#pragma once
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

template <typename K, typename V> class HashTableChaining {
  private:
    struct Node {
        K key;
        V val;
        Node *next;
        Node(const K &key, const V &val) : key(key), val(val), next(nullptr) {}
    };
    vector<Node *> table;
    size_t count;
    size_t cap;
    float loadFactor;

    void rehash(size_t count) {
        // do not forget casting float, or the LF will be 0
        float currentLF = (float)count / table.size();
        size_t newSize = 0;
        if (currentLF >= loadFactor) {
            newSize = table.size() * 2;
        }
        // to reduce table size, take the quarted of LF as a measure due to
        // thrashing problem if we take same LF to update table size, there will
        // be so much O(N) processes in consecutive insert and remove
        else if (currentLF <= loadFactor / 4.0f && table.size() / 2 >= cap) {
            newSize = table.size() / 2;
        } else {
            return;
        }
        vector<Node *> newTable(newSize, nullptr);
        for (size_t i = 0; i < table.size(); i++) {
            Node *current = table.at(i);
            while (current != nullptr) {
                Node *next = current->next;
                size_t newIndex = hash(current->key, newSize);
                current->next = newTable.at(newIndex);
                newTable.at(newIndex) = current;
                current = next;
            }
        }
        // to copy newTable to table use std::move, it prevent O(N) copying
        // process, reduce it to O(1)
        table = move(newTable);
    }

    size_t hash(const K &key, size_t size) const {
        if constexpr (is_integral_v<K>) {
            // use is_signed_v, otherwise the compiler throw an error says
            // "unsigned numbers cannot be negative"
            if constexpr (is_signed_v<K>) {
                if (key < 0) {
                    throw invalid_argument(
                        "Key value must be positive integer.");
                }
            }
            return (size_t)key % size;
        } else if constexpr (is_same_v<K, string>) {
            size_t hashVal = 0;
            for (char c : key) {
                hashVal += (size_t)c;
            }
            return hashVal % size;
        } else {
            throw invalid_argument(
                "The key value must be an integer or a string.");
        }
    }

    size_t hash(const K &key) const { return hash(key, table.size()); }

  public:
    HashTableChaining(size_t cap = 10, float loadFactor = 0.75f)
        : cap(cap), table(cap, nullptr), count(0), loadFactor(loadFactor) {}

    ~HashTableChaining() {
        for (size_t i = 0; i < table.size(); i++) {
            Node *current = table.at(i);
            while (current != nullptr) {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
    }

    void insert(const K &key, const V &val) {
        try {
            size_t index = hash(key);
            Node *current = table.at(index);
            while (current != nullptr) {
                if (current->key == key) {
                    current->val = val;
                    return;
                }
                current = current->next;
            }
            Node *node = new Node(key, val);
            node->next = table.at(index);
            table.at(index) = node;
            rehash(++count);
        } catch (const exception &e) {
            cerr << e.what() << endl;
        }
    }

    void remove(const K &key) {
        try {
            size_t index = hash(key);
            Node *current = table.at(index);
            Node *prev = nullptr;
            while (current != nullptr) {
                if (current->key == key) {
                    if (prev == nullptr) {
                        table.at(index) = current->next;
                    } else {
                        prev->next = current->next;
                    }
                    delete current;
                    rehash(--count);
                    return;
                }
                prev = current;
                current = current->next;
            }
            cout << "Key is not found" << endl;
        } catch (const exception &e) {
            cerr << e.what() << endl;
        }
    }

    void search(const K &key) {
        try {
            size_t index = hash(key);
            Node *current = table.at(index);
            while (current != nullptr) {
                if (current->key == key) {
                    cout << current->key << " : " << current->val << endl;
                    return;
                }
                current = current->next;
            }
            cout << "Key is not found" << endl;
        } catch (const exception &e) {
            cerr << e.what() << endl;
        }
    }

    void print() {
        cout << "------------------------" << endl;
        for (size_t i = 0; i < table.size(); i++) {
            cout << "[" << i << "]";
            Node *current = table.at(i);
            while (current != nullptr) {
                cout << " -> (" << current->key << " : " << current->val << ")";
                current = current->next;
            }
            cout << endl;
        }
        cout << "------------------------" << endl;
    }
};

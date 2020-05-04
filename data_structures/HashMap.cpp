#include <iostream>
#include <string>

const int TABLE_SIZE = 100;

template <typename K, typename V>
class HashNode {
    private:
        K key;
        V value;
        HashNode* next;
    public:
        HashNode(const K k, const V v) : key(k), value(v), next(NULL) {

        }
        K getKey() const {
            return this->key;
        }
        
        V getValue() const {
            return this->value;
        }
        void setValue(V v) {
            this->value = v;
        }

        HashNode* getNext() const {
            return this->next;
        }
        void setNext(HashNode* n) {
            this->next = n;
        }
};

template <typename K, typename V>
class HashMap {
    private:
        HashNode<K, V>** table;
        unsigned getHash(const std::string &key) {
            unsigned hash_value = 0;
            for (size_t i = 0; i < key.size(); ++i) {
                hash_value = hash_value + (key[i] - 48);
            }
            while (hash_value > TABLE_SIZE) {
                hash_value %= TABLE_SIZE;
            }
            return hash_value;
        }
        unsigned getHash(const int &key) {
            unsigned hash_value = key;
            while (hash_value > TABLE_SIZE) {
                hash_value %= TABLE_SIZE;
            }
            return hash_value;
        }
        unsigned hashFunc(K const& key) {
            return getHash(key);
        }
    public:
        HashMap() {
            std::cout << "Constructor" << std::endl;
            table = new HashNode<K, V>* [TABLE_SIZE];
        }

        void put(K key, V value) {
            unsigned hashKey = hashFunc(key);
            std::cout << "put key: " << key << ", hash: " << hashKey << std::endl;

            HashNode<K, V>* prev = NULL;
            HashNode<K, V>* entry = this->table[hashKey];

            while (entry != NULL && entry->getKey() != key) {
                prev = entry;
                entry = entry->getNext();
            }

            if (entry == NULL) {
                entry = new HashNode<K, V>(key, value);
                if (prev == NULL) {
                    this->table[hashKey] = entry;
                } else {
                    prev->setNext(entry);
                }
            } else {
                entry->setValue(value);
            }
        }

        V get(const K &key) {
            unsigned hashKey = hashFunc(key);
            std::cout << "get key: " << key << ", hash: " << hashKey << std::endl;

            HashNode<K, V>* entry = this->table[hashKey];
            while (entry != NULL) {
                if (entry->getKey() == key) {
                    return entry->getValue();
                }
                entry = entry->getNext();
            }
            return "ERROR!!! Key not found";
        }

        void remove(const K &key) {
            unsigned hashKey = hashFunc(key);
            std::cout << "remove key: " << key << ", hash: " << hashKey << std::endl;

            HashNode<K, V>* prev = NULL;
            HashNode<K, V>* entry = this->table[hashKey];
            while (entry != NULL && entry->getKey() != key) {
                prev = entry;
                entry = entry->getNext();
            }

            if (entry == NULL) {
                // Key not found
                return;
            } else {
                if (prev == NULL) {
                    table[hashKey] = entry->getNext();
                } else {
                    prev->setNext(entry->getNext());
                }
                delete entry;
            }
        }

        ~HashMap() {
            std::cout << "Destructor" << std::endl;
            for (size_t i = 0; i < TABLE_SIZE; ++i) {
                HashNode<K, V>* entry = this->table[i];
                while (entry != NULL) {
                    HashNode<K, V>* prev = entry;
                    entry = entry->getNext();
                    delete prev;
                }
                this->table[i] = NULL;
            }
            delete [] this->table;
        }
};

int main() {
    HashMap<std::string, std::string> mHashMap;
    mHashMap.put("Smith", "123456");
    mHashMap.put("John", "456789");
    std::cout << mHashMap.get("Smith") << std::endl;
    mHashMap.remove("Smith");
    std::cout << mHashMap.get("John") << std::endl;
    std::cout << mHashMap.get("Smith") << std::endl;

    std::cout << std::endl;

    HashMap<int, std::string> mHashMapInt;
    mHashMapInt.put(4, "123456");
    mHashMapInt.put(8, "456789");
    std::cout << mHashMapInt.get(8) << std::endl;

    return 0;
}
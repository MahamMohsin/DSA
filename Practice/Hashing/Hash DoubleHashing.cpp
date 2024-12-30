#include <iostream>
using namespace std;

// HashTableEntry class: This class represents an entry in the hash table.
// Each entry stores a key, value, and a deleted flag to indicate if the entry has been removed.
class HashTableEntry {
public:
    int key;       // Unique key for the entry
    int value;     // Corresponding value for the entry
    bool deleted;  // Deleted flag indicating whether the entry is deleted or not

    // Constructor: Creates a new entry with the given key and value
    HashTableEntry(int k, int v) : key(k), value(v), deleted(false) {}
};

// HashMapTable class: This class implements a hash table using double hashing for collision resolution.
class HashMapTable {
private:
    static const int TABLE_SIZE = 11;   // Fixed size of the table (a prime number for better hashing)
    HashTableEntry** table;            // Pointer array to store the table entries

    // HashFunc1: Primary hash function that computes key mod TABLE_SIZE
    int HashFunc1(int k) {
        return k % TABLE_SIZE;
    }

    // HashFunc2: Secondary hash function used for double hashing
    // Uses a different modulus (a prime number 7) for better collision resolution
    int HashFunc2(int k) {
        return 7 - (k % 7);
    }

public:
    // Constructor: Initializes the hash table with all slots set to null
    HashMapTable() {
        table = new HashTableEntry*[TABLE_SIZE]();
    }

    // DoubleHashFunc: Combines both hash functions to compute a unique index based on the key and attempt (i)
    int DoubleHashFunc(int k, int i) {
        return (HashFunc1(k) + i * HashFunc2(k)) % TABLE_SIZE;
    }

    // Insert function: Inserts a new key-value pair into the table
    void Insert(int k, int v) {
        int i = 0;  // Attempt counter (used for double hashing)
        int hash = HashFunc1(k);  // Result of the primary hash function

        // Apply double hashing until a free or deleted slot is found
        while (table[hash] != nullptr && !table[hash]->deleted) {
            i++;  // Increment attempt counter
            hash = DoubleHashFunc(k, i);  // Compute new index using double hashing
        }

        // Create a new entry and place it at the calculated position
        table[hash] = new HashTableEntry(k, v);
    }

    // SearchKey function: Searches for a given key in the table and returns its value
    int SearchKey(int k) {
        int i = 0;  // Attempt counter
        int hash = HashFunc1(k);  // Result of the primary hash function

        // Search until a null slot is reached
        while (table[hash] != nullptr) {
            // If key matches and the entry is not deleted, return its value
            if (!table[hash]->deleted && table[hash]->key == k) {
                return table[hash]->value;
            }
            i++;  // Increment attempt counter
            hash = DoubleHashFunc(k, i);  // Compute new index using double hashing
        }

        return -1;  // Return -1 if the key is not found
    }

    // Remove function: Removes a given key from the table by setting the deleted flag to true
    void Remove(int k) {
        int i = 0;  // Attempt counter
        int hash = HashFunc1(k);  // Result of the primary hash function

        // Search for the key in the table
        while (table[hash] != nullptr) {
            // If key matches and the entry is not deleted, mark it as deleted
            if (!table[hash]->deleted && table[hash]->key == k) {
                table[hash]->deleted = true;  // Mark the entry as deleted
                return;
            }
            i++;  // Increment attempt counter
            hash = DoubleHashFunc(k, i);  // Compute new index using double hashing
        }
    }

    // PrintTable function: Prints the contents of the table (occupied slots and empty slots)
    void PrintTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            // If the entry exists and is not deleted, print its data
            if (table[i] != nullptr && !table[i]->deleted) {
                cout << "Index " << i << ": Key=" << table[i]->key << ", Value=" << table[i]->value << endl;
            } else {
                // Print "Empty" for empty slots or deleted entries
                cout << "Index " << i << ": Empty" << endl;
            }
        }
    }

    // Destructor: Frees all dynamically allocated memory for the table
    ~HashMapTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i] != nullptr) {
                delete table[i];  // Delete each entry
            }
        }
        delete[] table;  // Free the array of pointers
    }
};

// Main function: Demonstrates the usage of the hash table
int main() {
    HashMapTable hashTable;

    // Insertions: Insert some keys and values into the table
    hashTable.Insert(20, 10);
    hashTable.Insert(34, 20);
    hashTable.Insert(45, 30);
    hashTable.Insert(70, 40);
    hashTable.Insert(56, 50);

    // Print the contents of the table
    cout << "Hash Table After Insertions:" << endl;
    hashTable.PrintTable();

    // Searching: Search for a specific key (2) in the table
    int value = hashTable.SearchKey(2);
    if (value != -1) {
        cout << "Value for key 2: " << value << endl;
    } else {
        cout << "Key 2 not found." << endl;
    }

    // Removing: Remove key 2 from the table
    hashTable.Remove(2);

    // Print the contents of the table after the removal operation
    cout << "Hash Table After Removal:" << endl;
    hashTable.PrintTable();

    return 0;  // Program ends successfully
}

#include <iostream>
using namespace std;

class hashEntry {
public:
    int key;       // Unique key
    int freq;      // Frequency of the key
    bool deleted;  // Deleted flag

    hashEntry(int k, int f) : key(k), freq(f), deleted(false) {}
};

class hashtable {
public:
    int size;               // Current table size
    hashEntry** table;      // Pointer array for the hash table
    int numofElements;      // Number of active elements

    hashtable(int initialSize = 11) : size(initialSize) {
        table = new hashEntry*[size]();
        numofElements = 0;
    }

    // Calculate Load Factor
    double lf() {
        return static_cast<double>(numofElements) / size;
    }

    // Primary hash function
    int h1(int k) {
        return k % size;
    }

    // Secondary hash function for double hashing
    int h2(int k) {
        return 7 - (k % 7);
    }

    // Double hashing
    int doublehash(int i, int k) {
        return (h1(k) + i * h2(k)) % size;
    }

    // Resize the hash table
    void resize(int newSize) {
        hashEntry** oldTable = table;
        int oldSize = size;

        size = newSize;  // Update size
        table = new hashEntry*[size]();
        numofElements = 0;

        for (int i = 0; i < oldSize; i++) {
            if (oldTable[i] != nullptr && !oldTable[i]->deleted) {
                insert(oldTable[i]->key, oldTable[i]->freq);
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }

    // Insert a key-value pair
    void insert(int k, int f) {
        // Resize if load factor exceeds 0.7
        if (lf() > 0.7) {
            resize(size * 2);
        }

        int i = 0;
        int hash = h1(k);

        while (table[hash] != nullptr && !table[hash]->deleted) {
            if (table[hash]->key == k) {
                table[hash]->freq += f;  // Increase frequency if key exists
                return;
            }
            i++;
            hash = doublehash(i, k);
        }

        table[hash] = new hashEntry(k, f);
        numofElements++;
    }

    // Remove a key
    void remove(int k) {
        int i = 0;
        int hash = h1(k);

        while (table[hash] != nullptr) {
            if (!table[hash]->deleted && table[hash]->key == k) {
                table[hash]->deleted = true;
                numofElements--;
                return;
            }
            i++;
            hash = doublehash(i, k);
        }
    }

    // Search for a key
    int search(int k) {
        int i = 0;
        int hash = h1(k);

        while (table[hash] != nullptr) {
            if (!table[hash]->deleted && table[hash]->key == k) {
                return table[hash]->freq;
            }
            i++;
            hash = doublehash(i, k);
        }
        return -1;  // Key not found
    }

    // Collect all key-frequency pairs in an array
    int collect(int arr[][2]) {
        int idx = 0;
        for (int i = 0; i < size; i++) {
            if (table[i] != nullptr && !table[i]->deleted) {
                arr[idx][0] = table[i]->key;
                arr[idx][1] = table[i]->freq;
                idx++;
            }
        }
        return idx;  // Return the count of collected elements
    }

    // Destructor
    ~hashtable() {
        for (int i = 0; i < size; i++) {
            if (table[i] != nullptr) {
                delete table[i];
            }
        }
        delete[] table;
    }
};

// Merge two sorted subarrays based on frequency, then key
void merge(int arr[][2], int low, int mid, int high) {
    int len1 = mid - low + 1;
    int len2 = high - mid;

    int first[100][2];
    int second[100][2];

    // Copy elements to temporary arrays
    for (int i = 0; i < len1; i++) {
        first[i][0] = arr[low + i][0];
        first[i][1] = arr[low + i][1];
    }
    for (int i = 0; i < len2; i++) {
        second[i][0] = arr[mid + 1 + i][0];
        second[i][1] = arr[mid + 1 + i][1];
    }

    int i = 0, j = 0, k = low;

    // Merge the two arrays based on frequency, then key
    while (i < len1 && j < len2) {
        if (first[i][1] < second[j][1] || (first[i][1] == second[j][1] && first[i][0] < second[j][0])) {
            arr[k][0] = first[i][0];
            arr[k][1] = first[i][1];
            i++;
        } else {
            arr[k][0] = second[j][0];
            arr[k][1] = second[j][1];
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i < len1) {
        arr[k][0] = first[i][0];
        arr[k][1] = first[i][1];
        i++;
        k++;
    }
    while (j < len2) {
        arr[k][0] = second[j][0];
        arr[k][1] = second[j][1];
        j++;
        k++;
    }
}

// Merge sort for 2D array
void mergesort(int arr[][2], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// Driver code
int main() {
    hashtable ht;
    int marks[] = {85, 90, 75, 85, 60, 90, 85, 75, 95, 100};
    int n = sizeof(marks) / sizeof(marks[0]);

    // Insert marks into hash table
    for (int i = 0; i < n; i++) {
        ht.insert(marks[i], 1);
    }

    // Collect key-frequency pairs
    int freqArr[100][2];
    int count = ht.collect(freqArr);

    // Sort the key-frequency pairs by frequency, then key
    mergesort(freqArr, 0, count - 1);

    // Print the sorted frequencies
    cout << "Sorted Key-Frequency Pairs:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "Key: " << freqArr[i][0] << ", Frequency: " << freqArr[i][1] << endl;
    }

    return 0;
}

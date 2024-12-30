#include <iostream>
using namespace std;

class Heap {
private:
    int* arr;
    int size;
    int capacity;

    // Heapify function to maintain the heap property
    void heapify(int n, int i) {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right <= n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(n, largest);
        }
    }

    // Resizes the array if capacity is reached
    void resize() {
        int* newArr = new int[capacity * 2];
        for (int i = 1; i <= size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity *= 2;
    }

public:
    // Constructor to initialize the heap with a given array and size
    Heap(int cap) : size(0), capacity(cap) {
        arr = new int[capacity + 1];
        arr[0] = 0; // 1-based indexing
    }

    // Insertion function to add an element to the heap by value
    void insertValue(int value) {
        if (size == capacity) {
            resize(); // Resize array if at capacity
        }
        size++;
        arr[size] = value;

        int i = size;
        while (i > 1 && arr[i] > arr[i / 2]) {
            swap(arr[i], arr[i / 2]);
            i = i / 2;
        }
    }

    // Deletion function to remove the root element
    int deletion() {
        if (size == 0) return -1; // Check for underflow

        int x = arr[1];
        arr[1] = arr[size];
        size--;

        int i = 1;
        int j = 2 * i;

        while (j <= size) {
            if (j < size && arr[j + 1] > arr[j]) {
                j = j + 1;
            }
            if (arr[i] < arr[j]) {
                swap(arr[i], arr[j]);
                i = j;
                j = 2 * j;
            } else {
                break;
            }
        }
        return x;
    }

    // Heapsort function to sort the array
    void heapsort() {
        for (int i = size / 2; i >= 1; i--) {
            heapify(size, i);
        }

        for (int i = size; i >= 2; i--) {
            swap(arr[1], arr[i]);
            heapify(i - 1, 1);
        }
    }

    // Display the heap array
    void display() const {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Heap() {
        delete[] arr;
    }
};

int main() {
    Heap heap(10);

    // Insert elements by value
    heap.insertValue(10);
    heap.insertValue(20);
    heap.insertValue(30);
    heap.insertValue(25);
    heap.insertValue(5);
    heap.insertValue(40);
    heap.insertValue(35);

    cout << "Heap after insertions: ";
    heap.display();

    // Sorting the heap using heapsort
    heap.heapsort();

    cout << "Array after heapsort: ";
    heap.display();

    return 0;
}

#include <iostream>
using namespace std;

class Heap {
private:
    int* arr;          // Dynamic array to store the heap
    int size;          // Current number of elements in the heap
    int capacity;      // Maximum capacity of the heap

    void heapifyUp(int index){//for insertion
        // Correct the heap upwards
        while (index > 0){
            int parent = (index - 1) / 2;
            if (arr[parent] >= arr[index]) break; // Max-heap property satisfied
            swap(arr[parent], arr[index]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {
        // Correct the heap downwards
        while (index < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && arr[left] > arr[largest]) largest = left;
            if (right < size && arr[right] > arr[largest]) largest = right;

            if (largest == index) break; // Max-heap property satisfied
            swap(arr[index], arr[largest]);
            heapifyDown(largest);
        }
    }

public:
    Heap(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    ~Heap() {
        delete[] arr;
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full. Cannot insert.\n";
            return;
        }
        arr[size] = value;
        heapifyUp(size);
        size++;
    }

    int deleteMax() {
        if (size == 0) {
            cout << "Heap is empty. Cannot delete.\n";
            return -1;
        }
        int maxValue = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
        return maxValue;
    }

    void heapSort() {
        int originalSize = size;
        while (size > 1) {
            swap(arr[0], arr[size - 1]);
            size--;
            heapifyDown(0);
        }
        size = originalSize; // Restore original size
    }

    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap heap(10);

    // Insert elements
    heap.insert(15);
    heap.insert(20);
    heap.insert(10);
    heap.insert(30);
    heap.insert(25);

    cout << "Heap after insertions: ";
    heap.printHeap();

    // Delete the maximum element
    cout << "Deleted max element: " << heap.deleteMax() << endl;

    cout << "Heap after deletion: ";
    heap.printHeap();

    // Perform heap sort
    heap.heapSort();
    cout << "Heap after sorting: ";
    heap.printHeap();

    return 0;
}

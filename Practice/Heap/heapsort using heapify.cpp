#include <iostream>
using namespace std;

class Heap {
private:
    int* arr;
    int size;

    // Heapify function to maintain the heap property when heap is built
    //or generally when deleting as starts from root
    void heapify(int n, int i) {
        int largest = i;          // Initialize largest as root
        int left = 2 * i;         // left child
        int right = 2 * i + 1;    // right child

        if (left <= n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right <= n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(n, largest); // Recursively heapify the affected subtree
        }
    }

public:
    // Constructor to initialize the heap with a given array and size
    Heap(int* array, int n) : arr(array), size(n) {}

    // Insertion function to add an element to the heap
    void insertion(int n) {
        int i = n;
        int temp = arr[i];

        while (i > 1 && temp > arr[i / 2]) {
            arr[i] = arr[i / 2];
            i = i / 2;
        }
        arr[i] = temp;
    }

    // Deletion function to remove the root element
    int deletion(int n) {
        int x = arr[1];
        arr[1] = arr[n];

        int i = 1;
        int j = 2 * i;

        while (j <= n - 1) {
            if (j < n - 1 && arr[j + 1] > arr[j]) {
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
        // Build heap using bottom-up approach
        for (int i = size / 2; i >= 1; i--) {
            heapify(size, i);
        }

        // Extract elements from heap one by one
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
};

int main() {
    int arr[] = {0, 10, 20, 30, 25, 5, 40, 35}; // Initialize array with zero at index 0 for 1-based index
    int n = sizeof(arr) / sizeof(arr[0]) - 1;

    Heap heap(arr, n);

    // Building heap using insertion
    for (int i = 2; i <= n; i++) {
        heap.insertion(i);
    }

    cout << "Heap after insertion: ";
    heap.display();

    // Sorting the heap using heapsort
    heap.heapsort();

    cout << "Array after heapsort: ";
    heap.display();

    return 0;
}

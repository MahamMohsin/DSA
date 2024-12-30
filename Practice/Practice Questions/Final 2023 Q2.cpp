#include <iostream>
using namespace std;

// Merging two subarrays of arr[] and counting inversions
int merge(int arr[], int low, int mid, int high) {
    int len1 = mid - low + 1;
    int len2 = high - mid;
    
    // Temporary arrays to hold the subarrays
    int* first = new int[len1];
    int* sec = new int[len2];
    
    // Copying data to temporary arrays
    for (int i = 0; i < len1; i++) {
        first[i] = arr[low + i];
    }
    for (int i = 0; i < len2; i++) {
        sec[i] = arr[mid + 1 + i];
    }
    
    int i = 0, j = 0, k = low;
    int invCount = 0;
    
    // Merging the two subarrays while counting inversions
    while (i < len1 && j < len2) {
        if (first[i] <= sec[j]) {
            arr[k++] = first[i++];
        } else {
            arr[k++] = sec[j++];
            invCount += (len1 - i);  // Count inversions
        }
    }
    
    // Copying the remaining elements from the first array, if any
    while (i < len1) {
        arr[k++] = first[i++];
    }
    
    // Copying the remaining elements from the second array, if any
    while (j < len2) {
        arr[k++] = sec[j++];
    }
    
    // Return the number of inversions found in this merge
    delete[] first;
    delete[] sec;
    return invCount;
}

// Merge Sort function to sort the array and count inversions
int mergesort(int arr[], int low, int high) {
    int invCount = 0;
    if (low < high) {
        int mid = (low + high) / 2;
        
        // Count inversions in the left half
        invCount += mergesort(arr, low, mid);
        
        // Count inversions in the right half
        invCount += mergesort(arr, mid + 1, high);
        
        // Count inversions while merging the two halves
        invCount += merge(arr, low, mid, high);
    }
    return invCount;
}

int main() {
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;

    int arr[N];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Count inversions
    int inversionCount = mergesort(arr, 0, N - 1);
    cout << "Number of inversions in the array: " << inversionCount << endl;

    return 0;
}

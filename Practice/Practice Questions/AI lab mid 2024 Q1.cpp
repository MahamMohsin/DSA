#include <iostream>
using namespace std;

class studentrecords {
public:
    int id;
    string name;
    float gpa;
    int ecas;
    int intscore;

    studentrecords() {}

    studentrecords(int id, string name, float gpa, int ecas, int intscore) {
        this->id = id;
        this->name = name;
        this->gpa = gpa;
        this->ecas = ecas;
        this->intscore = intscore;
    }

    // Selection sort for ids
    void sorting(studentrecords stuArr[], int n) {
        int min;
        for (int i = 0; i < n - 1; i++) {
            min = i;
            for (int j = i + 1; j < n; j++) {
                if (stuArr[j].id < stuArr[min].id) {
                    min = j;
                }
            }
            if (min != i) {
                // Not only the ids need to be swapped but the entire record
                studentrecords temp = stuArr[i];
                stuArr[i] = stuArr[min];
                stuArr[min] = temp;
            }
        }
    }

    int binarysearch(studentrecords stuArr[], int searchedID, int n) {
        int low = 0;
        int high = n - 1;
        int mid;

        sorting(stuArr, n); // Making sure array is sorted before binary search

        while (low <= high) {
            mid = (low + high) / 2;

            if (stuArr[mid].id == searchedID) {
                return mid;
            } else if (stuArr[mid].id > searchedID) {
                high = mid - 1; // Narrowing the search range
            } else {
                low = mid + 1; // Narrowing the search range
            }
        }
        return -1; // If not found
    }

    // Determining top students with high GPA, ECAS, and interview score
    void insertionsort(studentrecords stuArr[], int n) {
        for (int i = 1; i < n; i++) {
            studentrecords temp = stuArr[i];
            int j = i - 1;

            // Updated condition for sorting
            while (j >= 0 && (stuArr[j].gpa < temp.gpa || 
                (stuArr[j].gpa == temp.gpa && stuArr[j].ecas < temp.ecas) ||
                (stuArr[j].gpa == temp.gpa && stuArr[j].ecas == temp.ecas && stuArr[j].intscore < temp.intscore))) {
                stuArr[j + 1] = stuArr[j];
                j--;
            }
            stuArr[j + 1] = temp; // Corrected the position where temp is placed
        }
    }

    void display(studentrecords stuArr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << stuArr[i].name << " (" << stuArr[i].id << ") - GPA " 
                 << stuArr[i].gpa << ", ECAS: " << stuArr[i].ecas 
                 << ", Interview Score: " << stuArr[i].intscore << endl;
        }
        cout << endl;
    }
};

int main() {
    studentrecords stuArr[] = {
        {1001, "Alice", 3.9, 80, 85},
        {1002, "Bob", 3.7, 90, 88},
        {1003, "Charlie", 3.9, 85, 80},
        {1004, "David", 3.8, 88, 82},
        {1005, "Eva", 3.9, 80, 90}
    };

    int n = sizeof(stuArr) / sizeof(stuArr[0]);
    studentrecords s; // For calling functions

    cout << "Displaying Initial Record" << endl;
    s.display(stuArr, n);

    cout << "\nTop Students After Sorting" << endl;
    s.insertionsort(stuArr, n);
    s.display(stuArr, n);

    int to_search = 1001;
    int foundIndex = s.binarysearch(stuArr, to_search, n);

    if (foundIndex == -1) {
        cout << "Student Not found!" << endl;
    } else {
        cout << "Student with ID " << to_search << " found at: " << foundIndex << endl;
        s.display(&stuArr[foundIndex], 1); // 1 sent to display only 1 element whose ref sent
    }

    return 0;
}

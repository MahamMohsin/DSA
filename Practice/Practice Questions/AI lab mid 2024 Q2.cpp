#include <iostream>
using namespace std;

// Creating a doubly queue using linked list for hospital management
// In which patient enters and is served based on their critical condition level
// If 2 have the same critical conditions, serve the one who came first
// Each node has patient ID, age, and criticality score

class node {
public:
    int id;
    int age;
    int criticalscore;
    node* next;
    node* prev;

    node(int i, int a, int cs) {
        id = i;
        age = a;
        criticalscore = cs;
        this->next = NULL;
        this->prev = NULL;
    }
};

class doublylinkedlist {
public:
    node* front = NULL; // for deletion in queue
    node* rear = NULL;  // for insertion in queue from the end

    bool isempty() {
        return front == NULL;
    }

    // Insert from tail
    void enqueue(int i, int a, int cs) {
        node* n = new node(i, a, cs);

        if (isempty()) {
            front = rear = n;
        } else {
            rear->next = n;
            n->prev = rear;
            rear = n; // setting n as the new tail
        }
    }

    // Deletion from top based on highest criticality
    void dequeue() {
        if (isempty()) {
            cout << "No Patient to serve!" << endl;
            return; // Add return to stop further execution
        }

        node* temp = front;                      // Iterator
        node* high_criticality_patient = front;  // To find the patient with the highest criticality score

        while (temp != NULL) {
            if (temp->criticalscore > high_criticality_patient->criticalscore) {
                high_criticality_patient = temp;
            }
            temp = temp->next;
        }

        // Now that we have the patient with the highest criticality score
        cout << "Dequeueing Patient " << high_criticality_patient->id << endl;

        // If the patient to dequeue is at the head
        if (high_criticality_patient == front) {
            front = front->next;
            if (front != NULL) {
                front->prev = NULL;
            } else {
                rear = NULL; // If we dequeued the last element, update rear to NULL as well
            }
        }
        // If the patient is at the rear
        else if (high_criticality_patient == rear) {
            rear = rear->prev;
            rear->next = NULL;
        }
        // If the patient is in the middle
        else {
            high_criticality_patient->prev->next = high_criticality_patient->next;
            high_criticality_patient->next->prev = high_criticality_patient->prev;
        }

        delete high_criticality_patient;
    }

    // Display all patients
    void display() {
        if (isempty()) {
            cout << "No Patients in the queue." << endl;
            return;
        }

        node* temp = front;

        while (temp != NULL) {
            cout << "Patient ID: " << temp->id << endl;
            cout << "Patient Age: " << temp->age << endl;
            cout << "Criticality: " << temp->criticalscore << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    doublylinkedlist dll;

    dll.enqueue(1, 78, 50);
    dll.enqueue(2, 60, 43);
    dll.enqueue(3, 50, 70);
    dll.enqueue(4, 32, 60);

    dll.display();
    cout << endl;

    dll.dequeue(); // Let patient 3 out first
    dll.display();

    dll.dequeue(); // Then 4
    dll.display();

    dll.dequeue(); // Then 1
    dll.display();

    dll.dequeue(); // Then 2 (last one)
    dll.display();
}

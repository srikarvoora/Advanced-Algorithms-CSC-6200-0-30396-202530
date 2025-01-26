#include <iostream>
using namespace std;

// Node structure for LinkedList
struct Node {
    int row;
    int col;
    int value;
    Node* next;
};

// LinkedList class for Sparse Matrix
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert a new node at the end of the LinkedList
    void insert(int row, int col, int value) {
        Node* newNode = new Node;
        newNode->row = row;
        newNode->col = col;
        newNode->value = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Display the LinkedList
    void display() {
        Node* temp = head;
        cout << "Sparse Matrix Representation (Linked List):\n";
        while (temp != nullptr) {
            cout << "Row: " << temp->row << ", Column: " << temp->col << ", Value: " << temp->value << endl;
            temp = temp->next;
        }
    }

    // Destructor to release memory
    ~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
        head = nullptr;
    }
};

int main() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int matrix[rows][cols];

    cout << "Enter the elements of the matrix (including zeros):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    LinkedList list;

    // Traverse the matrix and add non-zero elements to the linked list
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                list.insert(i, j, matrix[i][j]);
            }
        }
    }

    // Display the linked list representation of the sparse matrix
    list.display();

    return 0;
}

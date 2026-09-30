// COMSC 210 | Lab 17 | Yeji Kim

#include <iostream>

using namespace std;

const int SIZE = 7;

struct Node {
    float value;
    Node * next;
};

// adding function prototypes
void addNodeFront(Node * & );
void addNodeTail(Node * & );
void deleteNode(Node * & );
void insertNode(Node * & );
void deleteList(Node * & );
void output(Node * );

int main() {
    Node * head = nullptr;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        addNodeFront(head);
    }

    int choice = 0;

    // menu loop for user to choose from
    while (choice != 7) {
        cout << "Linked List Menu:" << endl;
        cout << "1. Add node to front" << endl;
        cout << "2. Add node to end" << endl;
        cout << "3: Delete a node" << endl;
        cout << "4: Insert a node" << endl;
        cout << "5. Delete entire list" << endl;
        cout << "6: Print list" << endl;
        cout << "7: Exit" << endl;
        cout << "Choice --> ";
        cin >> choice;

        if (choice == 1) {
            addNodeFront(head);
        } else if (choice == 2) {
            addNodeTail(head);
        } else if (choice == 3) {
            deleteNode(head);
        } else if (choice == 4) {
            insertNode(head);
        } else if (choice == 5) {
            deleteList(head);
        } else if (choice == 6) {
            output(head);
        } else if (choice == 7) {
            cout << "Exiting program." << endl;
        } else {
            cout << "Invalid choice. Please enter 1-7." << endl;
        }
    }

    // delete the entire list before exiting
    deleteList(head);

    return 0;
}

// add node to front
// pass head by reference to modify the original pointer and allow the new node to become the new head of the list
void addNodeFront(Node * & head) {
    int tmp_val = rand() % 100; // random number between 0-99
    Node * newVal = new Node;

    newVal -> value = tmp_val;
    newVal -> next = head;

    head = newVal;
}

// add node to tail
// pass head by reference to modify the original pointer if the list is empty and allow the new node to be added to the end of the list
void addNodeTail(Node * & head) {
    int tmp_val = rand() % 100; // random number between 0-99
    Node * newVal = new Node;

    newVal -> value = tmp_val;
    newVal -> next = nullptr;

    if (!head) {
        head = newVal;
        return;
    }

    Node * current = head;

    while (current -> next) {
        current = current -> next;
    }

    current -> next = newVal;
}

// delete a node
// pass head by reference to modify the original pointer and allow the new head of the list to be updated if the first node is deleted
void deleteNode(Node * & head) {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "Which node to delete?" << endl;
    output(head);

    int entry;
    cout << "Enter node number to delete: ";
    cin >> entry;

    Node * current = head;
    Node * previous = nullptr;

    for (int i = 0; i < (entry - 1) && current; i++) {
        previous = current;
        current = current -> next;
    }

    if (!current) {
        cout << "Invalid node number." << endl;
        return;
    }

    if (previous == nullptr) {
        head = current -> next;
    } else {
        previous -> next = current -> next;
    }

    delete current;
    current = nullptr;
}

// insert a node
// pass head by reference to modify the original pointer and allow the new node to be inserted at the specified position in the list
void insertNode(Node * & head) {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "After which node to insert?" << endl;
    output(head);

    int entry;
    cout << "Enter node number to insert after: ";
    cin >> entry;

    Node * current = head;
    Node * previous = nullptr;

    for (int i = 0; i < entry && current; i++) {
        previous = current;
        current = current -> next;
    }

    if (!previous) {
        cout << "Invalid node number." << endl;
        return;
    }

    Node * newnode = new Node;
    newnode -> value = 10000;
    newnode -> next = current;

    previous -> next = newnode;
}

// delete entire list
// pass head by reference to modify the original pointer and allow the entire list to be deleted and head to be set to nullptr
void deleteList(Node * & head) {
    Node * current = head;

    while (current) {
        head = current -> next;
        delete current;
        current = head;
    }

    head = nullptr;
}

// output the list
void output(Node * head) {
    if (!head) {
        cout << "Empty list.\n";
        return;
    }

    int count = 1;
    Node * current = head;

    while (current) {
        cout << "[" << count++ << "] " << current -> value << endl;
        current = current -> next;
    }

    cout << endl;
}
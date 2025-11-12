#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtBeginning(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAfter(int val, int afterVal) {
    Node* temp = head;
    while (temp != NULL && temp->data != afterVal) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Node with value " << afterVal << " not found." << endl;
        return;
    }
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertBefore(int val, int beforeVal) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    if (head->data == beforeVal) {
        insertAtBeginning(val);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != beforeVal) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Node with value " << beforeVal << " not found." << endl;
        return;
    }
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void deleteSpecific(int val) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    if (head->data == val) {
        deleteFromBeginning();
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Node with value " << val << " not found." << endl;
        return;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

int search(int val) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == val) {
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return -1;
}

void display() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert before/after a node" << endl;
        cout << "4. Delete from beginning" << endl;
        cout << "5. Delete from end" << endl;
        cout << "6. Delete specific node" << endl;
        cout << "7. Search for a node" << endl;
        cout << "8. Display all nodes" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int val;
                cout << "Enter value to insert: ";
                cin >> val;
                insertAtBeginning(val);
                break;
            }
            case 2: {
                int val;
                cout << "Enter value to insert: ";
                cin >> val;
                insertAtEnd(val);
                break;
            }
            case 3: {
                int val, refVal;
                char pos;
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter reference value: ";
                cin >> refVal;
                cout << "Insert before (b) or after (a): ";
                cin >> pos;
                if (pos == 'b' || pos == 'B') {
                    insertBefore(val, refVal);
                } else if (pos == 'a' || pos == 'A') {
                    insertAfter(val, refVal);
                } else {
                    cout << "Invalid choice." << endl;
                }
                break;
            }
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6: {
                int val;
                cout << "Enter value to delete: ";
                cin >> val;
                deleteSpecific(val);
                break;
            }
            case 7: {
                int val;
                cout << "Enter value to search: ";
                cin >> val;
                int pos = search(val);
                if (pos != -1) {
                    cout << "Node found at position " << pos << endl;
                } else {
                    cout << "Node not found." << endl;
                }
                break;
            }
            case 8:
                display();
                break;
            case 9:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 9);
    return 0;
}

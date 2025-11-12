#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
int countOccurrences(Node* head, int key) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}
void deleteAllOccurrences(Node*& head, int key) {
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL) {
        if (temp->data == key) {
            if (prev == NULL) {
                head = temp->next;
                delete temp;
                temp = head;
            } else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << "->";
        }
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    Node* head = new Node{1, new Node{2, new Node{1, new Node{2, new Node{1, new Node{3, new Node{1, NULL}}}}}}};
    int key = 1;

    int count = countOccurrences(head, key);
    cout << "Count: " << count << " , Updated Linked List: ";
    deleteAllOccurrences(head, key);
    display(head);
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}

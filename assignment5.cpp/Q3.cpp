#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
int findMiddle(Node* head) {
    if (head == NULL) return -1;
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
int main() {
    Node* head = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, NULL}}}}};
    cout << findMiddle(head) << endl;
    return 0;
}

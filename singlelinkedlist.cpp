#include <iostream>
using namespace std;
class Node
{
public:
  int key;
  int data;
  Node *next; // pointer of same class
  Node()
  {
    key = 0;
    data = 0;
    next = NULL;
  }
  Node(int k, int d)
  { // parameterised constructor
    key = k;
    data = d;
  }
};
class SinglyLinkedList
{
public:
  Node *head; // a pointer which points to the head of a node
  SinglyLinkedList(Node *n)
  { // pass by adress  Node *n → means you pass the address of a Node when creating the list. The constructor then sets head = n; so the list knows where the first node is.
    head = n;
  }
  // 1.check if node exists using key value
  Node *nodeExists(int k)
  {
    Node *temp = NULL;  // A Node pointer named temp is created and initialized to NULL. This pointer will be used to store the address of the node if we find it.
    Node *ptr = head;   // Another Node pointer, ptr (short for "pointer"), is created to act as our iterator. It's initialized to point to the head of the linked list, which is the starting point.
    while (ptr != NULL) // jab tak list ka end nahi aa jata
    {
      if (ptr->key == k)
      {
        temp = ptr; // temp me us node ka address save kar lo
      }
      ptr = ptr->next; // next node pe move kar jao
    }
    return temp;
  }
  // 2. append a node to the list
  void appendNode(Node *n)
  {
    if (nodeExists(n->key) != NULL)
    {
      cout << "Node already exists with key value: " << n->key << ". Append another node with different key value" << endl;
    }
    else
    {
      if (head == NULL)
      { // agar list empty hai to seedha head ko n ke barabar krdo append hojaega at last
        head = n;
        cout << "node appended" << endl;
      }
      else
      {
        Node *ptr = head;         // ek pointer bnaege jo head ka adress store krega
        while (ptr->next != NULL) // last node tk transverse kro
        {                         // next pointer agli node ka adress store krta hai agar ptr ->next == NULL hai to matlab last node hai aage koi node nhi hai kyuki adress null hai
          ptr = ptr->next;
        } // Loop tab tak chalta hai jab tak ptr->next != NULL hai. Matlab loop rukte hi ptr->next == NULL ho jaata hai. Aur isi ka matlab hai ki ptr ab last node pe khada hai.
        ptr->next = n;
        cout << "node appended" << endl;
      }
    }
  }
  // 3. prepend node - attach a node at the start
  void prependNode(Node *n)
  {
    if (nodeExists(n->key) != NULL)
    {
      cout << "Node already exists with key value: " << n->key << ". Append another node with different key value" << endl;
    }
    else
    {
      n->next = head; // Link the new node to the old head
      head = n;       // Update head to be the new node
      cout << "node prepended" << endl;
    }
  }
  // 4.insert a node after a particular node in the list
  void insertNodeAfter(int k, Node *n)
  {
    Node *ptr = nodeExists(k);
    if (ptr == NULL)
    {
      cout << "no node exists with key value" << k << endl;
    }
    else
    {
      if (nodeExists(n->key) != NULL)
      {
        cout << "Node already exists with key value: " << n->key << ". Append another node with different key value" << endl;
      }
      else
      {
        n->next = ptr->next;
        ptr->next = n;
      }
    }
  }
  // delete node by unique key
  void deleteNodeByKey(int k)
  {
    if (head == NULL)
    {
      cout << "singly linked list always empty. cant delete" << endl;
    }
    else if (head != NULL)
    {
      if (head->key == k)
      {
        head = head->next;
        cout << "Node unlinked with keys value";
      }
    }
  }
};
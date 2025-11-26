#include <iostream>
using namespace std;

class Node
{
public:
  int key;
  int data;
  Node *next;

  Node()
  {
    key = 0;
    data = 0;
    next = NULL;
  }
  Node(int k, int d)
  {
    key = k;
    data = d;
    next = NULL; // Initially NULL, will be linked up by the list class
  }
};

class CircularLinkedList
{
public:
  Node *head;

  // A default constructor is good practice
  CircularLinkedList()
  {
    head = NULL;
  }

  // 1. Check if a node exists using a key value (MODIFIED for circular traversal)
  Node *nodeExists(int k)
  {
    Node *temp = NULL;
    // Cant check for NULL head inside do-while, so check before
    if (head == NULL)
    {
      return temp;
    }

    Node *ptr = head;
    do
    {
      if (ptr->key == k)
      {
        temp = ptr;
        break; // Found it, no need to loop further
      }
      ptr = ptr->next;
    } while (ptr != head); // CHANGE: Loop until we are back at the head

    return temp;
  }

  // 2. Append a node to the list (MODIFIED for circular logic)
  void appendNode(Node *n)
  {
    if (nodeExists(n->key) != NULL)
    {
      cout << "Node already exists with key value: " << n->key << ". Append another node with a different key value." << endl;
    }
    else
    {
      if (head == NULL)
      {
        head = n;
        n->next = head; // CHANGE: Point back to itself to make it circular
        cout << "Node appended to an empty list." << endl;
      }
      else
      {
        // CHANGE: Find the last node (the one pointing to the head)
        Node *ptr = head;
        while (ptr->next != head)
        {
          ptr = ptr->next;
        }
        // Now ptr is the last node
        ptr->next = n;  // 1. Old last node points to the new node
        n->next = head; // 2. New node points to the head
        cout << "Node appended." << endl;
      }
    }
  }

  // 3. Prepend node - attach a node at the start (MODIFIED for circular logic)
  void prependNode(Node *n)
  {
    if (nodeExists(n->key) != NULL)
    {
      cout << "Node already exists with key value: " << n->key << ". Append another node with a different key value." << endl;
    }
    else
    {
      if (head == NULL)
      {
        head = n;
        n->next = head; // Point back to itself
        cout << "Node prepended to an empty list." << endl;
        return;
      }

      // CHANGE: Find the last node to update its pointer
      Node *ptr = head;
      while (ptr->next != head)
      {
        ptr = ptr->next;
      }
      // Now ptr is the last node
      ptr->next = n;  // 1. Last node now points to the new head
      n->next = head; // 2. New node points to the old head
      head = n;       // 3. Update the head pointer
      cout << "Node prepended." << endl;
    }
  }

  // 4. Insert a node after a particular node (Logic is nearly the same, but benefits from the fixed nodeExists)
  void insertNodeAfter(int k, Node *n)
  {
    Node *ptr = nodeExists(k);
    if (ptr == NULL)
    {
      cout << "No node exists with key value " << k << endl;
    }
    else
    {
      if (nodeExists(n->key) != NULL)
      {
        cout << "Node already exists with key value: " << n->key << ". Append another node with different key value" << endl;
      }
      else
      {
        n->next = ptr->next; // New node points to what the previous node was pointing to
        ptr->next = n;       // Previous node now points to the new node
        cout << "Node inserted." << endl;
      }
    }
  }

  // 5. Display the list (NEW and ESSENTIAL for testing)
  void printList()
  {
    if (head == NULL)
    {
      cout << "List is empty." << endl;
      return;
    }

    cout << "Head -> ";
    Node *ptr = head;
    do
    {
      cout << "(" << ptr->key << ", " << ptr->data << ") -> ";
      ptr = ptr->next;
    } while (ptr != head); // Loop until we're back at the start

    cout << "(Back to Head " << head->key << ")" << endl;
  }
};

int main()
{
  CircularLinkedList cl;

  Node *n1 = new Node(1, 10);
  cl.appendNode(n1);

  Node *n2 = new Node(2, 20);
  cl.appendNode(n2);

  Node *n3 = new Node(3, 30);
  cl.appendNode(n3);

  cout << "\nList after appending 3 nodes: " << endl;
  cl.printList();

  Node *n0 = new Node(0, 5);
  cl.prependNode(n0);

  cout << "\nList after prepending node (0, 5): " << endl;
  cl.printList();

  Node *n4 = new Node(4, 25);
  cl.insertNodeAfter(2, n4);

  cout << "\nList after inserting (4, 25) after key 2: " << endl;
  cl.printList();

  return 0;
}
#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
}*top;
void init(){
	top=NULL;
}
void push(int value){
	Node* n1=new Node();
	n1->data=value;
	if(top==NULL){
		n1->next=NULL;
	}
	else{
		n1->next=top;
	}
	top=n1;
}
void pop(){
	Node *temp=top;
	cout<<temp->data<<endl;
	top=temp->next;
}
void display(){
	if(top==NULL){
		cout<<"stack is empty"<<endl;
	}
	else{
		Node* n1=new Node();
	    n1=top;
		while(n1->next!=NULL){
			cout<<n1->data<<endl;
			n1=n1->next;
		}
	
	}
}
int main()
{
    init();

    push(10);
    push(20);
    push(30);

    display();

    pop();
    display();

    pop();
    display();

    pop();
    display();

    pop(); // Underflow check

    return 0;
}
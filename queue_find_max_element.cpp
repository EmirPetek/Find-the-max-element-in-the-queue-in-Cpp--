#include <iostream>
using namespace std;
class Node{

	public:
	int data;
	Node* next;

	friend class Queue;
};
class Queue{
	Node* front = NULL;
	Node* tail = NULL;

public: void enqueue(int data){ // It works for pushing element to the queue
	Node* node = new Node();
	
	node -> data = data;
	node -> next = NULL;
	if(front == NULL){
		front = node;
		tail = node;	
	} 
	else{
		tail -> next = node;
		tail = node;	
	}		
}

public: void dequeue(){ // It works for popping the element from the queue. It pops the first element.
	Node* temp;
	temp = front;
	if(isEmpty() == true){
		cout<< "Queue is empty" << endl;		
	}
	else{
		front = front -> next;
		temp -> next = NULL;				
	}
}

public: int getFront(){ 
	int frontElement;
	frontElement = front -> data;
	return frontElement;
}

public: int getTail(){
	int tailElement;
	Node* temp = front;
	while(temp != NULL){
		if(temp -> next == NULL) tailElement = temp -> data;
		temp = temp -> next;
	}
	return tailElement;
}

public: bool isEmpty(){
	if(front == NULL && tail == NULL) {
		return true;	
	}
	else return false;
}

public: int size(){
	Node* temp;
	temp = front;
	int count = 0;
	while(temp != NULL){
		temp = temp -> next; 
		count++;	
	}
	return count;
}

public: void show(){
	Node* temp;
	temp = front;
	if(temp == front) cout<<"Front ";
	while(temp != NULL){
		cout<< temp->data << " ";
		temp = temp -> next;
	}
	if(temp == NULL) cout<<" Tail "<< endl;
}

};

int main(int argc, char** argv) {
	
	Queue q1,q2;
	
	q1.enqueue(42);
	q1.enqueue(32);
	q1.enqueue(65);
	q1.enqueue(15);
	q1.enqueue(72);
	q1.enqueue(47);
	q1.enqueue(94);
	q1.enqueue(10);
	q1.enqueue(89);
	q1.show();
	
	int size = q1.size();
	int max = 0;
	for(int i=0; i < size; i++){
		if(q1.getFront() >= max)  max = q1.getFront();
		q2.enqueue(q1.getFront());
		q1.dequeue();
		
	}	
	cout<<"Max Element of queue: " << max << endl;

	return 0;
	
	
	
	
	
	
	
}

#include <iostream>
#include <cstdlib>

using namespace std;

class Node{
private:
	int value;


public:
	Node *next;
	Node *prev;
	
	Node(){
		next = nullptr;
		prev = nullptr;
		value = 0;
	}
	
	~Node(){
		cout << "Deconstructing " << value << endl;
	}
	
	Node(int value){
		next = nullptr;
		prev = nullptr;
		this->value = value;
	}
	
	void link(Node *next){
		this->next = next;
		if(next!=nullptr){
			next->prev = this;
		}
	}
	
	Node* getNext(){
		return next;
	}
	
	Node* getPrev(){
		return prev;
	}
	
	int getVal(){
		return value;
	}
	
	void print(){
		cout << value << " ";
	}
};

/*
int main(){
	//Test pointer and regular
	Node *first = new Node(1);
	Node *second = new Node(2);
	Node *third = new Node(3);
	
	first->link(second);
	second->link(third);
	third->link(first);
	Node *current = first;
	for(int i=0; i<10; i++){
		current->print();
		current = current->next;
	}
}
*/

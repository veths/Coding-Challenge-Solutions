#include <iostream>
#include <cstdlib>
#include "node.cpp"

class LinkedList{
private:
	Node *head;
	Node *tail;
	
public:
	LinkedList(){
		head = nullptr;
		tail = nullptr;
	}
	
	void insert(int value){
		Node *node = new Node(value);
		if(head==nullptr){
			head = node;
			tail = node;
		}
		else{
			tail->link(node);
			tail = node;
		}
	}
	
	bool contains(int value){
		Node *current = head;
		while(current!=nullptr){
			if(current->getVal() == value) return true;
			else current = current->getNext();
		}
		return false;
	}
	
	void remove(int value){
		//If the front of Linked List
		if(head->getVal() == value){
			if(head->getNext() != nullptr){
				head = head->getNext();
			}
			//If only element in list
			else{
				head = nullptr;
				tail = nullptr;
			}
		}
		//If the back of the Linked List
		else if(tail->getVal() == value){
			tail = tail->getPrev();
			tail->link(nullptr);
		}
		//Otherwise in the middle of list
		else{
			Node *current = head;
			while(current!=nullptr){
				if(current->getVal() == value){
					Node *prev = current->getPrev();
					prev->link(current->getNext());
					break;
				}
				else{
					current = current->getNext();
				}
			}			
		}
	}
	
	void print(){
		Node *current = head;
		cout << "[";
		while(current!=nullptr){
			if(current->getNext()!=nullptr){
				cout << current->getVal() << ",";
			}
			else{
				cout << current->getVal();
			}
			current = current->getNext();
		}
		cout << "]" << endl;
	}
};
/*
int main(){
	LinkedList list;
	for(int i=1; i<20+1; i++){
		list.insert(i);
	}
	
	list.print();
	
	cout << "Done" << endl;
	
	return 0;
}
*/

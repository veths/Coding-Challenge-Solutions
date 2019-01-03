#include <iostream>
#include <cstdlib>
#include <random>

#include "list.cpp"

class HashTable{
private:
	LinkedList *data;
	int size;

public:
	HashTable(){
		data = new LinkedList[5];
		size = 5;
	}
	
	HashTable(int size){
		this->size = size;
		data = new LinkedList[size];
	}
	
	int hash(int value){
		return value % size;
	}
	
	void insert(int value){
		int index = hash(value);
		data[index].insert(value);
	}
	
	void print(){
		for(int i=0; i<size; i++){
			cout << "Index: " << i << " List: ";
			data[i].print();
		}
	}
};

int main(){
	srandom(time(NULL));
	
	HashTable table;
	
	for(int i=0; i<100; i++){
		int r = random()%100;
		table.insert(r);
	}
	table.print();
}

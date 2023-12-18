#include "linkedList.hpp"
#include <iostream>

namespace eda {

LinkedList::LinkedList(): head(nullptr) {

}

void LinkedList::insertFirst(int fila, int columna){
	Node* node = new Node(fila, columna);
	if (head == nullptr) {
		head = node;
	}
	else{
		node->setNext(head);
		head = node;
	}
}

void LinkedList::insertLast(int fila, int columna){
	Node* node = new Node(fila, columna);
	if (head == nullptr) {
		head = node;
	}
	else{
		Node* ptr = head;
		while(ptr->getNext() != nullptr){
			ptr = ptr->getNext();
		}
		ptr->setNext(node);
	}
}

void LinkedList::removeFirst(){
	Node* ptr = head;
	if (head != nullptr){
		head = head->getNext();
		delete ptr;
	}
}

void LinkedList::remove(int fila, int columna){
	Node* ptr = head;
	Node* ptr_prev = nullptr;
	while (ptr != nullptr){
		if (ptr->getFila() == fila && ptr->getColumna() == columna){
			//erase node
			if (ptr_prev == nullptr) {
				head = ptr->getNext();
				delete ptr;
				ptr = head;
			}
			else{
				ptr_prev->setNext(ptr->getNext());
				delete ptr;
				ptr = ptr_prev->getNext();
			}
		}
		else{
			ptr_prev = ptr;
			ptr = ptr->getNext();
		}
	}
}

void LinkedList::removeAll(){

	while (head != nullptr){
		removeFirst();
	}
}

Node* LinkedList::find(int fila, int columna){
	Node* ptr = head;
	while ((ptr != nullptr) && (ptr->getFila() != fila && ptr->getColumna() != columna)){
		ptr = ptr->getNext();
	}
	return ptr;
}

void LinkedList::print(){
	Node* ptr = head;
	while (ptr != nullptr) {
		ptr->print();
		std::cout << " -> ";
		ptr = ptr->getNext();
	}
	std::cout << std::endl;
}

LinkedList::~LinkedList() {
	removeAll();
}

} /* namespace eda */
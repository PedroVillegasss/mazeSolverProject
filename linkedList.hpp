#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include "node.hpp"

namespace eda {

class LinkedList {
public:
	Node* head;
	LinkedList();
	void insertLast(int fila, int columna);
	void insertFirst(int fila, int columna);
	void removeFirst();
	void remove(int fila, int columna);
	void removeAll();
	Node* find(int fila, int columna);
	void print();
	virtual ~LinkedList();
};

} /* namespace eda */

#endif /* LINKEDLIST_HPP_ */
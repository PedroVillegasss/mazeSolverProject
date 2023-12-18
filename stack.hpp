#ifndef STACK_HPP_
#define STACK_HPP_

#include "node.hpp"

namespace eda {

class Stack {
private:
	Node* head;
public:
	Stack();
	void push(int fila, int columna);
	void push(Node* node);
	void pop();
	Node* top();
	bool isEmpty();
	void clear();
	virtual ~Stack();
};

} /* namespace eda */

#endif /* STACK_HPP_ */
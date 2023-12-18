#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include "node.hpp"

namespace eda {

class Queue {
private:
	Node* head;
	Node* tail;
public:
	Queue();
	void push(int fila, int columna);
	void push(Node* node);
	void pop();
	Node* top();
	bool isEmpty();
	void clear();
	virtual ~Queue();
};

} /* namespace eda */

#endif /* QUEUE_HPP_ */
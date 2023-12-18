#ifndef NODE_HPP_
#define NODE_HPP_

namespace eda {

class Node {
private:
	int fila;
	int columna;
	Node* ptrNext;
public:
	Node();
	Node(int _fila, int _columna, Node* next = nullptr);
	void setFila(int _fila);
	void setColumna(int _columna);
	void setNext(Node* _next);
	int getFila();
	int getColumna();
	Node* getNext();
	void print();
	virtual ~Node();
};

} /* namespace eda */

#endif /* NODE_HPP_ */
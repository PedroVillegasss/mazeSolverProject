#include "node.hpp"
#include <iostream>

namespace eda {


Node::Node(): fila(-1), columna(-1), ptrNext(nullptr) {
}

Node::Node(int _fila, int _columna, Node* next): fila(_fila), columna(_columna), ptrNext(next) {

}

void Node::setFila(int _fila){
	fila = _fila;
}

void Node::setColumna(int _columna){
	columna = _columna;
}

void Node::setNext(Node* next){
	ptrNext = next;
}

int Node::getFila(){
	return fila;
}

int Node::getColumna(){
	return columna;
}

Node* Node::getNext(){
	return ptrNext;
}

void Node::print(){
	std::cout << "(" << fila << ":" << columna << ")";
}

Node::~Node() {

}

} /* namespace eda */
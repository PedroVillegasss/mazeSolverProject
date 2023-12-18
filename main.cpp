#include <iostream>
#include "maze.hpp"
#include "linkedList.hpp"

int main(int nargs, char** vargs){
	maze::Maze laberinto(5, 5);
	laberinto.print();
	
	std::cout << "+------------------------- IMPRIMIENDO SOLUCIONES --------------------------+" << std::endl;
	
	std::cout << "1) stackSolution con parametros: " << std::endl; 
	eda::LinkedList stackSolutionPar = laberinto.solve_pila(0, 0, 4, 4);
	laberinto.solutionPrinter(stackSolutionPar);
	
	std::cout << "+---------------------------------------------------------------------------+" << std::endl;
	std::cout << "2) stackSolution sin parametros: " << std::endl;
	eda::LinkedList stackSolution = laberinto.solve_cola();
	laberinto.solutionPrinter(stackSolution);

	std::cout << "+---------------------------------------------------------------------------+" << std::endl;
	std::cout << "3) queueSolution con parametros: " << std::endl;
	eda::LinkedList queueSolutionPar = laberinto.solve_cola(0, 0, 4, 4);
	laberinto.solutionPrinter(queueSolutionPar);

	std::cout << "+---------------------------------------------------------------------------+" << std::endl;
	std::cout << "4) queueSolution sin parametros: " << std::endl;
	eda::LinkedList queueSolution = laberinto.solve_cola();
	laberinto.solutionPrinter(queueSolution);


	return 0;
}
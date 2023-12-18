#include "maze.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>
#include <thread>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BLACK   "\033[30m"

using namespace eda;
using namespace std;
namespace maze{

const unsigned char Maze::WALL  = '@';
const unsigned char Maze::EMPTY = '-';
const int Maze::NORTH= 0;
const int Maze::SOUTH= 1;
const int Maze::EAST= 2;
const int Maze::WEST= 3;
Maze::Maze(int h, int w):
		height(h),
		width(w),
		grid(nullptr){
	dir[0] = NORTH;
	dir[1] = SOUTH;
	dir[2] = EAST;
	dir[3] = WEST;
	std::srand(time(0));
	generate_maze(h, w);

}

void Maze::reset_maze(int h, int w){
	delete_maze();
	height = h;
	width= w;
	grid = new uchar*[height];
	for (int i = 0; i < height; i++){
		grid[i] = new uchar[width];
		for (int j = 0; j < width; j++){
			grid[i][j] = 1;
		}
	}
}

void Maze::generate_maze(int h, int w){
	reset_maze(h, w);
	visit(0,0);
}

void Maze::delete_maze(){
	if (grid != nullptr){
		for (int i = 0; i < height; i++){
			delete[] grid[i];
		}
		delete[] grid;
	} 
}

void Maze::shuffle_dir(){
	for (int i = 0; i < 4; i++){
		int r = std::rand() & 3;
		int aux = dir[r];
		dir[r] = dir[i];
		dir[i] = aux;
	 }
}
bool Maze::inRange(int i, int j){
	return ((i >= 0) && (i< height) && (j >= 0) && (j< width));
}

void Maze::visit(int i, int j){

	int dx  = 0;
	int dy = 0;
	int i_next = 0;
	int j_next = 0;
	grid[i][j] = 0;
	shuffle_dir();
	//std::cout << dir[0] << " " << dir[1] << " " << dir[2] << " "<< dir[3] << std::endl;
	for(int k = 0; k <  4; k++){
		//std::cout << dir[k] << std::endl;
		if (dir[k] == NORTH){
			dy = -1;
			dx = 0;
		}
		else if (dir[k] == SOUTH){
			dy = 1;
			dx = 0;
		}
		else if (dir[k] == EAST){
			dy = 0;
			dx = 1;
		}
		else if (dir[k] == WEST){
			dy = 0;
			dx = -1;
		}
		i_next = i + (dy<<1);
		j_next = j + (dx<<1);
		if (inRange(i_next, j_next) && grid[i_next][j_next] == 1){
			grid[i_next - dy][j_next - dx] = 0;
			visit(i_next, j_next);

		}
	}
}

void Maze::print(){
	char LIMIT = '=';
	std::cout << " Maze ( "<< height << " x " << width << " ) " << std::endl;
	std::cout << " ";
	for (int j = 0; j < width; j++){
		std::cout << LIMIT;
	}
	std::cout << " ";
	std::cout << std::endl;
	for (int i = 0; i < height; i++){
		std::cout << "|";
		for (int j = 0; j < width; j++){
			if (grid[i][j] == 0) {
				std::cout << EMPTY;
			}
			else if (grid[i][j] == 7) {
				std::cout << YELLOW << "X" << RESET;
			}
			else {
				std::cout << BLACK << WALL << RESET;
			}
		}
		std::cout << "|";
		std::cout << std::endl;
	}
	std::cout << " ";
	for (int j = 0; j < width; j++){
		std::cout << LIMIT;
	}
	std::cout << " ";
	std::cout << std::endl;
}


LinkedList Maze::solve_pila(int f1, int c1, int f2, int c2) {
    LinkedList solution;
    Stack stack;
    vector<vector<int>> visited(height, vector<int>(width, 0));

	if (f2 == height || c2 == width) {
		std::cout << "No se puede elegir como target una coordenada invalida" << endl;
		return solution;
	}

    else if (grid[f1][c1] == 1) {
        cout << "No hay solucion, imposible iniciar en las coordenadas de una muralla" << endl;
        return solution;
    }

    stack.push(f1, c1);
    visited[f1][c1] = 1;
	solution.insertLast(f1, c1);

    while (!stack.isEmpty()) {
        Node* current = stack.top();

        if (current->getFila() == f2 && current->getColumna() == c2) {
            cout << "Se llego al target, saliendo..." << endl;
            return solution;
        }

        bool found = false; 

        shuffle_dir();
        for (int i = 0; i < 4; i++) {
            int dx = 0;
            int dy = 0;

            if (dir[i] == NORTH) {
                dy = -1;
            } 
			else if (dir[i] == SOUTH) {
                dy = 1;
            } 
			else if (dir[i] == EAST) {
                dx = 1;
            } 
			else if (dir[i] == WEST) {
                dx = -1;
            }

            int fn = current->getFila() + dx;
            int cn = current->getColumna() + dy;

            if (inRange(fn, cn)) {
                if (grid[fn][cn] == 0 && visited[fn][cn] == 0) {
                    stack.push(fn, cn);
                    visited[fn][cn] = 1;
                    solution.insertLast(fn, cn);
                    found = true;  
                    break;
                }
            }
        }

        if (!found) {
            stack.pop();
        }
    }

	if (solution.find(f2, c2) != nullptr) {
		cout << "Se encontro solucion al laberinto" << endl;
	}
	else {
		cout << "El laberinto no tiene solucion" << endl;
	}
    return solution;
}

LinkedList Maze::solve_cola(int f1, int c1, int f2, int c2) {
	LinkedList solution;
    Queue queue;
    vector<vector<int>> visited(height, vector<int>(width, 0));

	if (f2 == height || c2 == width) {
		std::cout << "No se puede elegir como target una coordenada invalida" << endl;
		return solution;
	}

    if (grid[f1][c1] == 1) {
        cout << "No hay solucion, imposible iniciar en las coordenadas de una muralla" << endl;
        return solution;
    }

    queue.push(f1, c1);
    visited[f1][c1] = 1;
	solution.insertLast(f1, c1);

    while (!queue.isEmpty()) {
        Node* current = queue.top();

        if (current->getFila() == f2 && current->getColumna() == c2) {
            cout << "Se llego al target, saliendo..." << endl;
            return solution;
        }

        bool found = false; 

        shuffle_dir();
        for (int i = 0; i < 4; i++) {
            int dx = 0;
            int dy = 0;

            if (dir[i] == NORTH) {
                dy = -1;
            } 
			else if (dir[i] == SOUTH) {
                dy = 1;
            } 
			else if (dir[i] == EAST) {
                dx = 1;
            } 
			else if (dir[i] == WEST) {
                dx = -1;
            }

            int fn = current->getFila() + dx;
            int cn = current->getColumna() + dy;

            if (inRange(fn, cn)) {
                if (grid[fn][cn] == 0 && visited[fn][cn] == 0) {
                    queue.push(fn, cn);
                    visited[fn][cn] = 1;
                    solution.insertLast(fn, cn);
                    found = true;  
                    break;
                }
            }
        }

        if (!found) {
            queue.pop();
        }
    }

	if (solution.find(f2, c2) != nullptr) {
		cout << "Se encontro solucion al laberinto" << endl;
	}
	else {
		cout << "El laberinto no tiene solucion" << endl;
	}

    return solution;
}

LinkedList Maze::solve_pila() {
	int f1 = 0;
	int c1 = std::rand() & width - 1;
	
	int f2 = height - 1;
	int c2 = std::rand() & width - 1;
	
	LinkedList solution = solve_pila(f1, c1, f2, c2);
	return solution;
}

LinkedList Maze::solve_cola() {

	// "Resolver el laberinto generado cuando el inicio es cualquier punto de la primera fila y el target
	// es cualquier punto de la ultima fila"

	int f1 = 0;
	int c1 = std::rand() & width - 1;
	
	int f2 = height - 1;
	int c2 = std::rand() & width - 1;
	
	LinkedList solution = solve_cola(f1, c1, f2, c2);
	return solution;
}

void Maze::solutionPrinter(LinkedList& solution) {
	Node* ptr = solution.head;
	while (ptr != nullptr) {
		int current_row = ptr->getFila();
		int current_column = ptr->getColumna();
		grid[current_row][current_column] = 7;
		this_thread::sleep_for(chrono::milliseconds(70));
		print();
		ptr = ptr->getNext();
	}


	Node* undoPtr = solution.head;
	while (undoPtr != nullptr) {
		int current_row = undoPtr->getFila();
		int current_column = undoPtr->getColumna();
		grid[current_row][current_column] = 0;
		undoPtr = undoPtr->getNext();
	}
}

}

# mazeSolverProject
El siguiente código fue desarrollado para la asignatura de Estructura de Datos y Algoritmos. El enunciado y las instrucciones del proyecto se encuentran a continuación.

## Descripción
En esta tarea deberás resolver un laberinto. Un laberinto es una matriz binaria, es decir que tiene dos posibles valores: (0) para indicar una celda disponible y (1) para indicar un muro. Así, en esta tarea deberán encontrar diversas soluciones dado un punto de inicio y un punto target para un laberinto generado aleatoriamente. La Figura 1 muestra, a la izquierda, un laberinto generado aleatoriamente y, a la derecha, una solución que parte de la primera fila y llega a la última. El laberinto mostrado en Figura 1 ha sido creado con el código de `https://github.com/jmsaavedrar/eda_cpp/tree/main/laberinto`. Esta implementación contiene la clase Maze, con métodos que permiten generar aleatoriamente un laberinto (puedes probarlo con el programa test del mismo repositorio).

## Descripción detallada

1. Agregar a la clase Maze, el método solve < estrategia > (f1, c1, f2, c2), que recibe como parámetros la posición inicial (f1, c1) y la posición target (f2, c2). El método debe devolver una lista con las posiciones de una posible solución. Tendremos dos versiones de solve, cambiando la estrategia. La primera usa una pila y la segunda una cola, por lo tanto, tendrás solve pila() y solve cola().

2. Resolver el laberinto generado cuando el inicio es cualquier punto de la primera fila y el target es cualquier punto de la última fila. Por ejemplo, la Figura 1 muestra una posible solución.

3. Mostrar en pantalla, la solución, marcando el path o camino encontrado con un símbolo especial (por ejemplo “x”). Deberás mostrar dos soluciones una con solve pila y otra con solve cola.

4. Sobre la solución: Para solucionar el algoritmo deberás experimentar con 2 estrategias. La primera usa una pila y la segunda una cola, como lo indicamos en el punto 1.

5. En ambos casos (con pila o con cola), la forma de insertar los nodos que vamos visitando deberá ser aleatoria, para garantizar que podamos encontrar diversas soluciones en cada ejecución. Esto es, si un nodo A se conecta los nodos B, C y D, los tres nodos hijos deben ser mezclados aleatoriamente antes de insertarlos en la pila o cola. Debes notar, que algunas veces el laberinto no tendrá solución, en ese caso deberás mostrar un mensaje indicando ese hecho.


<img width="362" alt="Sin título" src="https://github.com/PedroVillegasss/maze_solver_project/assets/127313865/2a0639d7-478d-49d3-9f2c-32016bc5b0f9">

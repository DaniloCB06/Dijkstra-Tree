# Dijkstra-Tree
This C program implements a simple graph structure and uses Dijkstra's algorithm to calculate the shortest paths from a starting node to other nodes in the graph. Here's an overview

1. **Graph Structure:**
   - The graph is represented by an adjacency list, where each vertex points to a list of neighboring vertices (nodes).
   - A `Viz` struct represents the edges between nodes, storing the destination node (`noj`), the weight of the edge (`peso`), and a pointer to the next neighbor.
   - The `Grafo` struct maintains the number of vertices (`nv`), the number of edges (`na`), and an array of adjacency lists (`viz`).

2. **Dijkstra's Algorithm:**
   - The function `dijkstra` calculates the shortest path from the start node (node 0) to all other nodes.
   - A `vetor` array stores the minimum distance to each node, initialized with a large value (infinity) except for the start node (set to 0).
   - A `visitados` array tracks whether a node has been visited.
   - The algorithm iteratively selects the node with the smallest distance that hasn't been visited, updates distances to its neighbors, and marks the node as visited.

3. **Helper Functions:**
   - `novoViz`: Creates a new node for the adjacency list.
   - `procuraMenor`: Finds the unvisited node with the smallest distance.
   - `visitaGrafo`: Updates the distances to neighboring nodes.
   - `exibeVetor`: Displays the current distances from the start node to each node.
   - `liberaMemoria`: Frees the allocated memory for the graph and adjacency lists.

4. **Example Graph:**
   - A graph with 5 nodes is manually constructed, and edges between nodes with weights are added.
   - The program runs Dijkstra's algorithm from node 0 and displays the shortest path to each node.

5. **Memory Management:**
   - The memory allocated for the graph and adjacency lists is freed at the end of the program using `liberaMemoria`.

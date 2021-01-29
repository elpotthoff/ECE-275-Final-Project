### ECE-275-Final-Project

## My final project for ECE 275 (Programming for Engineering II)

# An Explanation of my Project 2
1. My program is split into two parts, an abstract graph class, and the shortest path solver class.
   - The abstract graph class utilizes a metadata template capable of storing objects within the vertices of the graph. Additionally, I implemented my graph so that it is capable of being directed or undirected and weighted or unweighted. This allows for the abstract graph class to be applicable to almost any problem that needs solving
   - The graph itself is made up of a vector containing structures called nodes and a vector of vectors known as the adjacency matrix.
     - Each node in the vector of vertices contains a data variable of a type determined at instantiation. Additionally, each node is assigned an index number in the vector of vertices that allows for easy record keeping.
     - The adjacency matrix represents the edges between vertices. The vertical index of the adjacency matrix represents the source of the edge and the horizontal index represents the vertex that the edge points to. A zero in the matrix represents no connection between the two vertices. If the graph is unweighted, then edges will be represented with a one. If the graph is weighted then the edges will be represented with an integer equivalent to the weight of the edge.
   - The abstract graph contains a multitude of functions that allow for vertices and edges to be added or removed, to return the data from a vertex or the weight of an edge, or to print the adjacency matrix
2. The shortest path solver uses a path solving algorithm known as Dijkstra’s algorithm which was conceived by computer scientist Edsger W. Dijkstra in 1956. This algorithm calculates the shortest path from one source vertex to all vertices in the graph. I decided to implement this algorithm due to its simplicity for me to understand.
   - My process in constructing this class was to first write down and understand the Dijkstra’s algorithm. I then began by making a state diagram of this algorithm that I then translated into C code. Combining the C program that I created with my class definition was relatively easy and simply required changing some variables.
   - The shortest path solver implements breadth-first-search to a degree. Instead of expanding on nodes in order of the shortest number of vertices between the node and the source; it instead expands on nodes in order of the shortest distance between the node and the source. I honestly don’t know if this is technically considered breadth-first-searching, but it operates essentially the same way. If the graph was unweighted then it would be breadth-first-searching by the more standard definition.

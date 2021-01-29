#ifndef GRAPH_BASE
#define GRAPH_BASE

#include <iostream>
#include <vector>
#include <string>

// The abstract graph base I've created is capable of creating a combination 
//    of unweighted/weighted and undirected/directed graph.
// Every vertex is capable of holding data in any number of forms,
//    including integers, strings, and objects.
// Note that vertex and node are used interchangeably

// This struct stores the data for each vertex
// The typename T2 allows the data to be in almost any form (int, struct, etc.)
template <typename T2>
struct Node {
	T2 data;
};

//This class is a pure virtual class and is only able to be derived into other classes
// the type name T is equivalent to typename T2 in the Node class
template <typename T>
class GraphBase {
public:
	// This pure virtual function allows this class to only be derived into other classes
	virtual void create() = 0;

	//This function adds a node to the end of the vector of vertices
	void addNode(T data) {
		Node<T> temp; // Here the node is instantiated
		temp.data = data; // The node is then filled with the incoming data

		this->vertices.push_back(temp); // The node is then put at the end of the vector of vertices

		this->numNodes = this->numNodes + 1; // The number of nodes is increased by one

		this->adjMatrix.resize(this->numNodes); // The horizontal part of the adjacency matrix is increased by one

		for (int i = 0; i < this->numNodes; ++i) // The vertical part of the adjacency matrix is increased by one
			this->adjMatrix[i].resize(this->numNodes);
	};

	// This function removes a node from the vector of vertices
	void removeNode(int index) { 
		this->vertices.erase(this->vertices.begin() + index); // This erases the node using the inputted index

		this->adjMatrix.erase(this->adjMatrix.begin() + index); // This erases the node from the horizontal part of the adjacency list
		for (int i = 0; i < this->numNodes; ++i) // This erases the node from the vertical part of the adjacency list
			this->adjMatrix[i].erase(this->adjMatrix[i].begin() + index);
	};

	// This function returns the data being stored in a node at the inputted index
	T returnData(int index) { 
		return (this->vertices[index]).data;
	};

	// This function adds an unweighted edge between the nodes at the two inputted indexes
	void addEdge(int index1, int index2) { 
		this->adjMatrix[index1][index2] = 1;
	};

	// This function adds a weighted edge between the nodes at the two inputted indexes
	void addEdge(int index1, int index2, int weight) {
		this->adjMatrix[index1][index2] = weight;
	};

	// This function removes an edge between the nodes at the two inputted indexes
	void removeEdge(int index1, int index2) { 
		this->adjMatrix[index1][index2] = 0;
	};

	// This function returns the weight of an edge between the nodes at the two inputted indexes
	int returnEdge(int index1, int index2) { 
		return this->adjMatrix[index1][index2];
	};

	// This function returns the number of vertices in the graph
	int returnNumNodes() { 
		return this->numNodes;
	};

	// This function prints the adjacency matrix
	void printAdjMatrix() {
		std::cout << " " << "\t";

		for (int i = 0; i < this->numNodes; i++) {
			std::cout << vertices[i].data.name << "\t";
		}

		std::cout << std::endl;

		for (int m = 0; m < this->numNodes; m++) {
			std::cout << vertices[m].data.name << "\t";
			for (int n = 0; n < this->numNodes; n++) {
				std::cout << adjMatrix[m][n] << "\t";
			}
			std::cout << std::endl;
		}
	}

protected:
	int numNodes{}; 
	// This integer contains the number of vertices in the graph

	std::vector<Node<T>> vertices; 
	// This vector stores the vertices of the graph in the order that they were inserted
	
	std::vector<std::vector<int>> adjMatrix; 
	// This adjacency matrix identifies the edges between vertices on the graph

};


#endif
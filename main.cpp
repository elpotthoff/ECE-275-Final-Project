#include "GraphBase.hpp"
#include "ShortestPath.hpp"

#include <iostream>
#include <vector>
#include <string>

// This main.cpp is a working example of how the graph can be utilized
int main(void) {

	MetaData A;
	MetaData B;
	MetaData C;
	MetaData D;
	MetaData E;
	MetaData F;

	A.name = "A";
	B.name = "B";
	C.name = "C";
	D.name = "D";
	E.name = "E";
	F.name = "F";

	ShortestPath graph;
	graph.create();

	graph.addNode(A);
	graph.addNode(B);
	graph.addNode(C);
	graph.addNode(D);
	graph.addNode(E);
	graph.addNode(F);

	graph.addEdge(0, 1, 4);
	graph.addEdge(0, 2, 2);
	graph.addEdge(1, 2, 5);
	graph.addEdge(1, 3, 10);
	graph.addEdge(2, 4, 3);
	graph.addEdge(3, 5, 11);
	graph.addEdge(4, 3, 4);

	graph.printAdjMatrix();

	std::cout << "Shortest distance from A to D = " << graph.calculateShortestPath(0, 3) << std::endl;
	graph.printShortestPathTree(0);
	std::cout << "Shortest distance from C to D = " << graph.calculateShortestPath(2, 3) << std::endl;
	graph.printShortestPathTree(2);
	std::cout << "Shortest distance from B to F = " << graph.calculateShortestPath(1, 5) << std::endl;
	graph.printShortestPathTree(1);
	std::cout << "Shortest distance from F to D = " << graph.calculateShortestPath(5, 3) << std::endl;
	graph.printShortestPathTree(5);

	return 0;
}
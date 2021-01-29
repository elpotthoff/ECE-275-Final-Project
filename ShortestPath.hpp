#ifndef MY_GRAPH
#define MY_GRAPH

#include "GraphBase.hpp"

#include <iostream>
#include <vector>
#include <string>

// This struct stores the data for each vertex of the path
struct MetaData { 
	// Currently I only have the name of each vertex, 
	//     but I can store a wide variety of data here
	std::string name;
};

// This class derives from the graph base
// This class's goal is to find the shortest path between two points
class ShortestPath : public GraphBase<MetaData> {
public:
	// This function overrides the pure virtual function of the GraphBase
	void create() override;

	// This function calculates the distance to every vertex from the inputted index of a vertex
    std::vector<int> calculateShortestPathTree(int index1);

	// This function calculates the shortest distance between the vertices of the inputted indexes
    int calculateShortestPath(int index1, int index2);

	// This function prints a list of the distances to every vertex from the inputted index of a vertex
    void printShortestPathTree(int index1);

private:
	// This function finds the next adjacent vertex (that hasn't been added to the shortest path tree already) with the smallest distance
	int minDistance(std::vector<int> dist, std::vector<bool> sptSet);
};


#endif
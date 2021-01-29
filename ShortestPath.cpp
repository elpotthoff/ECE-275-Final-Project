#include "ShortestPath.hpp"


void ShortestPath::create() {
	this->numNodes = 0;
	this->vertices.resize(0);
	this->adjMatrix.resize(0);

}

std::vector<int> ShortestPath::calculateShortestPathTree(int index1) {

    std::vector<int> shortestPathTree; // Instantiate a vector for the shortest path tree
    shortestPathTree.resize(this->numNodes); // Resize said vector to be the length of the number of vertices in the graph

    std::vector<bool> shortPathTreeSet; // Instantiate a vector for the shortest path tree set
    shortPathTreeSet.resize(this->numNodes); // Resize said vector to be the length of the number of vertices in the graph

    for (int i = 0; i < this->numNodes; i++) // Initialize all indices of the shortest path tree with infinity and all indices of the shortest path tree set with false
        shortestPathTree[i] = INT_MAX, shortPathTreeSet[i] = false;

    shortestPathTree[index1] = 0; // The source vertex has a distance of 0 to the source vertex

    // Calculate shortest path tree here
    for (int count = 0; count < this->numNodes - 1; count++) {
        int u = minDistance(shortestPathTree, shortPathTreeSet); // Find the next adjacent vertex (that hasn't been added to the shortest path tree already) with the smallest distance

        shortPathTreeSet[u] = true; // Mark that you've covered that vertex that you've just found

        // Update shortest path tree only if vertex is not marked in shortest path tree set, 
        // there is an edge from u to v, and total weight of path from source to  v through u is 
        // smaller than current value of shortest path tree
        for (int v = 0; v < this->numNodes; v++) {
            if (!shortPathTreeSet[v] && this->adjMatrix[u][v] && shortestPathTree[u] != INT_MAX && shortestPathTree[u] + this->adjMatrix[u][v] < shortestPathTree[v])
                shortestPathTree[v] = shortestPathTree[u] + this->adjMatrix[u][v];
        }
    }

    return shortestPathTree;
}

int ShortestPath::calculateShortestPath(int index1, int index2) {
    std::vector<int> shortestPathTree = calculateShortestPathTree(index1); // Find shortest path tree
    
    if (shortestPathTree[index2] == INT_MAX) { // If the value at index2 equals infinity then there is no path from index1 to index2
        std::cout << "Path impossible" << std::endl;
        return -1;
    }
    else
        return shortestPathTree[index2]; // Else, return the shortest distance from index1 to index2
}

void ShortestPath::printShortestPathTree(int index1) {
    std::vector<int> shortestPathTree = calculateShortestPathTree(index1);

    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < this->numNodes; i++) {
        std::cout << i << "\t";
        if (shortestPathTree[i] == INT_MAX) // If the value at index2 equals infinity then there is no path from index1 to i
            std::cout << "Path impossible" << std::endl;
        else if (shortestPathTree[i] == 0) // Only the source has a distance of 0
            std::cout << "Source" << std::endl;
        else
            std::cout << shortestPathTree[i] << std::endl; // Print distance from index1 to i
    }
}

int ShortestPath::minDistance(std::vector<int> dist, std::vector<bool> sptSet) {
    int min = INT_MAX, min_index = 0;

    // Finds the next adjacent vertex (that hasn't been added to the shortest path tree already) with the smallest distance
    for (int v = 0; v < this->numNodes; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}
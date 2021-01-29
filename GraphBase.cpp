#include "GraphBase.hpp"

template <typename T>
void GraphBase<T>::addNode(T data) {
	Node<T>* temp = nullptr;
	temp->data = data;

	this->vertices.push_back(temp);

	this->numNodes = this->numNodes + 1;

	this->adjMatrix.resize(this->numNodes);
	for (int i = 0; i < this->numNodes; ++i)
		this->adjMatrix[i].resize(this->numNodes);
}

template<typename T>
void GraphBase<T>::removeNode(int index) {
	this->vertices.erase(index);

	this->adjMatrix.erase(index);
	for (int i = 0; i < this->numNodes; ++i)
		this->adjMatrix[i].erase(index);
}

template<typename T>
Node<T>* GraphBase<T>::returnNode(int index) {
	return this->vertices[index];
}

template<typename T>
T* GraphBase<T>::returnData(int index) {
	return returnNode(index)->data;
}

template<typename T>
void GraphBase<T>::addEdge(int index1, int index2) {
	this->adjMatrix[index1][index2] = 1;
}

template<typename T>
void GraphBase<T>::addEdge(int index1, int index2, int weight) {
	this->adjMatrix[index1][index2] = weight;
}

template<typename T>
void GraphBase<T>::removeEdge(int index1, int index2) {
	this->adjMatrix[index1][index2] = 0;
}

template<typename T>
int GraphBase<T>::returnEdge(int index1, int index2) {
	return this->adjMatrix[index1][index2];
}

template<typename T>
int GraphBase<T>::returnNumNodes() {
	return this->numNodes;
}

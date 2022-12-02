#pragma once
template<class T>
struct Node {
	T data;
	int height;
	Node<T>* left;
	Node<T>* right;
	
};
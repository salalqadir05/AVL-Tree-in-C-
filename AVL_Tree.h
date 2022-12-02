#pragma once
#include "LinkNode.h"
template<class T>
class AVL_Tree
{
protected:
	Node<T>* root;
public:
	AVL_Tree();
	virtual void insert(T value)=0;
	virtual void Insert(Node<T>*p,Node<T>* n)=0;
	virtual void inorder(Node<T>* p)=0; //LNR
	virtual void iinorder(Node<T>* p) = 0; //RNL
	virtual void preorder(Node<T>* p) = 0; //NLR
	virtual void ppreorder(Node<T>* p) = 0; //NRL
	virtual void postorder(Node<T>* p) = 0; //LRN
	virtual void ppostorder(Node<T>* p) = 0; //RLN
	virtual void display(Node <T>* ptr, int level) = 0;
	virtual T serachNumber(Node<T>* p,T value) = 0;
	~AVL_Tree();
};


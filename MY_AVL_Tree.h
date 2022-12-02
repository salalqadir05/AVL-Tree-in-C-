#pragma once
#include "LinkofAvl.h"
template<class T>
class MY_AVL_Tree :public AVL_Tree<T>
{
public:
	MY_AVL_Tree()
	{

	}
	 void insert(T value) ;
	 void Insert(Node<T>* p, Node<T>* n) ;
	 void inorder(Node<T>* p) ;
	 void Inorder() ;
	 void iinorder(Node<T>* p);
	 void IInorder();
	 void display(Node <T>* ptr, int level) ;
	 void Display();
	 void preorder(Node <T>* p);
	 void Preorder();
	 void ppreorder(Node <T>* p);
	 void PPreorder();
	 void postorder(Node <T>* p);
	 void Postorder();
	 void ppostorder(Node <T>* p);
	 void PPostorder();
	 T serachNumber(Node<T>* p,T key);
	 int max(int a, int b);
	 int getheight(Node <T>* p);
	 int getbalancefactor(Node<T> *p);
	 Node<T>* rightrotate(Node<T>* y);
	 Node<T>* leftrotate(Node<T>* y);
	 void readfile(MY_AVL_Tree<T>& ptr,fstream & fin);
	 void option(MY_AVL_Tree<T> &obj );
};


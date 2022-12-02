#include "AVL_Tree.h"
#include <iostream>
using namespace std;
template<class T>
AVL_Tree<T>::AVL_Tree()
{
	root = nullptr;

}

template<class T>
AVL_Tree<T>::~AVL_Tree()
{
	root = nullptr;
}
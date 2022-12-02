#include "MY_AVL_Tree.h"
#include <fstream>
#include<iostream>
using namespace std;
template<class T>
void MY_AVL_Tree<T>::insert(T value)
{
	Node <T>* n = new Node <T>;
	n->data = value;
	n->left = n->right = nullptr;
	
	if (MY_AVL_Tree<T>::root == nullptr)
	{
		n->height = 1;
		MY_AVL_Tree<T>::root=n;
	}
	else
	{
		Insert(MY_AVL_Tree<T>::root, n);
	}
	n->height = 1 + max(getheight(n->left), getheight(n->right));
	int bf = getbalancefactor(n);
	//left left
	if (bf > 1 && value < n->left->data)
	{
		rightrotate(n);
	}
	//right right
	if (bf < -1 && value > n->right->data)
	{
		leftrotate(n);
	}
	//left right
	if (bf > 1 && value > n->left->data)
	{
		n->left = leftrotate(n->left);
		rightrotate(n);
	}
	//right left
	if (bf < -1 && value < n->right->data)
	{
		n->right = rightrotate(n->right);
		leftrotate(n);
	}
}
template<class T>
void MY_AVL_Tree<T>::Insert(Node<T>* Orginalroot, Node<T>* n)
{
	if (n->data < Orginalroot->data && Orginalroot->left == nullptr)
	{
		Orginalroot->left = n;
	}
	else if (n->data < Orginalroot->data && Orginalroot->left != nullptr)
	{
		Insert(Orginalroot->left, n);
	}
	if (n->data >= Orginalroot->data && Orginalroot->right == nullptr)
	{
		Orginalroot->right = n;
	}
	else if (n->data >= Orginalroot->data && Orginalroot->right != nullptr)
	{
		Insert(Orginalroot->right, n);
	}
}
template<class T>
void MY_AVL_Tree<T>::inorder(Node<T>* p)
{
	if (p != nullptr)
	{
		inorder(p->left);
		cout << p->data << endl;
		inorder(p->right);
	}
}
template<class T>
void MY_AVL_Tree<T>::Inorder()
{
	if (MY_AVL_Tree<T>::root != nullptr)
	{
		cout << "---------------------------------------------------------------------------------------\n";
		inorder(MY_AVL_Tree<T>::root);
		cout << "---------------------------------------------------------------------------------------\n";
	}
}
template<class T>
void MY_AVL_Tree<T>::iinorder(Node<T>* p)
{
	if (p != nullptr)
	{
		iinorder(p->right);
		cout << p->data << endl;
		iinorder(p->left);
	}
}
template<class T>
void MY_AVL_Tree<T>::IInorder()
{
	if (MY_AVL_Tree<T>::root != nullptr)
	{
		cout << "---------------------------------------------------------------------------------------\n";
		iinorder(MY_AVL_Tree<T>::root);
		cout << "---------------------------------------------------------------------------------------\n";
	}
}
template<class T>
void MY_AVL_Tree<T>::preorder(Node <T>* p)
{
	if (p == nullptr)
	{
		return;
	}
	cout << p->data << endl;
	preorder(p->left);
	preorder(p->right);
}
template<class T>
void MY_AVL_Tree<T>::Preorder()
{
	if (MY_AVL_Tree<T>::root != nullptr)
	{
		cout << "---------------------------------------------------------------------------------------\n";
		preorder(MY_AVL_Tree<T>::root);
		cout << "---------------------------------------------------------------------------------------\n";
	}
}
template<class T>
void MY_AVL_Tree<T>::ppreorder(Node <T>* p)
{
	if (p == nullptr)
	{
		return;
	}
	cout << p->data << endl;
	ppreorder(p->right);
	ppreorder(p->left);
}
template<class T>
void MY_AVL_Tree<T>::PPreorder()
{
	if (MY_AVL_Tree<T>::root != nullptr)
	{
		cout << "---------------------------------------------------------------------------------------\n";
		ppreorder(MY_AVL_Tree<T>::root);
		cout << "---------------------------------------------------------------------------------------\n";
	}
}
template <class T>
void MY_AVL_Tree<T>::postorder(Node<T>* p)
{
	if (p == nullptr)
	{
		return;
	}
	postorder(p->left);
	postorder(p->right);
	cout << p->data << endl;
}
template<class T>
void MY_AVL_Tree<T>::Postorder()
{
	if (MY_AVL_Tree<T>::root != nullptr)
	{
		cout << "---------------------------------------------------------------------------------------\n";
		postorder(MY_AVL_Tree<T>::root);
		cout << "---------------------------------------------------------------------------------------\n";
	}
}
template <class T>
void MY_AVL_Tree<T>::ppostorder(Node<T>* p)
{
	if (p == nullptr)
	{
		return;
	}
	ppostorder(p->right);
	ppostorder(p->left);
	cout << p->data << endl;
}
template<class T>
void MY_AVL_Tree<T>::PPostorder()
{
	if (MY_AVL_Tree<T>::root != nullptr)
	{
		cout << "---------------------------------------------------------------------------------------\n";
		ppostorder(MY_AVL_Tree<T>::root);
		cout << "---------------------------------------------------------------------------------------\n";
	}
}
template<class T>
T MY_AVL_Tree<T>::serachNumber(Node<T>* p,T key)
{
	
	if (p != nullptr)
	{
		serachNumber(p->left, key);
			if (p->data == key)
			{
				cout <<"---------------------------------------------------------------------------------------\n";
				cout << "element exists :" << key << endl;;
				cout <<"---------------------------------------------------------------------------------------\n";
			}
			serachNumber(p->right, key);			
	}
	return key;
}
template <class T>
void MY_AVL_Tree<T>::display(Node <T>* ptr,int level)
{
	int i=0;
	if (ptr != nullptr)
	{
		display(ptr->right, level + 1);
		printf("\n");
		if (ptr == MY_AVL_Tree<T>::root)
			cout << "Root -> ";
		for (int i = 0; i < level &&  ptr != MY_AVL_Tree<T>::root; i++)
			cout << " ";
		cout << ptr->data;
		display(ptr->left, level + 1);
	}
}
template<class T>
void MY_AVL_Tree<T>::Display()
{
	int level = 1;
	if (MY_AVL_Tree<T>::root != nullptr)
	{
		display(MY_AVL_Tree<T>::root, level);
	}
	cout << endl;
}

template<class T>
int MY_AVL_Tree<T>::getheight(Node<T>* p)
{
	if (p == nullptr)
	{
		return 0;
	}
	return p->height;
}
template<class T>
int MY_AVL_Tree<T>::getbalancefactor( Node<T>* p)
{
	if(p==nullptr)
	{
		return 0;
	}
	int bf= getheight(p->left) - getheight(p->right);
	return  bf;
}
template<class T>
Node<T>* MY_AVL_Tree<T>::rightrotate(Node<T>* y)
{
	Node<T>* x = y->left;
	Node<T>* t1 = x->right;
	x->right = y;
	y->left = t1;
	y->height = max(getheight(y->right), getheight(y->left)) + 1;
	x->height = max(getheight(x->right), getheight(x->left)) + 1;
	return x;
}
template<class T>
Node<T>* MY_AVL_Tree<T>::leftrotate(Node<T>* x)
{
	Node<T>* y = x->right;
	Node<T>* t1 = y->left;
	y->left = x;
	x->right = t1;
	y->height = max(getheight(y->right), getheight(y->left)) + 1;
	x->height = max(getheight(x->right), getheight(x->left)) + 1;
	return y;
}

template<class T>
int MY_AVL_Tree<T>::max(int x,int y)
{
	if (x > y)
		return x;
	else
		return y;
}
template <class T>
void MY_AVL_Tree<T>::option( MY_AVL_Tree<T>& ptr)
{
	fstream fin;
	fin.open("input.txt");
	while (1)
	{
		cout << "1.press insert a value in Tree\n";
		cout << "2.seraching a value from Tree\n";
		cout << "3.Press for pre-order traversal NLR\n";
		cout << "4.pressfor in-order traversal LNR\n";
		cout << "5.Press for post - order traversal LRN\n";
		cout << "6.Press for pre - order traversal 2 NRL\n";
		cout << "7.Press for in - order traversal 2 RNL\n";
		cout << "8.press for post - order traversal 2 RLN\n";
		cout << "9.Press for displaying parent of a node present in Tree\n";
		cout << "10.Press to read integer values from the file “input.txt” to create a AVL tree\n";
		cout << "11.Press to delete values from the tree(Bonus)\n";
		cout << "12.Press to EXIT The program should exit when option 13 from the main menu is selected \n";
		int ch;
		cout << "enter your choice in :";
		cin >> ch;
		if (ch == 1)
		{
			int x;
			cout << "enter the number which do you want enter :";
			cin >> x;
			ptr.insert(x);
		}
		else if (ch == 2)
		{
			if (MY_AVL_Tree<T>::root != nullptr)
			{
				int temp;
				cout << "which number you want to serach :";
				cin >> temp;
				serachNumber(MY_AVL_Tree<T>::root, temp);
			}

		}
		else if (ch == 3)
		{
			Preorder();
		}
		else if (ch == 4)
		{
			Inorder();
		}
		else if (ch == 5)
		{
			Postorder();
		}
		else if (ch == 6)
		{
			PPreorder();
		}
		else if (ch == 7)
		{
			IInorder();
		}
		else if (ch == 8)
		{
			PPostorder();
		}
		else if (ch == 9)
		{
			Display();
		}
		else if (ch == 10)
		{
			readfile(ptr,fin);
		}
		else if (ch == 11)
		{
			cout << "---------------------------------------------------------------------------------------\n";
			cout << "deletion is bouns question and i don't have idea about deletion right now\n";
			cout << "---------------------------------------------------------------------------------------\n";
		}
		else if (ch == 12)
		{
			exit(0);
		}
	}
}
template <class T>
void MY_AVL_Tree<T>::readfile(MY_AVL_Tree<T> &ptr,fstream & fin)
{

	int x;
	while (!fin.eof())
	{
		fin >> x;
		cout << x << endl;
		ptr.insert(x);
	}
}
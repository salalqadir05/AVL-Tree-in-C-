#include<iostream>
#include<fstream>
#include "LinkofMYAVL.h"
using namespace std;
int main()
{
	fstream fin;
	fin.open("input.txt");
	MY_AVL_Tree<int> ptr;
	ptr.option(ptr);
	return 0;
}

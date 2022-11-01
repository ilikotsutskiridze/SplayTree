#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <clocale>
#include "TNODE.H"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class TREEE :public tnode
{
public:
	tnode* minitree;

	tnode* splay(tnode* tree, int k);//Специальная функция дерева
	tnode* create(int x, tnode* tree);
	tnode* del(tnode* tree, int x);
	void find(tnode* tree, int& x);//Поиск элемента в дереве
	void treeprint(tnode* tree);//Прямой обход дерева
	tnode* clear(tnode* tree);//Удаление поддерева
	tnode* ifprav(tnode* tree, int x);
	tnode* iflev(tnode* tree, int x);

	tnode* leftRotate(tnode* x);
	tnode* rightRotate(tnode* x);
	tnode* pomosh_v_find(tnode* tree);
};

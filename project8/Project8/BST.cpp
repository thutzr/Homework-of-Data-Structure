// BST.cpp : 定义控制台应用程序的入口点。
//
#include "BST.h"



int main()
{
	int x;
	std::cin >> x;
	BST<int> bst;
	while (x != 0) {
		if (x>0) bst.insert(x);
		else bst.remove(-x);
		printf("preOrder: ");
		bst.preOrder();
		printf("\n");
		printf("inOrder: ");
		bst.inOrder();
		printf("\n");
		std::cin >> x;
	}
	return 0;
}


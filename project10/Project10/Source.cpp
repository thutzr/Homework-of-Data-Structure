#include <iostream>
#include <stdlib.h>

using namespace std;

int* baseArr;

// 节点类型
typedef struct BSTNode {
	BSTNode *lchild;//左孩子
	BSTNode *rchild;//右孩子
	int data;//变量值
}BSTNode, *BST;
//创建新节点
BSTNode *createNode() {
	BST node = (BST)malloc(sizeof(BSTNode));
	if (node) {
		node->lchild = node->rchild = NULL;//左右孩子赋值为NULL
		return node;
	}
	else {//输入错误则退出
		exit(0);
	}
}
//插入节点
void insert(BSTNode*& root, int num) {
	BSTNode* temp = root;//代替根节点
	BSTNode* preTemp = NULL;//之后将作为temp前面的一个节点，即temp的父节点
	while (temp != NULL) {
		preTemp = temp;
		if ((temp->data) > num) {
			temp = temp->lchild;
		}
		else {
			temp = temp->rchild;
		}
	}
	if (preTemp != NULL) {
		BSTNode* leaf = createNode();
		leaf->data = num;
		if ((preTemp->data) > num) {
			preTemp->lchild = leaf;
		}
		else {
			preTemp->rchild = leaf;
		}
	}
}
//建立搜索树
//add N
void createTree(BSTNode*& root, int* arr, int N) {
	for (int i = 1; i < N; i++) {
		insert(root, arr[i]);
	}
}

bool compareTwoBST(BSTNode*& root1, BSTNode*& root2) {
	if ((root1 == NULL) && (root2 == NULL)) {
		return true;
	}
	else if ((root1 == NULL) || (root2 == NULL)) {
		return false;
	}

	if (root1->data != root2->data) {
		return false;
	}
	else {
		bool leftEqual = compareTwoBST(root1->lchild, root2->lchild);
		bool rightEqual = compareTwoBST(root1->rchild, root2->rchild);
		return (leftEqual && rightEqual);
	}
}

int main() {
	int L, N;
	
	cin >> L >> N;
	bool* finalResult = new bool[N];
	baseArr = new int[L];
	for (int i = 0; i < L; i++) {
		cin >> baseArr[i];
	}
	BSTNode* baseRoot = createNode();
	baseRoot->data = baseArr[0];
	createTree(baseRoot, baseArr, L);
	for (int i = 0; i < N; i++) {
		int* candArr = new int[L];
		for (int j = 0; j < L; j++) {
			cin >> candArr[j];
		}
		BSTNode* candRoot = createNode();
		candRoot->data = candArr[0];
		createTree(candRoot, candArr, L);
		BSTNode* temp = baseRoot;
		bool result = compareTwoBST(temp, candRoot);
		finalResult[i] = result;
	}
	for (int i = 0; i < N; i++) {
		if (finalResult[i] == true) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	system("pause");
}
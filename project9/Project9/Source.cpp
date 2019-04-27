#include <iostream>
//add <>
#include <stdlib.h>

using namespace std;

int* input;
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
void createTree(BSTNode*& root, int N) {
	for (int i = 1; i < N; i++) {
		insert(root, input[i]);
	}
}
// 找到公共祖先
int commonAncestor(BSTNode*& root, int num1, int num2) {
	if ((num1 < root->data) && (num2 < root->data)) {
		return commonAncestor(root->lchild, num1, num2);
	}
	if ((num1 > root->data) && (num2 > root->data)) {
		return commonAncestor(root->rchild, num1, num2);
	}
	return root->data;
}
int main() {
	//输入数据
	int N, M;
	cin >> N;
	cin >> M;
	input = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	int NUM11, NUM21, result;
	//建立根节点
	BSTNode* root1 = createNode();
	root1->data = input[0];
	createTree(root1, N);
	int* finalResult = new int[M];
	for (int j = 0; j < M; j++) {
		cin >> NUM11;
		cin >> NUM21;
		/*BSTNode* root1 = createNode();
		root1->data = input[0];
		createTree(root1);*/
		result = commonAncestor(root1, NUM11, NUM21);
		finalResult[j] = result;
	}
	for (int k = 0; k < M; k++) {
		cout << finalResult[k] << endl;
	}
}
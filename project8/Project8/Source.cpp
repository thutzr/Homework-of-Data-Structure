#include <iostream>
#include "BST.h"

using namespace std;

int* input;

typedef struct BSTNode {
	BSTNode *lchild;
	BSTNode *rchild;
	int data;
}BSTNode;

BSTNode *createNode() {
	BST node = (BST)malloc(sizeof(BSTNode));
	if (node) {
		node->lchild = node->rchild = NULL;
		return node;
	}
	else {
		exit(0);
	}
}

//void createTree(BSTNode*& root, int next) {
//	if (input[next] < root->data) {
//		BSTNode* p = createNode();
//		p->data = input[next];
//		root->lchild = p;
//		createTree(p, next + 1);
//	}
//	else if (input[next] > root->data) {
//		BSTNode* p = createNode();
//		p->data = input[next];
//		root->rchild = p;
//		createTree(p, next + 1);
//	}
//
//}

int commonAncestor(BSTNode* root, int num1, int num2) {
	if ((num1 < root->data) && (num2 < root->data)) {
		return commonAncestor(root->lchild, num1, num2);
	}
	if ((num1 > root->data) && (num2 > root->data)) {
		return commonAncestor(root->rchild, num1, num2);
	}
	return root->data;
}

int main() {
	int N, M;
	cin >> N;
	cin >> M;
	input = new int[N];
	BST<int> bst;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
		bst.insert(input[i]);
	}
	int num1, num2, result;
	BSTNode* root = createNode();
	root->data = input[0];
	

	int* finalResult = new int[M];
	for (int j = 0; j < M; j++) {
		cin >> num1;
		cin >> num2;
		result = commonAncestor(root, num1, num2);
		finalResult[j] = result;
	}
	for (int k = 0; k < M; k++) {
		cout << finalResult[k] << endl;
	}
}
#include <iostream>
#include <stdlib.h>

using namespace std;

int* baseArr;

// �ڵ�����
typedef struct BSTNode {
	BSTNode *lchild;//����
	BSTNode *rchild;//�Һ���
	int data;//����ֵ
}BSTNode, *BST;
//�����½ڵ�
BSTNode *createNode() {
	BST node = (BST)malloc(sizeof(BSTNode));
	if (node) {
		node->lchild = node->rchild = NULL;//���Һ��Ӹ�ֵΪNULL
		return node;
	}
	else {//����������˳�
		exit(0);
	}
}
//����ڵ�
void insert(BSTNode*& root, int num) {
	BSTNode* temp = root;//������ڵ�
	BSTNode* preTemp = NULL;//֮����Ϊtempǰ���һ���ڵ㣬��temp�ĸ��ڵ�
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
//����������
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
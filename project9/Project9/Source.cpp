#include <iostream>
//add <>
#include <stdlib.h>

using namespace std;

int* input;
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
void createTree(BSTNode*& root, int N) {
	for (int i = 1; i < N; i++) {
		insert(root, input[i]);
	}
}
// �ҵ���������
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
	//��������
	int N, M;
	cin >> N;
	cin >> M;
	input = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	int NUM11, NUM21, result;
	//�������ڵ�
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
#include <iostream>
#include <vector>
using namespace std;

int* inputPre;
int* inputMid;
vector<int> result;

typedef struct Node {
	Node *lchild;
	Node *rchild;
	int c;
}Node, *Tree;

Node *createNode() {
	Tree node = (Tree)malloc(sizeof(Node));
	if (node) {
		node->lchild = node->rchild = NULL;
		return node;
	}
	else {
		exit(0);
	}
}

Node * build(int s1, int e1, int s2, int e2) {
	Node * ret = createNode();
	ret->c = inputPre[s1];
	int rootIdx;
	for (int i = s2; i <= e2; i++) {
		if (inputMid[i] == inputPre[s1]) {
			rootIdx = i;
			break;
		}
	}
	if (rootIdx != s2) {
		ret->lchild = build(s1 + 1, s1 + (rootIdx - s2), s2, rootIdx - 1);
	}
	if (rootIdx != e2) {
		ret->rchild = build(s1 + (rootIdx - s2) + 1, e1, rootIdx + 1, e2);
	}
	result.push_back(ret->c);
	return ret;
}

int main() {

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int M;
		cin >> M;
		inputPre = new int[M];
		for (int j = 0; j < M; j++) {
			cin >> inputPre[j];
		}
		inputMid = new int[M];
		for (int j = 0; j < M; j++) {
			cin >> inputMid[j];
		}
		build(0, M-1, 0, M-1);
		for (int k = 0; k < M; k++) {
			cout << result[k];
		}
		cout << endl;
		result.clear();
	}
}

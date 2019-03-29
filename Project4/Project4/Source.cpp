#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>

using namespace std;

struct Node {
	int data;
	struct Node* next;
};

typedef struct Node* pointerNode;


pointerNode initializeList(int n) {
	pointerNode head, p, temp;
	head = NULL;
	p = NULL;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			temp = (pointerNode)malloc(sizeof(head));
			head = temp;
			p = head;
			temp->data = i + 1;
			temp->next = head;
		}
		else {
			temp = (pointerNode)malloc(sizeof(head));
			temp->data = i + 1;
			temp->next = head;
			p->next = temp;
			p = temp;
		}
	}
	return head;
}

pointerNode Delete(pointerNode head, int m) {
	pointerNode p = head;
	while (p != p->next) {
		for (int i = 0; i < m - 2; i++) {
			p = p->next;
		}
		p->next = p->next->next;
		p = p->next;
		continue;
	}
	return p;
}

int main() {
	int N;
	cin >> N;
	int M;
	cin >> M;
	pointerNode head = initializeList(N);
	pointerNode result = Delete(head, M);
	cout << result->data << endl;
	return 0;
}
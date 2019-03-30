#include <iostream>
#include <stack>

using namespace std;

bool stackPermutation(int B[]) {
	stack<int> S;
	int i = 1;
	int size = sizeof(B);
	for (int k = 0; k < size; k++) {
		while (S.empty() || S.top() != B[k]) {
			if (i > size) {
				return false;
			}
			else {
				S.push(i);
				i++;
			}
		}
		S.pop();
	}
	return true;
}


int main() {
	int N;
	cin >> N;
	int K;
	cin >> K;
	for (int i = 0; i < N; i++) {
		int *seq = new int[K];

		for (int j = 0; j < K; j++) {
			cin >> seq[j];
		}
		
		if (stackPermutation(seq) == true) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
		delete seq;
	}
	system("pause");
}
#include <iostream>
#include <queue>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
bool isPrime[10000];
bool visited[10000];
int result[10000];
int a, b;
void bfs(int x) {
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int t = q.front();
		if (t == b) {
			return;
		}
		visited[t] = true;
		q.pop();
		char ch[5];
		snprintf(ch, "%d", t);
		for (int i = 0; i < 4; i++) {
			for (int k = 0; k < 10; k++) {
				int temp;
				if ((i == 0) && (k == 0)) {
					continue;
				}
				if (i == 0) {
					temp = k * 1000 + (ch[1] - '0') * 100 + (ch[2] - '0') * 10 + (ch[3] - '0');
				}
				else if (i == 1) {
					temp = k * 100 + (ch[0] - '0') * 1000 + (ch[2] - '0') * 10 + (ch[3] - '0');
				}
				else if (i == 2) {
					temp = k * 10 + (ch[0] - '0') * 1000 + (ch[1] - '0') * 100 + (ch[3] - '0');
				}
				else if (i == 3) {
					temp = k + (ch[0] - '0') * 1000 + (ch[1] - '0') * 100 + (ch[2] - '0') * 10;
				}
				if (isPrime[temp] && !visited[temp] && temp < 10000) {
					result[temp] = result[t] + 1;
					visited[temp] = true;
					q.push(temp);
				}
			}
		}
	}
}


int main() {
	int n;
	cin >> n;
	int* finalresult = new int[n];
	for (int i = 0; i < 10000; i++) {
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i < 100; i++) {
		if (isPrime[i]) {
			for (int j = 2; i*j < 10000; j++) {
				isPrime[i*j] = false;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		memset(visited, false, sizeof(visited));
		memset(result, 0, sizeof(result));
		bfs(a);
		finalresult[i] = result[b];
	}
	for (int i = 0; i < n; i++) {
		cout << finalresult[i] << endl;
	}
	system("pause");
}
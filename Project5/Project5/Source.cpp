//#include <iostream>
//#include <stack>
//
//using namespace std;

#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int N, K, M, R;
	cin >> N;
	cin >> K;
	char result[N][10];
	int a[K + 1], b[K];
	for (int i = 0; i < N; i++)
	{
		M = 0;
		R = 0;
		for (int j = 0; j < K; j++)
		{
			cin >> b[j];
		}
		for (int k = 0; k < K + 1; k++) {
			a[k] = 0;
		}
		for (int r = 0; r < K; r++)
		{
			if (b[r] > M)
			{
				a[b[r]] = 1;
				M = b[r];
			}
			else
			{
				for (int t = M - 1; t > b[r]; t--)
				{
					if (a[t] == 0)
					{
						R = 1;
						break;
					}
				}
				if (R == 0) {
					a[b[r]] = 1;
				}
			}
			if (R == 1) {
				break;
			}
		}
		if (R) {
			strcpy(result[i], "No\n");
		}
		else {
			strcpy(result[i], "Yes\n");
		}
	}
	for (int i = 0; i < N; i++) {
		cout << result[i];
	}
}

//bool stackPermutation(int B[]) {
//	stack<int> S;
//	int i = 0;
//	int size = sizeof(B);
//	for (int k = 0; k < size; k++) {
//		while (S.empty() || S.top() != B[k]) {
//			if (i > size) {
//				return false;
//			}
//			else {
//				S.push(i);
//				i++;
//			}
//		}
//		S.pop();
//	}
//	return true;
//}
//
//
//int main() {
//	int N;
//	cin >> N;
//	int K;
//	cin >> K;
//	for (int i = 0; i < N; i++) {
//		int *seq = new int[K];
//
//		for (int j = 0; j < K; j++) {
//			cin >> seq[j];
//		}
//		
//		if (stackPermutation(seq) == true) {
//			cout << "Yes" << endl;
//		}
//		else {
//			cout << "No" << endl;
//		}
//		delete seq;
//	}
//	system("pause");
//}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int mergeCount(vector<double>& array, vector<double>& copy, int start, int end) {
	int count = 0;
	if (start == end) {
		copy[start] = array[start];
		return 0;
	}
	else {
		int mid = (start + end) >> 1;

		long long int leftCount = mergeCount(array, copy, start, mid);
		long long int rightCount = mergeCount(array, copy, mid + 1, end);

		int i = start;
		int j = mid + 1;
		int index = start;
		

		while ((i <= mid) && (j <= end)) {
			if (array[i] < array[j]) {
				copy[index] = array[i];
				i++;
				index++;
				count = count + end - j + 1;
			}
			else {
				copy[index] = array[j];
				index++;
				j++;
			}
		}
		for (; i < mid; i++) {
			copy[index] = array[i];
			index++;
		}
		for (; j < end; j++) {
			copy[index] = array[j];
			index++;
		}
		for (int s = start; s < end; s++) {
			array[s] = copy[s];
		}
		return leftCount + rightCount + count;
	}
}

int main() {
	int N;
	cin >> N;
	vector< vector<double> > input(N, vector<double>(2));
	for (int m = 0; m < N; m++) {
		for (int n = 0; n < 2; n++) {
			cin >> input[m][n];
		}
	}

	sort(input.begin(), input.end());
	vector<double> y(N);
	for (int k = 0; k < N; k++) {
		y[k] = input[k][1];
	}

	vector<double> copy(N);
	for (int r = 0; r < N; r++) {
		copy[r] = y[r];
	}
	cout << mergeCount(y, copy, 0, N - 1) << endl;

	return 0;
}
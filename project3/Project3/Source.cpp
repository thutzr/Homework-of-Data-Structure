//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//long long int mergeCount(vector<double>& array, vector<double>& copy, int start, int end) {
//	long long int count = 0;
//	if (start == end) {
//		copy[start] = array[start];
//		return 0;
//	}
//	else {
//		int mid = (start + end) >> 1;
//
//		long long int leftCount = mergeCount(array, copy, start, mid);
//		long long int rightCount = mergeCount(array, copy, mid + 1, end);
//
//		int i = start;
//		int j = mid + 1;
//		int index = start;
//		
//
//		while ((i <= mid) && (j <= end)) {
//			if (array[i] < array[j]) {
//				copy[index] = array[i];
//				i++;
//				index++;
//				count = count + end - j + 1;
//			}
//			else {
//				copy[index] = array[j];
//				index++;
//				j++;
//			}
//		}
//		for (; i < mid; i++) {
//			copy[index] = array[i];
//			index++;
//		}
//		for (; j < end; j++) {
//			copy[index] = array[j];
//			index++;
//		}
//		for (int s = start; s < end; s++) {
//			array[s] = copy[s];
//		}
//		return leftCount + rightCount + count;
//	}
//}
//
//int main() {
//	int N;
//	cin >> N;
//	vector< vector<double> > input(N, vector<double>(2));
//	for (int m = 0; m < N; m++) {
//		for (int n = 0; n < 2; n++) {
//			cin >> input[m][n];
//		}
//	}
//
//	sort(input.begin(), input.end());
//	vector<double> y(N);
//	for (int k = 0; k < N; k++) {
//		y[k] = input[k][1];
//		copy[r] = y[r];
//	}
//
//	vector<double> copy(N);
//	for (int r = 0; r < N; r++) {
//		
//	}
//	cout << mergeCount(y, copy, 0, N - 1) << endl;
//
//	return 0;
//}

#include<iostream>

using namespace std;

long long int count = 0;

void mergeSort(double *x, double *y, int start, int end)
{
	if ((end - start) > 1)
	{
		int mid = (start + end) >> 2, i = start, j = mid, num = 0;
		mergeSort(x, y, start, mid);
		mergeSort(x, y, mid, end);
		double copy[end - start][2];
		while ((i != mid) && (j != end))
		{
			if (x[i] < x[j])
			{
				copy[num][0] = x[i];
				copy[num][1] = y[i];
				i++;
				num++;
			}
			else
			{
				copy[num][0] = x[j];
				copy[num][1] = y[j];
				j++;
				num++;
			}
		}
		if (i == mid)
		{
			while (j != end)
			{
				copy[num][0] = x[j];
				copy[num][1] = y[j];
				j++;
				num++;
			}
		}
		else
		{
			while (i != mid)
			{
				copy[num][0] = x[i];
				copy[num][1] = y[i];
				i++;
				num++;
			}
		}
		for (int k = start; k < end; k++)
		{
			x[k] = copy[k - start][0];
			y[k] = copy[k - start][1];
		}
	}
}
void mergeCount(double *y, int start, int end)
{
	if ((end - start) > 1)
	{
		int mid = (start + end) >> 2, i = start, j = mid, num = 0;
		mergeCount(y, start, mid);
		mergeCount(y, mid, end);
		double copy[start - end];
		while ((i != mid) && (j != end))
		{
			if (y[i] < y[j])
			{
				copy[num] = y[i];
				count += num - (i - start);
				i++;
				num++;
			}
			else
			{
				copy[num++] = y[j++];
			}
		}
		if (i == mid)
		{
			while (j != end)
			{
				copy[num++] = y[j++];
			}
		}
		else
		{
			while (i != mid)
			{
				copy[num] = y[i];
				count += num - (i - start);
				i++;
				num++;
			}
		}
		for (int k = start; k < end; k++)
		{
			y[k] = copy[k - start];
		}
	}
}
int main()
{
	int n;
	cin >> n;
	double x[n], y[n];
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	mergeCount(x, y, 0, n);
	mergeCount(y, 0, n);
	long long int all = (long long int)(n - 1)*n >> 2;
	cout << all - count;
}
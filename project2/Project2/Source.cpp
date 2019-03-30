#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Vec {
public:
	int e1;
	int e2;
};

bool operator <(Vec v1, Vec v2) {
	if (v1.e1 < v2.e1) {
		return true;
	}
	else if (v1.e1 > v2.e1){
		return false;
	}
	else if (v1.e1 == v2.e1) {
		if (v1.e2 < v2.e2) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool operator >(Vec v1, Vec v2) {
	if (v1.e1 > v2.e1) {
		return true;
	}
	else if (v1.e1 < v2.e1) {
		return false;
	}
	else if (v1.e1 == v2.e1) {
		if (v1.e2 > v2.e2) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool operator ==(Vec v1, Vec v2) {
	if ((v1.e1 == v2.e1) && (v1.e2 == v2.e2)) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
	
	int N;
	cin >> N ;
	vector<Vec> input(N);
	Vec temp;
	for (int i = 0; i < N; i++){
		cin >> temp.e1;
		cin >> temp.e2;
		input[i] = temp;
}
	sort(input.begin(), input.end());
	input.erase(unique(input.begin(), input.end()), input.end());

	for (vector<Vec>::iterator it = input.begin(); it != input.end(); it++) {
		cout << (*it).e1 << " " << (*it).e2 << endl;
	}

}
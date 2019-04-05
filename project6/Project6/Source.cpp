#include <string>
#include <iostream>
#include <map>
using namespace std;

#define stacksize 100

struct stack
{
	char strStack[stacksize];
	int top;
};

void initStack(stack &s)
{
	s.top = -1;
}

char top(stack &s) {
	return s.strStack[s.top];
}

char push(stack &s, char a)
{
	if (s.top == stacksize - 1)
	{
		return 0;
	}
	s.top++;
	s.strStack[s.top] = a;
	return a;
}

char pop(stack &s)
{
	if (s.top == -1)
	{
		return 0;
	}
	char a = s.strStack[s.top];
	s.top--;
	return a;
}

int empty(stack &s,int result)
{
	if (s.top == -1)
	{
		result = 1;
		return result;
	}
	else
	{
		result = 0;
		return result;
	}
}

int main() {	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string in_str;
		cin >> in_str;
		stack s;
		initStack(s);
		bool flag = true;
		int len = in_str.length();
		int result = 0;
		for (int j = 0; j < len; j++) {
			switch (in_str[j]) {
			case '(':
				push(s, in_str[j]);
				break;
			case '{':
				push(s, in_str[j]);
				break;
			case '[':
				push(s, in_str[j]);
				break;
			case ')':
				if ((empty(s,result) == 1) || ('(' != pop(s))) {
					flag = false;
					break;
				}
				else {
					continue;
				}
			case '}':
				if ((empty(s,result) == 1) || ('{' != pop(s))) {
					flag = false;
					break;
				}
				else {
					continue;
				}
			case ']':
				if ((empty(s,result) == 1) || ('[' != pop(s))) {	
					flag = false;
					break;
				}
				else {
					continue;
				}
			}

			if (!flag) {
				break;
			}
		}

		if ((flag) && (result == 0)) {
			cout << 1 << endl;
		}
		else if (flag == false) {
			cout << 0 << endl;
		}
		else {
			cout << 1 << endl;
		}
	}
	system("pause");
}
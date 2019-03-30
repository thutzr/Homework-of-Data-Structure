#include <iostream> 
#include <map>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	int N; char input[3][3];
	char star = '*';
	char solution[8][3][3] = { { { '8','1','6' },{ '3','5','7' },{ '4','9','2' } },
{ { '6','1','8' },{ '7','5','3' },{ '2','9','4' } },
{ { '4','9','2' },{ '3','5','7' },{ '8','1','6' } },
{ { '2','9','4' },{ '7','5','3' },{ '6','1','8' } },
{ { '6','7','2' },{ '1','5','9' },{ '8','3','4' } },
{ { '8','3','4' },{ '1','5','9' },{ '6','7','2' } },
{ { '2','7','6' },{ '9','5','1' },{ '4','3','8' } },
{ { '4','3','8' },{ '9','5','1' },{ '2','7','6' } } };

	int flag;
	cin >> N;
	for (int n = 0; n < N; n++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> input[i][j];
			}
		}
		int result = 0;
		for (int t = 0; t < 8; ++t)
		{

			flag = 0;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if ((input[i][j] != star) && (input[i][j] != solution[t][i][j]))
					{
						flag = 1;
						break;
					}
					else {
						continue;
					}
				}
				if (flag == 1)
				{
					break;
				}
			}
			if (flag == 0)
			{
				result++;
			}
		}
		cout << result << endl;
	}
}
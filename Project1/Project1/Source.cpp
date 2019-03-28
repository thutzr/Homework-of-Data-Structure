#include <iostream> 
#include <map>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	int N; char input[3][3];
	char star = '*';
	char solution_1[3][3] = { { 8,1,6 },{ 3,5,7 },{ 4,9,2 } },
		solution_2[3][3] = { { 6,1,8 },{ 7,5,3 },{ 2,9,4 } },
		solution_3[3][3] = { { 4,9,2 },{ 3,5,7 },{ 8,1,6 } },
		solution_4[3][3] = { { 2,9,4 },{ 7,5,3 },{ 6,1,8 } },
		solution_5[3][3] = { { 6,7,2 },{ 1,5,9 },{ 8,3,4 } },
		solution_6[3][3] = { { 8,3,4 },{ 1,5,9 },{ 6,7,2 } },
		solution_7[3][3] = { { 2,7,6 },{ 9,5,1 },{ 4,3,8 } },
		solution_8[3][3] = { { 4,3,8 },{ 9,5,1 },{ 2,7,6 } };

	map<int, char[3][3]> solution_map;
	memcpy(solution_map[1], solution_1, sizeof(solution_1));
	memcpy(solution_map[2], solution_2, sizeof(solution_2));
	memcpy(solution_map[3], solution_3, sizeof(solution_3));
	memcpy(solution_map[4], solution_4, sizeof(solution_4));
	memcpy(solution_map[5], solution_5, sizeof(solution_5));
	memcpy(solution_map[6], solution_6, sizeof(solution_6));
	memcpy(solution_map[7], solution_7, sizeof(solution_7));
	memcpy(solution_map[8], solution_8, sizeof(solution_8));

	char solution[3][3];
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
		for (map<int, char[3][3]>::iterator it = solution_map.begin(); it != solution_map.end(); it++)
		{
			memcpy(solution, it->second, sizeof(it->second));

			for (int k1 = 0; k1 < 3; k1++)
			{
				for (int k2 = 0; k2 < 3; k2++)
				{
					solution[k1][k2] = solution[k1][k2] + '0';
				}
			}

			flag = 0;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if ((input[i][j] != star) && (input[i][j] != solution[i][j]))
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
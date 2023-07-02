#include<vector>
#include<string>

using namespace std;


/*
401. 二进制手表
*/
class Solution {
public:
	vector<string> readBinaryWatch(int turnedOn) {
		vector<string> res;
		char str[10];
		for (int i = 0; i < 1 << 10; i++)
		{
			int s = 0;
			for (int j = 0; j < 10; j++)
			{
				if (i >> j & 1)
					s++;
			}
			if (s == turnedOn)
			{
				int a = i >> 6, b = i & 63;
				if (a < 12 && b < 60)
				{
					sprintf(str, "%d:%02d", a, b);
					res.push_back(str);
				}
			}
		}
		return res;
	}
};
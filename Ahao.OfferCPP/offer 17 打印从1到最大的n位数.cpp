#include<vector>

using namespace std;



/*
offer 17 ��ӡ��1������nλ��
*/
class Solution {
public:
	vector<int> printNumbers(int n) {
		vector<int> res;
		int i = pow(10, n) - 1;
		for (int j = 1; j <= i; ++j)
		{
			res.push_back(j);
		}
		return res;
	}
};


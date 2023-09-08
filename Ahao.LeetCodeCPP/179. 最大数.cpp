#include<vector>
#include <string>
#include <algorithm>

using namespace std;

/*
179. �����

����һ��Ǹ����� nums����������ÿ������˳��ÿ�������ɲ�֣�ʹ֮���һ������������

ע�⣺���������ܷǳ�����������Ҫ����һ���ַ���������������
*/



class Solution {
	static bool cmp(const int& x, const int& y)
	{
		string a = to_string(x), b = to_string(y);
		return a + b > b + a;
	}
public:
	string largestNumber(vector<int>& nums) {
		string res;
		sort(nums.begin(), nums.end(), cmp);
		for (auto& num : nums)
		{
			res += to_string(num);
		}
		if (res[0] == '0')
			return "0";
		return res;
	}
};
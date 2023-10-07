#include<vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;



/*
128. ���������

����һ��δ������������� nums ���ҳ���������������У���Ҫ������Ԫ����ԭ�������������ĳ��ȡ�

������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(n) ���㷨��������⡣
*/
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int res = 0;
		unordered_map<int, int> tr_left, tr_right;
		for (auto x : nums)
		{
			int left = tr_right[x - 1];
			int right = tr_left[x + 1];
			tr_left[x - left] = max(tr_left[x - left], left + 1 + right);
			tr_right[x + right] = max(tr_right[x + right], left + 1 + right);
			res = max(res, left + 1 + right);
		}
		return res;
	}
};


class Solution {
public:
	/*
	Times:O(n)
	Space:O(n)
	*/
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> st(nums.begin(), nums.end());
		int res = 0;
		for (int num : nums)
		{
			if (!st.count(num - 1))
			{
				int x = num + 1;
				while (st.count(x))
					x++;
				res = max(res, x - num);
			}
		}
		return res;
	}
};
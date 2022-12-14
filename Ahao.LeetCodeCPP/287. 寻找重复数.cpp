#include<vector>

using namespace std;


/*
287. Ѱ���ظ���
����һ������ n + 1 ������������ nums �������ֶ��� [1, n] ��Χ�ڣ����� 1 �� n������֪���ٴ���һ���ظ���������

���� nums ֻ��һ���ظ������� ����������ظ����� ��

����ƵĽ���������벻�޸�����nums��ֻ�ó�����O(1)�Ķ���ռ䡣
*/
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int n = nums.size() - 1;
		int left = 1, right = n;
		while (left < right)
		{
			int mid = left + right >> 1;
			int cnt = 0;
			for (auto x : nums)
			{
				if (x >= 1 && x <= mid)
					cnt++;
			}
			if (cnt > mid - left + 1) right = mid;
			else left = mid + 1;
		}
		return right;
	}
};
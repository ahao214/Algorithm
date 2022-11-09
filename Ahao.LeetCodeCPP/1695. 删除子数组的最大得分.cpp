#include<vector>
#include <unordered_map>

using namespace std;


/*
1695. ɾ������������÷�
����һ������������ nums ���������ɾ��һ������ ���ɲ�ͬԪ�� �������顣ɾ��������� �÷� �����������Ԫ��֮ �� ��

���� ֻɾ��һ�� ������ɻ�õ� ���÷� ��

������� b ������ a ��һ�����������У������������ a[l],a[l+1],...,a[r] ����ô������ a ��һ�������顣
*/
class Solution {
public:
	int maximumUniqueSubarray(vector<int>& nums) {
		unordered_map<int, int> hash;
		int res = 0;
		for (int i = 0, j = 0, sum = 0; i < nums.size(); i++)
		{
			int x = nums[i];
			hash[x]++;
			sum += x;
			while (hash[x] > 1)
			{
				sum -= nums[j];
				hash[nums[j++]]--;
			}
			res = max(res, sum);
		}

		return res;
	}
};
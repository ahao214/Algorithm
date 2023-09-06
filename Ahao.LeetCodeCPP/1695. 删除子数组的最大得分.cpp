#include<vector>
#include <unordered_map>
#include <unordered_set>

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




class Solution {
public:
	int maximumUniqueSubarray(vector<int>& nums) {
		int res = 0, left = 0, sum = 0;
		unordered_set<int> st;
		for (int right = 0; right < nums.size(); right++)
		{
			while (st.count(nums[right]))
			{
				st.erase(nums[left]);
				sum -= nums[left];
				left++;
			}
			sum += nums[right];
			st.insert(nums[right]);
			res = max(res, sum);
		}
		return res;
	}
};

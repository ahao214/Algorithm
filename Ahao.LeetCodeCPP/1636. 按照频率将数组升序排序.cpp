#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;


/*
1636. ����Ƶ�ʽ�������������
*/
class Solution {
public:
	vector<int> frequencySort(vector<int>& nums) {
		unordered_map<int, int> dict;
		for (int n : nums)
		{
			dict[n]++;
		}
		sort(nums.begin(), nums.end(), [&](int a, int b) {
			if (dict[a] == dict[b])
			{
				return a > b;
			}
			return dict[a] < dict[b];
			});
		return nums;
	}
};
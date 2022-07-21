#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;


/*
1636. 按照频率将数组升序排序
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
using namespace std;
#include<string>;
#include<vector>;

class Solution {
public:
	/// <summary>
	/// ±©Á¦·½·¨
	/// </summary>
	/// <param name="nums"></param>
	/// <param name="target"></param>
	/// <returns></returns>
	vector<int> twoSum(vector<int>& nums, int target) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (nums[i] + nums[j] == target) {
					return { i,j };
				}
			}
		}
		return {};
	}
};
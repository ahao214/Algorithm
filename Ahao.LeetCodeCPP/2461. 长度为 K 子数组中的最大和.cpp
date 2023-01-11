#include<vector>
#include<unordered_map>


using namespace std;


/*
2461. ����Ϊ K �������е�����

����һ���������� nums ��һ������ k ������� nums ����������������ȫ�����������ҳ����������ͣ�

������ĳ����� k����
�������е�����Ԫ�� ������ͬ ��
������������Ҫ������������͡����������������������Щ���������� 0 ��

������ ��������һ�������ǿյ�Ԫ�����С�
*/
using LL = long long;
class Solution {
public:
	long long maximumSubarraySum(vector<int>& nums, int k) {
		LL sum = 0;
		LL result = 0;
		unordered_map<int, int> freq;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			freq[nums[i]]++;
			sum += nums[i];
			if (i >= k) {
				freq[nums[i - k]]--;
				if (freq[nums[i - k]] == 0) {
					freq.erase(nums[i - k]);
				}
				sum -= nums[i - k];
			}
			if (i >= k - 1) {
				if (freq.size() == k) {
					result = max(result, sum);
				}
			}
		}
		return result;
	}
};
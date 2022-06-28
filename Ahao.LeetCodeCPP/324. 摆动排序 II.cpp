#include<vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		int n = nums.size();
		vector<int> arr = nums;
		sort(arr.begin(), arr.end());
		int x = (n + 1) / 2;
		for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, j--, k--) {
			nums[i] = arr[j];
			if (i + 1 < n) {
				nums[i + 1] = arr[k];
			}
		}
	}
};


class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		int n = nums.size(), l = (n - 1) / 2, r = n - 1;
		vector<int> a = nums;
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0)
				nums[i] = a[l--];
			else
				nums[i] = a[r--];
		}
	}
};

using namespace std;
#include<vector>


/*
34. �����������в���Ԫ�صĵ�һ�������һ��λ��
����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�

��������в�����Ŀ��ֵ target������ [-1, -1]��
*/
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty()) return { -1,-1 };
		vector<int> ans(2);
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] >= target)
				r = mid;
			else
				l = mid + 1;
		}
		if (nums[l] != target) return { -1,-1 };
		ans[0] = l;

		l = 0, r = nums.size() - 1;
		while (l < r) {
			int mid = l + (r - l) / 2 + 1;
			if (nums[mid] <= target)
				l = mid;
			else
				r = mid - 1;
		}
		ans[1] = r;
		return ans;
	}
};



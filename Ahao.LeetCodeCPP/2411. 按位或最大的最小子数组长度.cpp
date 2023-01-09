#include<vector>

using namespace std;



/*
2411. ��λ��������С�����鳤��
����һ������Ϊ n �±�� 0 ��ʼ������ nums ���������������־�Ϊ�Ǹ����������� 0 �� n - 1 ֮���ÿһ���±� i ������Ҫ�ҳ� nums ��һ�� ��С �ǿ������飬������ʼλ��Ϊ i ���������λ�ã���ͬʱ�� ��� �� ��λ������ֵ ��

����֮���� Bij ��ʾ������ nums[i...j] �İ�λ������Ľ��������Ҫ�ҵ�һ����ʼλ��Ϊ i ����С�����飬���������İ�λ������Ľ������ max(Bik) ������ i <= k <= n - 1 ��
һ������İ�λ������ֵ������������������ְ�λ������Ľ����

���㷵��һ����СΪ n ���������� answer������ answer[i]�ǿ�ʼλ��Ϊ i ����λ������������� ��� ������ĳ��ȡ�

������ ��������һ�������ǿ�Ԫ����ɵ����С�
*/
class Solution {
public:
	vector<int> smallestSubarrays(vector<int>& nums) {
		int n = nums.size();
		int j = n - 1;

		vector<int> count(32, 0);
		vector<int>res(n);
		for (int i = n - 1; i >= 0; i--) {
			for (int k = 0; k < 32; k++) {
				count[k] += ((nums[i] >> k) & 1);
			}
			while (j > i && ok2remove(nums[j], count)) {
				for (int k = 0; k < 32; k++) {
					count[k] -= ((nums[j] >> k) & 1);
				}
				j--;
			}
			res[i] = j - i + 1;
		}
		return res;
	}

	bool ok2remove(int num, vector<int>& count) {
		for (int k = 0; k < 32; k++) {
			if (count[k] == 1 && ((num >> k) & 1))
				return false;
		}
		return true;
	}
};


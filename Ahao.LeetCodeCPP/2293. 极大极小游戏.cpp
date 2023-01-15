#include<vector>

using namespace std;

/*
2293. ����С��Ϸ
����һ���±�� 0 ��ʼ���������� nums ���䳤���� 2 ���ݡ�

�� nums ִ�������㷨��

�� n ���� nums �ĳ��ȣ���� n == 1 ����ֹ �㷨���̡����򣬴��� һ���µ��������� newNums �������鳤��Ϊ n / 2 ���±�� 0 ��ʼ��
�������� 0 <= i < n / 2 ��ÿ�� ż�� �±� i ���� newNums[i] ��ֵ Ϊ min(nums[2 * i], nums[2 * i + 1]) ��
�������� 0 <= i < n / 2 ��ÿ�� ���� �±� i ���� newNums[i] ��ֵ Ϊ max(nums[2 * i], nums[2 * i + 1]) ��
�� newNums �滻 nums ��
�Ӳ��� 1 ��ʼ �ظ� �������̡�
ִ���㷨�󣬷��� nums ��ʣ�µ��Ǹ����֡�
*/


class Solution {
public:
	int minMaxGame(vector<int>& nums) {
		int n = nums.size();
		if (n == 1) {
			return nums[0];
		}
		vector<int>newNums(n / 2);
		for (int i = 0; i < newNums.size(); i++) {
			if (i % 2 == 0) {
				newNums[i] = min(nums[2 * i], nums[2 * i + 1]);
			}
			else {
				newNums[i] = max(nums[2 * i], nums[2 * i + 1]);
			}
		}
		return minMaxGame(newNums);
	}
};



class Solution {
public:
	int minMaxGame(vector<int>& nums) {
		int n = nums.size();
		while (n != 1) {
			vector<int> newNums(n / 2);
			for (int i = 0; i < newNums.size(); i++) {
				if (i % 2 == 0) {
					newNums[i] = min(nums[2 * i], nums[2 * i + 1]);
				}
				else {
					newNums[i] = max(nums[2 * i], nums[2 * i + 1]);
				}
			}
			nums = newNums;
			n /= 2;
		}
		return nums[0];
	}
};

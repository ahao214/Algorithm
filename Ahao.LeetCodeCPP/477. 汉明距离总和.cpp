#include<vector>

using namespace std;


/*
477. ���������ܺ�

���������� �������� ָ�������������ֵĶ���������Ӧλ��ͬ��������
����һ���������� nums��������㲢����nums������������֮�人��������ܺ� ��
*/
class Solution {
public:
	int totalHammingDistance(vector<int>& nums) {
		int res = 0;
		for (int i = 0; i <= 30; i++) {
			int ones = 0;
			for (auto x : nums) {
				if (x >> i & 1)
					ones++;
			}
			res += ones * (nums.size() - ones);
		}
		return res;
	}
};



class Solution {
public:
	int totalHammingDistance(vector<int>& nums) {
		int res = 0;
		for (int i = 0; i <= 30; i++) {
			int ones = 0;
			for (auto x : nums) {
				if (x >> i & 1)
					ones++;
			}
			res += ones * (nums.size() - ones);
		}
		return res;
	}
};
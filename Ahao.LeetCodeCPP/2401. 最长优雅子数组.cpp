#include<vector>

using namespace std;


/*
2401. �����������
����һ���� �� ������ɵ����� nums ��

��� nums ����������λ�� ��ͬ λ�õ�ÿ��Ԫ�ذ�λ �루AND������Ľ������ 0 ����Ƹ�������Ϊ ���� �����顣
���� � ������������ĳ��ȡ�
������ �������е�һ�� ���� ���֡�
ע�⣺����Ϊ 1 ��������ʼ����������������
*/
class Solution {
public:
	int longestNiceSubarray(vector<int>& nums) {
		int res = 0;
		int count = 0;
		int j = 0;
		for (int i = 0; i < nums.size(); i++) {
			while (j < nums.size() && (count & nums[j]) == 0) {
				count += nums[j];
				j++;
			}
			res = max(res, j - i);
			count -= nums[i];
		}
		return res;
	}
};
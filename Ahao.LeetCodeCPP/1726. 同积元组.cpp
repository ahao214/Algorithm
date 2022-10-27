#include<vector>
#include<unordered_map>

using namespace std;


/*
1726. ͬ��Ԫ��
����һ���� ��ͬ ��������ɵ����� nums �����㷵������ a * b = c * d ��Ԫ�� (a, b, c, d) ������������ a��b��c �� d ���� nums �е�Ԫ�أ��� a != b != c != d ��
*/
class Solution {
public:
	int tupleSameProduct(vector<int>& nums) {
		int n = nums.size();
		//hash������¼ÿ�ֳ˻��ĸ���
		unordered_map<int, int> hash;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				hash[nums[i] * nums[j]]++;
			}
		}
		int res = 0;
		//p��ʾ�˻� k��ʾ����
		for (auto& [p, k] : hash)
		{
			res += k * (k - 1) / 2 * 8;
		}
		return res;
	}
};

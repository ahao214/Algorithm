#include<vector>

using namespace std;


/*
1752. ��������Ƿ��������ת�õ�
����һ������ nums ��nums ��Դ�����У�����Ԫ���� nums ��ͬ�������ǵݼ�˳�����С�

��� nums �ܹ���Դ������ת����λ�ã����� 0 ��λ�ã��õ����򷵻� true �����򣬷��� false ��

Դ�����п��ܴ��� �ظ��� ��

ע�⣺���ǳ����� A ����ת x ��λ�ú�õ�������ͬ������ B ������������ A[i] == B[(i+x) % A.length] ������ % Ϊȡ�����㡣
*/
class Solution {
public:
	bool check(vector<int>& nums) {
		auto b = nums;;
		sort(b.begin(), b.end());
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			if (nums == b) return true;
			int t = nums[0];
			for (int j = 1; j < n; j++)
				nums[j - 1] = nums[j];
			nums.back() = t;
		}
		return false;
	}
};



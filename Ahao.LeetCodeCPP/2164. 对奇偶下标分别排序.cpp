#include<vector>
#include <algorithm>

using namespace std;


/*
2164. ����ż�±�ֱ�����
��Ŀ�Ѷ�Easy
����һ���±�� 0 ��ʼ���������� nums ������������������ nums �е�ֵ��

�� �ǵ��� ˳������ nums �����±� �ϵ�����ֵ��
�ٸ����ӣ��������ǰ nums = [4,1,2,3] ���������±��ֵ������Ϊ [4,3,2,1] �������±� 1 �� 3 ��ֵ���շǵ���˳�����š�
�� �ǵݼ� ˳������ nums ż���±� �ϵ�����ֵ��
�ٸ����ӣ��������ǰ nums = [4,1,2,3] ����ż���±��ֵ������Ϊ [2,1,4,3] ��ż���±� 0 �� 2 ��ֵ���շǵݼ�˳�����š�
�������� nums ��ֵ֮���γɵ����顣
*/
class Solution {
public:
	vector<int> sortEvenOdd(vector<int>& a) {
		vector<int>x, y;
		for (int i = 0; i < a.size(); i++)
		{
			if (i % 2 == 0) x.push_back(a[i]);
			else y.push_back(a[i]);
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end(), greater<int>());

		vector<int>res;
		for (int i = 0; i < y.size(); i++)
		{
			res.push_back(x[i]);
			res.push_back(y[i]);
		}
		if (a.size() % 2 == 1) res.push_back(x.back());
		return res;
	}
};

class Solution {
public:
	vector<int> sortEvenOdd(vector<int>& nums) {
		vector<int> ans;
		vector<int> num1;
		vector<int> num2;
		int N = nums.size();
		for (int i = 0; i < N; i++) {
			if ((i & 1) == 0) {
				num1.push_back(nums[i]);
			}
			else {
				nums.push_back(nums[i]);
			}
		}
		sort(num1.begin(), num1.end());
		sort(num2.begin(), num2.end());
		reverse(num2.begin(), num2.end());
		for (int i = 0; i < N; i++) {
			if ((i & 1) == 0) {
				ans.push_back(num1[i / 2]);
			}
			else {
				ans.push_back(num2[i / 2]);
			}
		}
		return ans;
	}
};
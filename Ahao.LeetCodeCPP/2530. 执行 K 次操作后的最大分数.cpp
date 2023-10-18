#include<vector>
#include <queue>


using namespace std;


/*
2530. ִ�� K �β������������

����һ���±�� 0 ��ʼ���������� nums ��һ������ k ����� ��ʼ���� Ϊ 0 ��

��һ�� ���� �У�

ѡ��һ������ 0 <= i < nums.length ���±� i ��
����� ���� ���� nums[i] ������
�� nums[i] �滻Ϊ ceil(nums[i] / 3) ��
������ ǡ�� ִ�� k �β���������ܻ�õ���������

����ȡ������ ceil(val) �Ľ���Ǵ��ڻ���� val ����С������
*/


class Solution {
public:
	long long maxKelements(vector<int>& nums, int k) {
		priority_queue<int> q(nums.begin(), nums.end());
		long long ans = 0;
		for (int _ = 0; _ < k; ++_) {
			int x = q.top();
			q.pop();
			ans += x;
			q.push((x + 2) / 3);
		}
		return ans;
	}
};


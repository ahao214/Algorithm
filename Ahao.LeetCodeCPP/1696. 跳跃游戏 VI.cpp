#include<vector>
#include <deque>

using namespace std;


/*
1696. ��Ծ��Ϸ VI
����һ���±�� 0 ��ʼ���������� nums ��һ������ k ��

һ��ʼ�����±� 0 ����ÿһ��������������ǰ�� k �������㲻����������ı߽硣Ҳ����˵������Դ��±� i ���� [i + 1�� min(n - 1, i + k)] ���� �����˵������λ�á�

���Ŀ���ǵ����������һ��λ�ã��±�Ϊ n - 1 ������� �÷� Ϊ��������������֮�͡�

���㷵�����ܵõ��� ���÷� ��
*/
class Solution {
public:
	int maxResult(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> f(n);
		f[0] = nums[0];
		deque<int> q;
		q.push_back(0);
		for (int i = 1; i < n; i++)
		{
			while (q.front() < i - k) q.pop_front();
			f[i] = f[q.front()] + nums[i];
			while (q.size() && f[q.back()] <= f[i])
				q.pop_back();
			q.push_back(i);
		}
		return f[n - 1];
	}
};

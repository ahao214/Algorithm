#include<vector>


using namespace std;


/*
528. ��Ȩ�����ѡ��

����һ�� �±�� 0 ��ʼ ������������ w ������ w[i] ����� i ���±��Ȩ�ء�

����ʵ��һ������ pickIndex �������� ����� �ӷ�Χ [0, w.length - 1] �ڣ��� 0 �� w.length - 1��ѡ��������һ���±ꡣѡȡ�±� i �� ���� Ϊ w[i] / sum(w) ��

���磬���� w = [1, 3]����ѡ�±� 0 �ĸ���Ϊ 1 / (1 + 3) = 0.25 ������25%������ѡȡ�±� 1 �ĸ���Ϊ 3 / (1 + 3) = 0.75������75%����
*/
class Solution {
public:
	vector<int> s;
	Solution(vector<int>& w) {
		s = w;
		for (int i = 1; i < s.size(); i++)
			s[i] += s[i - 1];
	}

	int pickIndex() {
		int x = rand() % s.back() + 1;
		return lower_bound(s.begin(), s.end(), x) - s.begin();
	}
};

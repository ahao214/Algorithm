#include<vector>

using namespace std;


class Solution {
public:
	vector<int> constructArray(int n, int k) {
		vector<int> answer;
		for (int i = 1; i < n - k; ++i) {
			answer.push_back(i);
		}
		for (int i = n - k, j = n; i <= j; ++i, --j) {
			answer.push_back(i);
			if (i != j) {
				answer.push_back(j);
			}
		}
		return answer;
	}
};





/*
667. ���������� II

������������ n �� k �����㹹��һ�����б� answer �����б�Ӧ�������� 1 �� n �� n ����ͬ����������ͬʱ��������������

������б��� answer = [a1, a2, a3, ... , an] ����ô�б� [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] ��Ӧ�����ҽ��� k ����ͬ������
�����б� answer ��������ڶ��ִ𰸣�ֻ�践������ ����һ�� ��
*/
class Solution {
public:
	vector<int> constructArray(int n, int k) {
		vector<int> res(n);
		for (int i = 0; i < n - k - 1; i++)
			res[i] = i + 1;
		int u = n - k - 1;
		for (int i = n - k, j = n; u < n; i++, j--)
		{
			res[u++] = i;
			if (u < n)
				res[u++] = j;
		}
		return res;
	}
};

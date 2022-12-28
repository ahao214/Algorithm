#include<vector>
#include <string>
#include<set>

using namespace std;


/*
97. �����ַ���
���������ַ��� s1��s2��s3�������æ��֤ s3 �Ƿ����� s1 �� s2 ���� ��ɵġ�

�����ַ��� s �� t ���� �Ķ�����������£�����ÿ���ַ������ᱻ�ָ������ �ǿ� ���ַ�����

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
���� �� s1 + t1 + s2 + t2 + s3 + t3 + ... ���� t1 + s1 + t2 + s2 + t3 + s3 + ...
ע�⣺a + b ��ζ���ַ��� a �� b ���ӡ�
*/
class Solution {
public:
	bool res;
	set<vector<int>> visited;
	void backtracking(const string& s1, const string& s2, const string& s3, int i, int j, int k) {
		if (i == s1.size() && j == s2.size() && k == s3.size())
		{
			res = true;
			return;
		}
		if (visited.count({ i,j,k }))
			return;
		visited.insert({ i,j,k });
		if (s1[i] == s3[k])
			backtracking(s1, s2, s3, i + 1, j, k + 1);
		if (s2[j] == s3[k])
			backtracking(s1, s2, s3, i, j + 1, k + 1);
	}

	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size())
			return false;
		res = false;
		backtracking(s1, s2, s3, 0, 0, 0);
		return res;
	}
};

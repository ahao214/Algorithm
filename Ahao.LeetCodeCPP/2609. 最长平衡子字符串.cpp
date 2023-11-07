#include<vector>
#include<string>

using namespace std;

/*
2609. �ƽ�����ַ���

����һ������ 0 �� 1 ��ɵĶ������ַ��� s ��

������ַ����� ���е� 0 ���� 1 ֮ǰ ������ 0 ���������� 1 ������������Ϊ s ��������ַ�����ƽ�����ַ�������ע�⣬�����ַ���Ҳ����ƽ�����ַ�����

����  s �����ƽ�����ַ������ȡ�

���ַ������ַ����е�һ�������ַ����С�
*/


class Solution {
public:
	int findTheLongestBalancedSubstring(string s) {
		int res = 0, n = s.size();
		vector<int> count(2);
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				count[1]++;
				res = max(res, 2 * min(count[0], count[1]));
			}
			else if (i == 0 || s[i - 1] == '1') {
				count[0] = 1;
				count[1] = 0;
			}
			else {
				count[0]++;
			}
		}
		return res;
	}
};

#include<vector>
#include <string>
#include <unordered_set>

using namespace std;


/*
1456. �����Ӵ���Ԫ���������Ŀ
�����ַ��� s ������ k ��

�뷵���ַ��� s �г���Ϊ k �ĵ������ַ����п��ܰ��������Ԫ����ĸ����

Ӣ���е� Ԫ����ĸ Ϊ��a, e, i, o, u����
*/
class Solution {
public:
	int maxVowels(string s, int k) {
		int res = 0;
		unordered_set<char> S({ 'a','e','i','o','u' });
		for (int i = 0, cnt = 0; i < s.size(); i++)
		{
			cnt += S.count(s[i]);
			if (i >= k) cnt -= S.count(s[i - k]);
			if (i >= k - 1) res = max(res, cnt);
		}
		return res;
	}
};
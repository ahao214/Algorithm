#include<vector>
#include <string>
#include <unordered_set>

using namespace std;



/*
139. ���ʲ��
����һ���ַ��� s ��һ���ַ����б� wordDict ��Ϊ�ֵ䡣�����ж��Ƿ���������ֵ��г��ֵĵ���ƴ�ӳ� s ��

ע�⣺��Ҫ���ֵ��г��ֵĵ���ȫ����ʹ�ã������ֵ��еĵ��ʿ����ظ�ʹ�á�
*/
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> S;
		for (auto word : wordDict) S.insert(word);

		int n = s.size();
		vector<bool> f(n + 1, false);
		f[0] = true;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (S.count(s.substr(j, i - j)) && f[j] == true)
				{
					f[i] = true;
					break;
				}
			}
		}
		return f[n];
	}
};

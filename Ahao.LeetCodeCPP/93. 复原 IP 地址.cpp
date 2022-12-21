#include<vector>
#include <string>

using namespace std;



/*
93. ��ԭ IP ��ַ
��Ч IP ��ַ �������ĸ�������ÿ������λ�� 0 �� 255 ֮����ɣ��Ҳ��ܺ���ǰ�� 0��������֮���� '.' �ָ���

���磺"0.1.2.201" �� "192.168.1.1" �� ��Ч IP ��ַ������ "0.011.255.245"��"192.168.1.312" �� "192.168@1.1" �� ��Ч IP ��ַ��
����һ��ֻ�������ֵ��ַ��� s �����Ա�ʾһ�� IP ��ַ���������п��ܵ���Ч IP ��ַ����Щ��ַ����ͨ���� s �в��� '.' ���γɡ��� ���� ���������ɾ�� s �е��κ����֡�����԰� �κ� ˳�򷵻ش𰸡�
*/
class Solution {
public:
	vector<string> res;
	vector<string> restoreIpAddresses(string s) {
		string path;
		dfs(s, 0, 0, path);
		return res;
	}

	void dfs(string& s, int u, int k, string path)
	{
		if (u == s.size())
		{
			if (k == 4)
			{
				res.push_back(path.substr(1));
			}
			return;
		}
		if (k > 4) return;

		if (s[u] == '0')
			dfs(s, u + 1, k + 1, path + ".0");
		else
		{
			for (int i = u, t = 0; i < s.size(); i++)
			{
				t = t * 10 + s[i] - '0';
				if (t < 256) dfs(s, i + 1, k + 1, path + '.' + to_string(t));
				else break;
			}
		}
	}
};

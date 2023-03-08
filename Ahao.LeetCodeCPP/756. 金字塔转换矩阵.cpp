#include<vector>
#include <string>

using namespace std;



/*
756. ������ת������
���ڣ�������һЩ����������һ���������� ÿ�������ý�����һ����ĸ���ַ�����ʾ��

ʹ����Ԫ���ʾ�������Ķ����������£�

������Ԫ�� ABC ��C Ϊ���㷽�飬���� A ��B �ֱ���Ϊ���� C ��һ��ĵ������ӿ顣���ҽ��� ABC �Ǳ��������Ԫ�飬���ǲſ��Խ�������ϡ�

��ʼʱ�������������Ļ��� bottom����һ���ַ�����ʾ��һ���������Ԫ���б� allowed��ÿ����Ԫ����һ������Ϊ 3 ���ַ�����ʾ��

��������ɻ���һֱ�ѵ�����ͷ��� true �����򷵻� false ��
*/
class Solution {
public:
	vector<char> allows[7][7];
	bool pyramidTransition(string bottom, vector<string>& allowed) {
		for (auto allow : allowed)
		{
			int a = allow[0] - 'A', b = allow[1] - 'A', c = allow[2];
			allows[a][b].push_back(c);
		}
		return dfs(bottom, "");
	}

	bool dfs(string& last, string now)
	{
		if (last.size() == 1) return true;

		if (now.size() + 1 == last.size()) return dfs(now, "");
		int a = last[now.size()] - 'A', b = last[now.size() + 1] - 'A';
		for (auto c : allows[a][b])
		{
			if (dfs(last, now + c))
				return true;
		}
		return false;
	}
};





class Solution {
public:
	vector<char> g[7][7];

	bool pyramidTransition(string bottom, vector<string>& allowed) {
		for (auto& e : allowed)
			g[e[0] - 'A'][e[1] - 'A'].push_back(e[2]);
		return dfs(bottom, "", 0);
	}

	bool dfs(string bottom, string cur, int u)
	{
		if (bottom.size() == 1)
			return true;
		if (u == bottom.size() - 1)
			return dfs(cur, "", 0);
		for (auto c : g[bottom[u] - 'A'][bottom[u + 1] - 'A'])
		{
			if (dfs(bottom, cur + c, u + 1))
				return true;
		}
		return false;
	}
};


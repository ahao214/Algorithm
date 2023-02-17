#include<vector>
#include <string>

using namespace std;



/*
839. �����ַ�����

��������ַ��� X �е�������ͬλ�õ���ĸ��ʹ�������ַ��� Y ��ȣ���ô�� X �� Y �����ַ������ơ�����������ַ�����������ȵģ�������Ҳ�����Ƶġ�

���磬"tars" �� "rats" �����Ƶ� (���� 0 �� 2 ��λ��)�� "rats" �� "arts" Ҳ�����Ƶģ����� "star" ���� "tars"��"rats"���� "arts" ���ơ�

��֮������ͨ���������γ������������飺{"tars", "rats", "arts"} �� {"star"}��ע�⣬"tars" �� "arts" ����ͬһ���У���ʹ���ǲ������ơ���ʽ�ϣ���ÿ������ԣ�Ҫȷ��һ�����������У�ֻ��Ҫ����ʺ͸���������һ���������ơ�

����һ���ַ����б� strs���б��е�ÿ���ַ������� strs �����������ַ�����һ����ĸ��λ�ʡ����� strs ���ж��ٸ������ַ����飿



ʾ�� 1��

���룺strs = ["tars","rats","arts","star"]
�����2
ʾ�� 2��

���룺strs = ["omv","ovm"]
�����1


��ʾ��

1 <= strs.length <= 300
1 <= strs[i].length <= 300
strs[i] ֻ����Сд��ĸ��
strs �е����е��ʶ�������ͬ�ĳ��ȣ����Ǳ˴˵���ĸ��λ�ʡ�
*/
class Solution {
public:
	int n;
	vector<int> p;
	int find(int x)
	{
		if (p[x] != x) p[x] = find(p[x]);
		return p[x];
	}

	bool check(string& a, string& b)
	{
		if (a == b)return true;
		vector<int> q;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] != b[i])
				q.push_back(i);
		}
		if (q.size() != 2) return false;
		int x = q[0], y = q[1];
		return a[x] == b[y] && a[y] == b[x];
	}

	int numSimilarGroups(vector<string>& strs) {
		n = strs.size();
		p.resize(n);
		for (int i = 0; i < n; i++) p[i] = i;

		int res = n;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (check(strs[i], strs[j]))
				{
					if (find(i) != find(j))
					{
						p[find(i)] = find(j);
						res--;
					}
				}
			}
		}
		return res;
	}
};


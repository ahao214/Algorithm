#include<vector>
#include<unordered_map>
using namespace std;


/*
1791. �ҳ�����ͼ�����Ľڵ�
��һ������� ���� ͼ���� n ����Ŵ� 1 �� n �Ľڵ���ɡ�����ͼ��һ�� ���� �ڵ㣬����ǡ�� n - 1 ���߽����Ľڵ�������ÿ���ڵ�����������

����һ����ά�������� edges ������ edges[i] = [ui, vi] ��ʾ�ڽڵ� ui �� vi ֮�����һ���ߡ������ҳ������� edges ����ʾ����ͼ�����Ľڵ㡣
*/
class Solution {
public:
	int findCenter(vector<vector<int>>& edges) {
		unordered_map<int, int> mp;
		for (auto& e : edges)
		{
			int a = e[0], b = e[1];
			if (++mp[a] > 1) return a;
			if (++mp[b] > 1) return b;
		}
		return -1;
	}
};

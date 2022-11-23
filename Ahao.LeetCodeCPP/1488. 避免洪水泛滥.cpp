#include<vector>
#include <queue>
#include <unordered_map>

using namespace std;


/*
1488. �����ˮ����
��Ĺ��������������������к���һ��ʼ���ǿյġ����� n �����������ʱ������� n �������ǿյģ���ô���ͻ�װ��ˮ��������������ᷢ����ˮ�����Ŀ���Ǳ�������һ������������ˮ��

����һ���������� rains �����У�

rains[i] > 0 ��ʾ�� i ��ʱ���� rains[i] �����������ꡣ
rains[i] == 0 ��ʾ�� i ��û�к��������꣬�����ѡ�� һ�� ������ ��� ���������ˮ��
�뷵��һ������ ans �����㣺

ans.length == rains.length
��� rains[i] > 0 ����ôans[i] == -1 ��
��� rains[i] == 0 ��ans[i] ����� i ��ѡ���ɵĺ�����
����ж��ֿ��н⣬�뷵�������е� ����һ�� �����û�취��ֹ��ˮ���뷵��һ�� �յ����� ��

��ע�⣬�����ѡ����һ��װ��ˮ�ĺ�����������һ���յĺ������������ѡ����һ���յĺ�������ô�����·����������뿴ʾ�� 4����
*/
class Solution {
public:
	vector<int> avoidFlood(vector<int>& rains) {
		int n = rains.size();
		vector<int> next(n, n + 1);
		unordered_map<int, int> tm;
		for (int i = n - 1; i >= 0; i--)
		{
			int r = rains[i];
			if (r)
			{
				if (tm.count(r)) next[i] = tm[r];
				tm[r] = i;
			}
		}

		typedef pair<int, int> PII;
		priority_queue<PII, vector<PII>, greater<PII>> heap;
		unordered_map<int, bool> st;

		vector<int> res;
		for (int i = 0; i < n; i++)
		{
			int r = rains[i];
			if (r)
			{
				if (st[r]) return {};
				st[r] = true;
				heap.push({ next[i],r });
				res.push_back(-1);
			}
			else {
				if (heap.empty()) res.push_back(1);
				else {
					auto t = heap.top();
					heap.pop();
					st[t.second] = false;
					res.push_back(t.second);
				}
			}
		}
		return res;
	}
};
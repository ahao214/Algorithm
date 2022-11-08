#include<vector>
#include <queue>

using namespace std;



/*
1705. ��ƻ���������Ŀ
��һ�������ƻ������һ�� n �죬ÿ�춼���Գ������ɸ�ƻ�����ڵ� i �죬���ϻ᳤�� apples[i] ��ƻ������Щƻ�������� days[i] ���Ҳ����˵���� i + days[i] ��ʱ�����ã�����޷�ʳ�á�Ҳ��������ô���죬���ϲ��᳤���µ�ƻ������ʱ�� apples[i] == 0 �� days[i] == 0 ��ʾ��

�����ÿ�� ��� ��һ��ƻ������֤Ӫ�����⡣ע�⣬��������� n ��֮�������ƻ����

������������Ϊ n ���������� days �� apples ����������ԳԵ���ƻ���������Ŀ��
*/
class Solution {
public:
	int eatenApples(vector<int>& apples, vector<int>& days) {
		typedef pair<int, int> PII;
		//С����
		priority_queue<PII, vector<PII>, greater<PII>> heap;
		int res = 0;
		int n = apples.size();
		for (int i = 0; i <= 40000; i++)
		{
			if (i < n && apples[i] > 0)
			{
				heap.push({ i + days[i] - 1,apples[i] });
			}
			while (heap.size() && heap.top().first < i) heap.pop();
			if (heap.empty()) continue;
			auto t = heap.top();
			heap.pop();
			res++;
			if (--t.second)
			{
				heap.push(t);
			}
		}
		return res;
	}
};
#include<vector>
#include <queue>

using namespace std;


/*
871. ��ͼ��ʹ���

������������ʻ��Ŀ�ĵأ���Ŀ�ĵ�λ�ڳ���λ�ö��� target Ӣ�ﴦ��

��;�м���վ��ÿ�� station[i] ����һ������վ����λ�ڳ���λ�ö��� station[i][0] Ӣ�ﴦ�������� station[i][1] �����͡�

����������������������޵ģ���������� startFuel ��ȼ�ϡ���ÿ��ʻ 1 Ӣ��ͻ��õ� 1 �����͡�

�������������վʱ��������ͣ�������ͣ����������ʹӼ���վת�Ƶ������С�

Ϊ�˵���Ŀ�ĵأ���������Ҫ����ͼ��ʹ����Ƕ��٣�����޷�����Ŀ�ĵأ��򷵻� -1 ��

ע�⣺��������������վʱʣ��ȼ��Ϊ 0������Ȼ������������͡������������Ŀ�ĵ�ʱʣ��ȼ��Ϊ 0����Ȼ��Ϊ���Ѿ�����Ŀ�ĵء�
*/
class Solution {
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
		stations.push_back({ target,0 });
		priority_queue<int> heap;
		int res = 0;
		for (auto& p : stations)
		{
			int x = p[0], y = p[1];
			while (heap.size() && startFuel < x)
			{
				startFuel += heap.top();
				heap.pop();
				res++;
			}
			if (startFuel < x) return -1;
			heap.push(y);
		}
		return res;
	}
};

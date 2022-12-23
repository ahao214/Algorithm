#include<vector>

using namespace std;


/*
134. ����վ
��һ����·���� n ������վ�����е� i ������վ������ gas[i] ����

����һ�������������޵ĵ��������ӵ� i ������վ������ i+1 ������վ��Ҫ�������� cost[i] ����������е�һ������վ��������ʼʱ����Ϊ�ա�

����������������gas��cost �����������ƻ�·��ʻһ�ܣ��򷵻س���ʱ����վ�ı�ţ����򷵻� -1 ������ڽ⣬��֤����Ψһ�ġ�
*/
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		for (int i = 0, j; i < n; i += j + 1)
		{
			int gas_left = 0;
			for (j = 0; j < n; j++)
			{
				int k = (i + j) % n;
				gas_left += gas[k] - cost[k];
				if (gas_left < 0)
					break;
			}
			if (j >= n) return i;
		}
		return -1;
	}
};
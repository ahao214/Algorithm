#include<vector>

using namespace std;



/*
121. ������Ʊ�����ʱ��

����һ������ prices �����ĵ� i ��Ԫ�� prices[i] ��ʾһ֧������Ʊ�� i ��ļ۸�

��ֻ��ѡ�� ĳһ�� ������ֻ��Ʊ����ѡ���� δ����ĳһ����ͬ������ �����ù�Ʊ�����һ���㷨�����������ܻ�ȡ���������

��������Դ���ʽ����л�ȡ�������������㲻�ܻ�ȡ�κ����󣬷��� 0 ��
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int minPrice = INT_MIN;
		int profit = 0;
		for (auto p : prices) {
			if (p < minPrice) {
				minPrice = p;
			}
			else {
				profit = max(profit, p - minPrice);
			}
		}
		return profit;
	}
};




class Solution {
public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	int maxProfit(vector<int>& prices) {
		int ans = 0, minPrice = prices[0];
		for (int i = 1; i < prices.size(); i++)
		{
			ans = max(ans, prices[i] - minPrice);
			minPrice = min(minPrice, prices[i]);
		}
		return ans;
	}
};

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
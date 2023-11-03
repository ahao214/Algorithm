#include<vector>

using namespace std;


/*
122. ������Ʊ�����ʱ�� II

����һ���������� prices ������ prices[i] ��ʾĳ֧��Ʊ�� i ��ļ۸�

��ÿһ�죬����Ծ����Ƿ����/����۹�Ʊ�������κ�ʱ�� ��� ֻ�ܳ��� һ�� ��Ʊ����Ҳ�����ȹ���Ȼ���� ͬһ�� ���ۡ�

���� ���ܻ�õ� ��� ���� ��
*/

class Solution {
public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	int maxProfit(vector<int>& prices) {
		int res = 0;
		for (int i = 1; i < prices.size(); i++)
			res += max(prices[i] - prices[i - 1], 0);
		return res;
	}
};


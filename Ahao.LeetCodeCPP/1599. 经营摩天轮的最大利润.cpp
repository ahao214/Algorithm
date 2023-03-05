#include<vector>

using namespace std;


/*
1599. ��ӪĦ���ֵ��������

�����ھ�Ӫһ��Ħ���֣���Ħ���ֹ��� 4 ������ ��ÿ������ ���������� 4 λ�ο� ������� ��ʱ�� ��ת���գ���ÿ����ת����Ҫ֧��һ�������гɱ� runningCost ��Ħ����ÿ����ת��ǡ��ת�� 1 / 4 �ܡ�

����һ������Ϊ n ������ customers �� customers[i] ���ڵ� i ����ת���±�� 0 ��ʼ��֮ǰ��������ο͵���������Ҳ��ζ������������ο͵���ǰ��ת i �Ρ�ÿλ�ο��ڵ�����������������ǰ����֧���ǲճɱ� boardingCost ��һ���������ٴεִ���棬���Ǿͻ��뿪���ս������档

�������ʱͣ��Ħ���֣������� �ڷ��������ο�֮ǰ ����������ֹͣ��ӪĦ���֣�Ϊ�˱�֤�����οͰ�ȫ��½������ѽ������к�����ת ��ע�⣬����г��� 4 λ�ο��ڵ�Ħ���֣���ôֻ�� 4 λ�οͿ��Ե���Ħ���֣��������Ҫ�ȴ� ��һ����ת ��

���������������ִ�е� ��С��ת���� �� �������������Ϊ���ķ������򷵻� -1 ��
*/


class Solution {
public:
	int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
		int ans = -1;
		int maxProfit = 0;
		int totalProfit = 0;
		int operations = 0;
		int customersCount = 0;
		int n = customers.size();
		for (int i = 0; i < n; i++) {
			operations++;
			customersCount += customers[i];
			int curCustomers = min(customersCount, 4);
			customersCount -= curCustomers;
			totalProfit += boardingCost * curCustomers - runningCost;
			if (totalProfit > maxProfit) {
				maxProfit = totalProfit;
				ans = operations;
			}
		}
		if (customersCount == 0) {
			return ans;
		}
		int profitEachTime = boardingCost * 4 - runningCost;
		if (profitEachTime <= 0) {
			return ans;
		}
		if (customersCount > 0) {
			int fullTimes = customersCount / 4;
			totalProfit += profitEachTime * fullTimes;
			operations += fullTimes;
			if (totalProfit > maxProfit) {
				maxProfit = totalProfit;
				ans = operations;
			}
			int remainingCustomers = customersCount % 4;
			int remainingProfit = boardingCost * remainingCustomers - runningCost;
			totalProfit += remainingProfit;
			if (totalProfit > maxProfit) {
				maxProfit = totalProfit;
				operations++;
				ans++;
			}
		}
		return ans;
	}
};

#include<vector>
#include <queue>

using namespace std;

/*
1801. ��ѹ�����еĶ�������

����һ����ά�������� orders ������ÿ�� orders[i] = [pricei, amounti, orderTypei] ��ʾ�� amounti ������Ϊ orderTypei ���۸�Ϊ pricei �Ķ�����

�������� orderTypei ���Է�Ϊ���֣�

0 ��ʾ����һ���ɹ����� buy
1 ��ʾ����һ�����۶��� sell
ע�⣬orders[i] ��ʾһ������ amounti �ʵĶ�����������Щ�����ļ۸��������ͬ������������Ч�� i ���� orders[i] ��ʾ�����ж����ύʱ������� orders[i+1] ��ʾ�����ж�����

������δִ�ж�����ɵ� ��ѹ���� ����ѹ��������ǿյġ��ύ����ʱ���ᷢ�����������

����ö�����һ�ʲɹ����� buy ������Բ鿴��ѹ�����м۸� ��� �����۶��� sell ����������۶��� sell �ļ۸� ���ڻ���� ��ǰ�ɹ����� buy �ļ۸���ƥ�䲢ִ�������ʶ������������۶��� sell �ӻ�ѹ������ɾ�������򣬲ɹ����� buy ������ӵ���ѹ�����С�
��֮��Ȼ������ö�����һ�����۶��� sell ������Բ鿴��ѹ�����м۸� ��� �Ĳɹ����� buy ������òɹ����� buy �ļ۸� ���ڻ���� ��ǰ���۶��� sell �ļ۸���ƥ�䲢ִ�������ʶ����������ɹ����� buy �ӻ�ѹ������ɾ�����������۶��� sell ������ӵ���ѹ�����С�
�������ж����󣬷��ػ�ѹ�����е� �������� ���������ֿ��ܴܺ�������Ҫ���ض� 109 + 7 ȡ��Ľ����
*/

class Solution {
public:
	int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
		const int MOD = 1000000007;
		priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> buyOrders;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sellOrders;
		for (auto&& order : orders) {
			int price = order[0], amount = order[1], orderType = order[2];
			if (orderType == 0) {
				while (amount > 0 && !sellOrders.empty() && sellOrders.top().first <= price) {
					auto sellOrder = sellOrders.top();
					sellOrders.pop();
					int sellAmount = min(amount, sellOrder.second);
					amount -= sellAmount;
					sellOrder.second -= sellAmount;
					if (sellOrder.second > 0) {
						sellOrders.push(sellOrder);
					}
				}
				if (amount > 0) {
					buyOrders.emplace(price, amount);
				}
			}
			else {
				while (amount > 0 && !buyOrders.empty() && buyOrders.top().first >= price) {
					auto buyOrder = buyOrders.top();
					buyOrders.pop();
					int buyAmount = min(amount, buyOrder.second);
					amount -= buyAmount;
					buyOrder.second -= buyAmount;
					if (buyOrder.second > 0) {
						buyOrders.push(buyOrder);
					}
				}
				if (amount > 0) {
					sellOrders.emplace(price, amount);
				}
			}
		}
		int total = 0;
		while (!buyOrders.empty()) {
			total = (total + buyOrders.top().second) % MOD;
			buyOrders.pop();
		}
		while (!sellOrders.empty()) {
			total = (total + sellOrders.top().second) % MOD;
			sellOrders.pop();
		}
		return total;
	}
};


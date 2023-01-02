#include<vector>
#include <queue>

using namespace std;

/*
1801. 积压订单中的订单总数

给你一个二维整数数组 orders ，其中每个 orders[i] = [pricei, amounti, orderTypei] 表示有 amounti 笔类型为 orderTypei 、价格为 pricei 的订单。

订单类型 orderTypei 可以分为两种：

0 表示这是一批采购订单 buy
1 表示这是一批销售订单 sell
注意，orders[i] 表示一批共计 amounti 笔的独立订单，这些订单的价格和类型相同。对于所有有效的 i ，由 orders[i] 表示的所有订单提交时间均早于 orders[i+1] 表示的所有订单。

存在由未执行订单组成的 积压订单 。积压订单最初是空的。提交订单时，会发生以下情况：

如果该订单是一笔采购订单 buy ，则可以查看积压订单中价格 最低 的销售订单 sell 。如果该销售订单 sell 的价格 低于或等于 当前采购订单 buy 的价格，则匹配并执行这两笔订单，并将销售订单 sell 从积压订单中删除。否则，采购订单 buy 将会添加到积压订单中。
反之亦然，如果该订单是一笔销售订单 sell ，则可以查看积压订单中价格 最高 的采购订单 buy 。如果该采购订单 buy 的价格 高于或等于 当前销售订单 sell 的价格，则匹配并执行这两笔订单，并将采购订单 buy 从积压订单中删除。否则，销售订单 sell 将会添加到积压订单中。
输入所有订单后，返回积压订单中的 订单总数 。由于数字可能很大，所以需要返回对 109 + 7 取余的结果。
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


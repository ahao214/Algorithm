#include<vector>
#include <map>

using namespace std;


/*
860. 柠檬水找零
在柠檬水摊上，每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。

每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。

注意，一开始你手头没有任何零钱。

给你一个整数数组 bills ，其中 bills[i] 是第 i 位顾客付的账。如果你能给每位顾客正确找零，返回 true ，否则返回 false 。
*/
class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		int fives = 0, tens = 0;
		for (auto b : bills) {
			if (b == 5)
			{
				fives++;
			}
			else if (b == 10)
			{
				if (fives) fives--;
				else return false;
				tens++;
			}
			else
			{
				int t = 15;
				if (tens)
				{
					t -= 10;
					tens--;
				}
				while (t && fives)
				{
					t -= 5;
					fives--;
				}
				if (t) return false;
			}
		}
		return true;
	}

	bool lemonadeChange(vector<int>& bills) {
		map<int, int> cash;
		for (auto b : bills)
		{
			if (b == 5)
			{
				cash[b]++;
			}
			else if (b == 10)
			{
				if (cash[5] > 0)
				{
					cash[5]--;
					cash[10]++;
				}
				else
				{
					return false;
				}
			}
			else if (b == 20)
			{
				if (cash[10] > 0 && cash[5] > 0)
				{
					cash[10]--;
					cash[5]--;
				}
				else if (cash[10] == 0 && cash[5] > 2)
				{
					cash[5] -= 3;
				}
				else
				{
					return false;
				}
			}
		}
		return true;
	}
};
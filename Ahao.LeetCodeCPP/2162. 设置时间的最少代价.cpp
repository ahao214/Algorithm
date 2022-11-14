#include<vector>

using namespace std;



/*
2162. ����ʱ������ٴ���
������΢��¯�������ü���ʱ�䣬�Ҽ���ʱ����������������

����Ϊ 1 ���ӡ�
����Ϊ 99 �� 99 �롣
����� ��� ���� 4 ������ �����ü���ʱ�䡣����������λ������ 4 λ��΢��¯���Զ��� ǰ׺ 0 ������ 4 λ��΢��¯�Ὣ���úõ���λ���У�ǰ ��λ�������������� ��λ������������������ʾ����ʱ����Ǽ���ʱ�䡣�ȷ�˵��

������ 9 5 4 ���������֣������Զ�����Ϊ 0954 ������ʾ 9 �� 54 �롣
������ 0 0 0 8 ���ĸ����֣�����ʾ 0 �� 8 �롣
������ 8 0 9 0 ����ʾ 80 �� 90 �롣
������ 8 1 3 0 ����ʾ 81 �� 30 �롣
�������� startAt ��moveCost ��pushCost �� targetSeconds ��һ��ʼ�������ָ������ startAt ��������ָ�Ƶ� �κ��������� ����Ҫ���� moveCost �ĵ�λ���ۡ�ÿ ��������ָ����λ�õ�����һ�Σ���Ҫ���� pushCost �ĵ�λ���ۡ�

Ҫ���� targetSeconds ��ļ���ʱ�䣬���ܻ��ж������÷���������Ҫ֪����Щ�����У��ܴ�����СΪ���١�

�����ܷ������� targetSeconds ���Ӽ���ʱ����Ҫ���ѵ����ٴ��ۡ�

���ס����Ȼ΢��¯���������������õ� 99 �룬��һ���ӵ��� 60 �롣
*/
class Solution {
public:
	void getData(int mini, int sec, vector<int>& vData) {
		vData.push_back(sec % 10);
		sec /= 10;
		vData.push_back(sec % 10);
		vData.push_back(mini % 10);
		mini /= 10;
		vData.push_back(mini % 10);
		while (vData.back() == 0) {
			vData.pop_back();
		}
		reverse(vData.begin(), vData.end());
	}

	int slove(int startAt, int moveCost, int pushCost, int mini, int sec) {
		vector<int> vData;
		getData(mini, sec, vData);
		int at = startAt;
		int res = 0;
		for (auto x : vData) {
			if (at != x) {
				at = x;
				res += moveCost;
			}
			res += pushCost;
		}
		return res;
	}

	int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
		int mini = targetSeconds / 60;
		int sec = targetSeconds % 60;

		if (mini >= 100) {
			sec += 60;
			mini--;
		}

		int ans = slove(startAt, moveCost, pushCost, mini, sec);

		if (mini >= 1 && sec < 40) {
			sec += 60;
			mini--;
			int ans1 = slove(startAt, moveCost, pushCost, mini, sec);
			ans = min(ans, ans1);
		}
		return ans;
	}
};



class Solution {
public:
	int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
		int ans = 4 * (moveCost + pushCost);

		for (int s = 0; s <= 9999; s += 1) {
			int mi = s / 100, sec = s % 100;
			if (mi * 60 + sec == targetSeconds) {
				int cur = 0;
				int v[4], x = s, last = startAt;
				for (int i = 0; i < 4; i++) {
					v[i] = x % 10, x /= 10;
				}
				reverse(v, v + 4);
				bool flag = false;
				for (int i = 0; i < 4; i++) {
					if (v[i] == 0 && flag == false) continue;
					flag = true;
					if (last == v[i]) {
						cur += pushCost;
					}
					else {
						cur += moveCost + pushCost;
						last = v[i];
					}
				}
				ans = min(ans, cur);
			}
		}
		return ans;
	}
};
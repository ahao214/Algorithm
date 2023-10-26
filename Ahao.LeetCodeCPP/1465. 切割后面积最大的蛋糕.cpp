#include<vector>
#include <algorithm>

using namespace std;


/*
1465. �и��������ĵ���

���ε���ĸ߶�Ϊ h �ҿ��Ϊ w������������������ horizontalCuts �� verticalCuts������ horizontalCuts[i] �ǴӾ��ε��ⶥ������  i ��ˮƽ�пڵľ��룬���Ƶأ� verticalCuts[j] �ǴӾ��ε������ൽ�� j ����ֱ�пڵľ��롣

���㰴���� horizontalCuts �� verticalCuts ���ṩ��ˮƽ����ֱλ���и�������ҳ� ������ ���Ƿݵ��⣬�������� ��� �����ڴ𰸿�����һ���ܴ�����֣������Ҫ������� 10^9 + 7 ȡ��󷵻ء�
*/
class Solution {
public:
	//�ҵ�����������ֵ�ͺ᷽������ֵ
	//�������
	int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
		//���߽���뵽��������
		horizontalCuts.push_back(0), horizontalCuts.push_back(h);
		verticalCuts.push_back(0), verticalCuts.push_back(w);

		sort(horizontalCuts.begin(), horizontalCuts.end());
		sort(verticalCuts.begin(), verticalCuts.end());

		int x = 0, y = 0;
		for (int i = 1; i < horizontalCuts.size(); i++)
			x = max(x, horizontalCuts[i] - horizontalCuts[i - 1]);
		for (int j = 1; j < verticalCuts.size(); j++)
			y = max(y, verticalCuts[j] - verticalCuts[j - 1]);

		return (long long)x * y % 1000000007;
	}
};


class Solution {
public:
	int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
		int mod = 1e9 + 7;
		sort(horizontalCuts.begin(), horizontalCuts.end());
		sort(verticalCuts.begin(), verticalCuts.end());
		auto calMax = [](vector<int>& arr, int boardr) -> int {
			int res = 0, pre = 0;
			for (int i : arr) {
				res = max(i - pre, res);
				pre = i;
			}
			return max(res, boardr - pre);
		};
		return (long long)calMax(horizontalCuts, h) * calMax(verticalCuts, w) % mod;
	}
};


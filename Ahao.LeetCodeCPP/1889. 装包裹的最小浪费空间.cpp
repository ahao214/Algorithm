#include<vector>
#include<algorithm>
#include <numeric>

using namespace std;


/*
1889. װ��������С�˷ѿռ�
���� n ������������Ҫ������װ�������ÿ������װһ���������ܹ��� m ����Ӧ���ṩ ��ͬ�ߴ� �����ӣ�ÿ����������������ӣ������һ�������ĳߴ� С�ڵ��� һ�����ӵĳߴ磬��ô��������Ϳ��Է����������֮�С�

�����ĳߴ���һ���������� packages ��ʾ������ packages[i] �ǵ� i �������ĳߴ硣��Ӧ���ö�ά���� boxes ��ʾ������ boxes[j] �ǵ� j ����Ӧ���ṩ���������ӳߴ�����顣

����Ҫѡ�� һ����Ӧ�� ��ֻʹ�øù�Ӧ���ṩ�����ӣ�ʹ�� ���˷ѿռ���С ������ÿ��װ�˰��������ӣ����Ƕ��� �˷ѵ� �ռ���� ���ӵĳߴ� - �����ĳߴ� �����˷ѿռ� Ϊ ���� �������˷ѿռ���ܺ͡�

�ȷ�˵���������Ҫ�óߴ�����Ϊ [4,8] ������װ�³ߴ�Ϊ [2,3,5] �İ���������Խ��ߴ�Ϊ 2 �� 3 ����������װ�������ߴ�Ϊ 4 �������У�ͬʱ�ѳߴ�Ϊ 5 �İ���װ��ߴ�Ϊ 8 �������С����˷ѿռ�Ϊ (4-2) + (4-3) + (8-5) = 6 ��
����ѡ�� ���� ���ӹ�Ӧ�̣�ʹ�� ���˷ѿռ���С ����� �޷� �����а������������У����㷵�� -1 �����ڴ𰸿��ܻ� �ܴ� ���뷵������ 109 + 7 ȡ�� �Ľ����
*/

typedef long long LL;
const LL MOD = 1e9 + 7, INF = 1e18;

class Solution {
public:
	int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
		sort(packages.begin(), packages.end());
		LL sum = accumulate(packages.begin(), packages.end(), 0ll);
		int n = packages.size();
		LL res = INF;
		for (auto& b : boxes)
		{
			sort(b.begin(), b.end());
			if (b.back() < packages.back()) continue;

			LL t = -sum, last = -1;
			for (auto x : b)
			{
				int left = last, right = n - 1;
				while (left < right)
				{
					int mid = left + right + 1 >> 1;
					if (packages[mid] > x)
						right = mid - 1;
					else left = mid;
				}
				if (right == last)continue;
				t += (right - last) * x;
				last = right;
			}
			res = min(res, t);
		}

		if (res == INF) res = -1;
		return res % MOD;
	}

};

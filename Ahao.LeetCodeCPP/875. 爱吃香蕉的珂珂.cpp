#include<vector>

using namespace std;


/*
875. �����㽶������

����ϲ�����㽶�������� n ���㽶���� i ������ piles[i] ���㽶�������Ѿ��뿪�ˣ����� h Сʱ�������

������Ծ��������㽶���ٶ� k ����λ����/Сʱ����ÿ��Сʱ��������ѡ��һ���㽶�����гԵ� k �����������㽶���� k ���������Ե���ѵ������㽶��Ȼ����һСʱ�ڲ����ٳԸ�����㽶��

����ϲ�������ԣ�����Ȼ���ھ�������ǰ�Ե����е��㽶��

������������ h Сʱ�ڳԵ������㽶����С�ٶ� k��k Ϊ��������
*/
class Solution {
public:
	int get(vector<int>& piles, int mid)
	{
		int res = 0;
		for (auto x : piles)
		{
			res += (x + mid - 1) / mid;
		}
		return res;
	}
	int minEatingSpeed(vector<int>& piles, int h) {
		int left = 1, right = 1e9;
		while (left < right)
		{
			int mid = (left + right) >> 1;
			if (get(piles, mid) <= h)
				right = mid;
			else left = mid + 1;
		}
		return right;
	}
};
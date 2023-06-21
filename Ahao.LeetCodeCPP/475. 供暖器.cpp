#include<vector>
#include <algorithm>

using namespace std;


/*
475. ��ů��

�����Ѿ����١� ������������һ���й̶����Ȱ뾶�Ĺ�ů�������з��ݹ�ů��

�ڼ������ļ��Ȱ뾶��Χ�ڵ�ÿ�����ݶ����Ի�ù�ů��

���ڣ�����λ��һ��ˮƽ���ϵķ��� houses �͹�ů�� heaters ��λ�ã������ҳ������ؿ��Ը������з��ݵ���С���Ȱ뾶��

˵�������й�ů������ѭ��İ뾶��׼�����ȵİ뾶Ҳһ����
*/
class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		heaters.push_back(INT_MIN), heaters.push_back(INT_MAX);
		sort(heaters.begin(), heaters.end());
		int res = 0;
		for (auto& x : houses)
		{
			int left = 0, right = heaters.size() - 1;
			while (left < right)
			{
				int mid = (left + right) >> 1;
				if (heaters[mid] >= x) right = mid;
				else
					left = mid + 1;
			}
			res = max(res, (int)min(heaters[right] - 0ll - x, x - 0ll - heaters[right - 1]));
		}
		return res;
	}
};




class Solution {
public:
	bool check(int mid, vector<int>& houses, vector<int>& heaters)
	{
		for (int i = 0, j = 0; i < houses.size(); i++)
		{
			while (j < heaters.size() && abs(heaters[j] - houses[i]) > mid)
				j++;
			if (j >= heaters.size()) return false;
		}
		return true;
	}

	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		int left = 0, right = INT_MAX;
		while (left < right)
		{
			int mid = (long long)(left + right) >> 1;
			if (check(mid, houses, heaters)) right = mid;
			else left = mid + 1;
		}
		return right;
	}
};
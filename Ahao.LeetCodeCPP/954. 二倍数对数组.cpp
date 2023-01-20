#include<vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


/*
954. ������������

����һ������Ϊż������������ arr��ֻ�ж� arr ���������������� ������ÿ�� 0 <= i < len(arr) / 2������ arr[2 * i + 1] = 2 * arr[2 * i]�� ʱ������ true�����򣬷��� false��
*/
class Solution {
public:
	bool canReorderDoubled(vector<int>& arr) {
		int n = arr.size(), cnt = 0;
		sort(arr.begin(), arr.end());
		unordered_map<int, int> mp;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] < 0 && mp.count(arr[i] * 2))
			{
				if (--mp[arr[i] * 2] == 0)mp.erase(arr[i] * 2);
				cnt++;
			}
			else if (arr[i] >= 0 && arr[i] % 2 == 0 && mp.count(arr[i] / 2))
			{
				if (--mp[arr[i] / 2] == 0)mp.erase(arr[i] / 2);
				cnt++;
			}
			else
			{
				mp[arr[i]]++;
			}
		}

		return cnt == n / 2;
	}
};

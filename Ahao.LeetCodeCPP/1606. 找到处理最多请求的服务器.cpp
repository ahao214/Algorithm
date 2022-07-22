#include<vector>
#include <queue>
#include <set>

using namespace std;


/*
1606. �ҵ������������ķ�����
*/
class Solution {
public:
	vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;
		//���еķ�����
		set<int> free;
		for (int i = 0; i < k; i++)
		{
			free.insert(i);
		}

		vector<int> count(k, 0);

		for (int i = 0; i < arrival.size(); i++)
		{
			while (!busy.empty() && busy.top().first <= arrival[i])
			{
				free.insert(busy.top().second);
				busy.pop();
			}

			if (free.empty()) continue;

			auto iter = free.lower_bound(i % k);
			if (iter == free.end())	//û���ҵ�
			{
				iter = free.begin();
			}
			//�ҵ���������ID
			int id = *iter;
			count[id] += 1;
			free.erase(id);
			busy.push({ arrival[i] + load[i],id });
		}

		vector<int> res;
		int maxCount = *max_element(count.begin(), count.end());

		for (int i = 0; i < k; i++)
		{
			if (count[i] == maxCount)
				res.push_back(i);
		}
		return res;
	}
};
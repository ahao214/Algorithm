#include<vector>
#include <unordered_map>

using namespace std;


/*
347. ǰ K ����ƵԪ��
����һ���������� nums ��һ������ k �����㷵�����г���Ƶ��ǰ k �ߵ�Ԫ�ء�����԰� ����˳�� ���ش𰸡�
*/
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> hash;
		for (auto x : nums) hash[x]++;
		int n = nums.size();
		vector<int> s(n + 1, 0);
		for (auto p : hash) s[p.second]++;
		int i = n, t = 0;
		while (t < k) t += s[i--];
		vector<int> res;
		for (auto p : hash)
			if (p.second > i)
				res.push_back(p.first);

		return res;
	}
};
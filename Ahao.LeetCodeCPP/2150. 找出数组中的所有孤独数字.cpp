#include<vector>
#include<unordered_map>

using namespace std;


/*
2150. �ҳ������е����й¶�����
����һ���������� nums ��������� x �������н����� һ�� ����û�� ���� ���֣�����x + 1 �� x - 1�������������У�����Ϊ���� x �� �¶����� ��

���� nums �е� ���� �¶����֡�����԰� �κ�˳�� ���ش𰸡�
*/
class Solution {
public:
	vector<int> findLonely(vector<int>& nums) {
		unordered_map<int, int> cnt;
		for (auto x : nums)
			cnt[x]++;
		vector<int> res;
		for (auto x : nums)
		{
			if (cnt[x] == 1 && !cnt.count(x - 1) && !cnt.count(x + 1))
				res.push_back(x);
		}
		return res;
	}

};

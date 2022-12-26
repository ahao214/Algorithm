#include<vector>
#include <unordered_set>

using namespace std;


/*
421. ��������������������ֵ
����һ���������� nums ������ nums[i] XOR nums[j] ����������������� 0 �� i �� j < n ��

���ף�������� O(n) ��ʱ�������������
*/
class Solution {
public:
	typedef long long ll;
	int findMaximumXOR(vector<int>& nums) {
		unordered_set<ll> edge;
		int res = 0;
		for (auto& x : nums) {
			ll pre = 0, pre_op = 0;
			int xorr = 0;
			for (int i = 30; i >= 0; i--) {
				int next = x >> i & 1;
				edge.insert(pre + next * (1ll << 32) + i * (1ll << 33));
				if (edge.count(pre_op + !next * (1ll << 32) + i * (1ll << 33))) {
					xorr = xorr * 2 + 1;
					pre_op = pre_op * 2 + !next;
				}
				else {
					xorr <<= 1;
					pre_op = pre_op * 2 + next;
				}
				pre = pre * 2 + next;
			}
			res = max(res, xorr);
		}
		return res;
	}
};
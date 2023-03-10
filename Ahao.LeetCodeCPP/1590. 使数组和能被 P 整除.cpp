#include<vector>
#include<unordered_map>


using namespace std;


/*
1590. ʹ������ܱ� P ����

����һ������������ nums�������Ƴ� ��� �����飨����Ϊ �գ���ʹ��ʣ��Ԫ�ص� �� �ܱ� p ������ ������ ���������鶼�Ƴ���

���㷵������Ҫ�Ƴ������������ĳ��ȣ�����޷�������ĿҪ�󣬷��� -1 ��

������ ����Ϊԭ������������һ��Ԫ�ء�
*/
class Solution {
public:
	int minSubarray(vector<int>& nums, int p) {
		unordered_map<int, int> Map;
		Map[0] = -1;
		long totalSum = 0;
		for (auto a : nums)
			totalSum = (totalSum + a) % p;
		long r0 = totalSum % p;
		if (r0 == 0) return 0;

		int presum = 0;
		int ret = INT_MAX;
		for (int j = 0; j < nums.size(); j++)
		{
			presum = (presum + nums[j]) % p;
			int r = presum % p;
			int dr = (r - r0 + p) % p;

			if (Map.find(dr) != Map.end())
			{
				int i = Map[dr] + 1;
				ret = min(ret, j - i + 1);
			}
			Map[presum % p] = j;
		}
		if (ret < nums.size())
			return ret;
		else
			return -1;
	}
};





class Solution {
public:
	int minSubarray(vector<int>& nums, int p) {
		int x = 0;
		for (auto num : nums) {
			x = (x + num) % p;
		}
		if (x == 0) {
			return 0;
		}
		unordered_map<int, int> index;
		int y = 0, res = nums.size();
		for (int i = 0; i < nums.size(); i++) {
			index[y] = i; // f[i] mod p = y����˹�ϣ���¼ y ��Ӧ���±�Ϊ i
			y = (y + nums[i]) % p;
			if (index.count((y - x + p) % p) > 0) {
				res = min(res, i - index[(y - x + p) % p] + 1);
			}
		}
		return res == nums.size() ? -1 : res;
	}
};

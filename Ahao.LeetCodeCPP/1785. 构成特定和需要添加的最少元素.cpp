#include<vector>
#include <numeric>

using namespace std;



/*
1785. �����ض�����Ҫ��ӵ�����Ԫ��
����һ���������� nums ������������ limit �� goal ������ nums ��һ����Ҫ���ԣ�abs(nums[i]) <= limit ��

����ʹ����Ԫ���ܺ͵��� goal ����Ҫ����������ӵ� ����Ԫ������ �����Ԫ�� ��Ӧ�ı� ������ abs(nums[i]) <= limit ��һ���ԡ�

ע�⣬��� x >= 0 ����ô abs(x) ���� x �����򣬵��� -x ��
*/
class Solution {
public:
	int minElements(vector<int>& nums, int limit, int goal) {
		long long sum = accumulate(nums.begin(), nums.end(), 0ll);
		return (abs(sum - goal) + limit - 1) / limit;
	}
};

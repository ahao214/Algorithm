#include<vector>

using namespace std;


/*
1829. ÿ����ѯ��������ֵ
����һ�� ���� ���� nums ������ n ���Ǹ�������ɣ�ͬʱ����һ������ maximumBit ������Ҫִ�����²�ѯ n �Σ�

�ҵ�һ���Ǹ����� k < 2maximumBit ��ʹ�� nums[0] XOR nums[1] XOR ... XOR nums[nums.length-1] XOR k �Ľ�� ��� ��k �ǵ� i ����ѯ�Ĵ𰸡�
�ӵ�ǰ���� nums ɾ�� ��� һ��Ԫ�ء�
���㷵��һ������ answer ������ answer[i]�ǵ� i ����ѯ�Ľ����
*/
class Solution {
public:
	vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
		vector<int> res;
		for (int i = 0, sum = 0; i < nums.size(); i++)
		{
			sum ^= nums[i];
			res.push_back(sum ^ (1 << maximumBit) - 1);
		}
		reverse(res.begin(), res.end());
		return res;
	}

};
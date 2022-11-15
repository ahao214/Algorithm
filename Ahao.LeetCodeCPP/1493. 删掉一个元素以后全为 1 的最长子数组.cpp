#include<vector>

using namespace std;


/*
1493. ɾ��һ��Ԫ���Ժ�ȫΪ 1 ���������
����һ������������ nums ������Ҫ����ɾ��һ��Ԫ�ء�

������ɾ��Ԫ�صĽ�������У����������ֻ���� 1 �ķǿ�������ĳ��ȡ�

��������������������飬�뷵�� 0 ��
*/
class Solution {
public:
	//ʹ��˫ָ��i��j��������i��j֮��ʼ�ձ���ֻ��һ��0
	//ÿ������ĳ�����i-j,����ÿ������ֵ�����ֵ
	int longestSubarray(vector<int>& nums) {
		int res = 0;
		//zero��ʾ0�ĸ���
		for (int i = 0, j = 0, zero = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0) zero++;
			while (zero > 1)
				zero -= !nums[j++];
			res = max(res, i - j);
		}
		return res;
	}
};
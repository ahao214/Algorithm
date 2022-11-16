#include<vector>

using namespace std;



/*
1558. �õ�Ŀ����������ٺ������ô���

����һ���� nums ��С��ͬ�ҳ�ʼֵȫΪ 0 ������ arr ������������Ϻ����õ��������� nums ��

���㷵�ؽ� arr ��� nums �����ٺ������ô�����

�𰸱�֤�� 32 λ�з����������ڡ�
arr=[0,0,0] ������� nums = [2,3,1]
��������Ϊ�У���arr�����е�ĳ������1�����arr�����е�������������2
*/
class Solution {
public:
	int minOperations(vector<int>& nums) {
		int k = 0, os = 0;
		for (auto x : nums)
		{
			int bits = 0, ones = 0;
			while (x)
			{
				if (x & 1) ones++;
				bits++;
				x >>= 1;
			}
			k = max(k, bits), os += ones;
		}
		return os + k - 1;
	}
};

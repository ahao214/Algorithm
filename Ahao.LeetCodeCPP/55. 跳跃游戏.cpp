using namespace std;

#include<vector>

/*
55. ��Ծ��Ϸ
����һ���Ǹ��������� nums �������λ������� ��һ���±� ��

�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�

�ж����Ƿ��ܹ��������һ���±ꡣ
*/
class Solution {
public:
	bool canJump(vector<int>& nums) {
		for (int i = 0, maxPos = 0; i < nums.size(); i++)
		{
			if (i > maxPos) return false;
			maxPos = max(maxPos, i + nums[i]);
		}
		return true;
	}
};



/*
55. ��Ծ��Ϸ
����һ���Ǹ��������� nums �������λ������� ��һ���±� ��

�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�

�ж����Ƿ��ܹ��������һ���±ꡣ
*/
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int dist = 0;
		for (int i = 0; i < nums.size() && i <= dist; i++) {
			dist = max(dist, nums[i] + i);
		}
		return dist >= (int)nums.size() - 1;
	}
};
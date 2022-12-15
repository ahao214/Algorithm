#include<vector>
#include <stack>
#include <unordered_map>

using namespace std;



/*
496. ��һ������Ԫ�� I
nums1 ������ x �� ��һ������Ԫ�� ��ָ x �� nums2 �ж�Ӧλ�� �Ҳ� �� ��һ�� �� x ���Ԫ�ء�

�������� û���ظ�Ԫ�� ������ nums1 �� nums2 ���±�� 0 ��ʼ����������nums1 �� nums2 ���Ӽ���

����ÿ�� 0 <= i < nums1.length ���ҳ����� nums1[i] == nums2[j] ���±� j �������� nums2 ȷ�� nums2[j] �� ��һ������Ԫ�� �������������һ������Ԫ�أ���ô���β�ѯ�Ĵ��� -1 ��

����һ������Ϊ nums1.length ������ ans ��Ϊ�𰸣����� ans[i] ������������ ��һ������Ԫ�� ��
*/
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		stack<int> stk;
		unordered_map<int, int> hash;
		for (int j = nums2.size() - 1; j >= 0; j--)
		{
			while (stk.size() && stk.top() <= nums2[j])
				stk.pop();
			hash[nums2[j]] = stk.size() ? stk.top() : -1;
			stk.push(nums2[j]);
		}
		vector<int> res;
		for (auto x : nums1)
			res.push_back(hash[x]);
		return res;
	}
};
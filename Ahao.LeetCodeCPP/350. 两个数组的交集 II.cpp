#include<vector>
#include <unordered_set>

using namespace std;



/*
350. ��������Ľ��� II
���������������� nums1 �� nums2 ��������������ʽ����������Ľ��������ؽ����ÿ��Ԫ�س��ֵĴ�����Ӧ��Ԫ�������������ж����ֵĴ���һ�£�������ִ�����һ�£�����ȡ��Сֵ�������Բ�������������˳��
*/
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size()) return intersect(nums2, nums1);
		unordered_multiset<int> hash;
		for (auto x : nums1) hash.insert(x);
		vector<int> res;
		for (auto x : nums2)
		{
			if (hash.count(x))
			{
				res.push_back(x);
				auto it = hash.find(x);
				hash.erase(it);
			}
		}
		return res;
	}
};

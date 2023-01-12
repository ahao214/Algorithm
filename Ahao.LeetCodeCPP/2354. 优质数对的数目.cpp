#include<vector>
#include <unordered_set>
#include <algorithm>

using namespace std;



/*
2354. �������Ե���Ŀ
����һ���±�� 0 ��ʼ������������ nums ��һ�������� k ��

����������������������� (num1, num2) �� �������� ��

num1 �� num2 �� ������ nums �д��ڡ�
num1 OR num2 �� num1 AND num2 �Ķ����Ʊ�ʾ��ֵΪ 1 ��λ��֮�ʹ��ڵ��� k ������ OR �ǰ�λ �� �������� AND �ǰ�λ �� ������
���� ��ͬ �������Ե���Ŀ��

��� a != c ���� b != d ������Ϊ (a, b) �� (c, d) �ǲ�ͬ���������ԡ����磬(1, 2) �� (2, 1) ��ͬ��

ע�⣺��� num1 �����������ٳ��� һ�� �������� num1 == num2 ������ (num1, num2) Ҳ�������������ԡ�
*/
class Solution {
public:
	long long countExcellentPairs(vector<int>& nums, int k) {
		unordered_set<int>st(nums.begin(), nums.end());

		vector<int> bits;
		for (auto x : st) {
			bits.push_back(__builtin_popcount(x));
		}

		sort(bits.begin(), bits.end());
		int n = bits.size();
		int j = n - 1;
		long long res = 0;
		for (int i = 0; i < n; i++) {
			while (j >= 0 && bits[i] + bits[j] >= k) {
				j--;
			}
			if (j >= i)
				res += n - (j + 1);
			else
				res += n - (i + 1);
		}
		res *= 2;
		for (auto x : bits) {
			if (x * 2 >= k) {
				res += 1;
			}
		}
		return res;
	}
};


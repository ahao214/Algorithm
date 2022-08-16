#include<vector>
#include<unordered_map>

using namespace std;


/*
1865. �ҳ���Ϊָ��ֵ���±��
���������������� nums1 �� nums2 ������ʵ��һ��֧�����������ѯ�����ݽṹ��

�ۼ� ����һ���������ӵ� nums2 ��ָ���±��ӦԪ���ϡ�
���� ��ͳ������ nums1[i] + nums2[j] ����ָ��ֵ���±�� (i, j) ��Ŀ��0 <= i < nums1.length �� 0 <= j < nums2.length����
ʵ�� FindSumPairs �ࣺ

FindSumPairs(int[] nums1, int[] nums2) ʹ���������� nums1 �� nums2 ��ʼ�� FindSumPairs ����
void add(int index, int val) �� val �ӵ� nums2[index] �ϣ�����ִ�� nums2[index] += val ��
int count(int tot) �������� nums1[i] + nums2[j] == tot ���±�� (i, j) ��Ŀ��
*/
class Solution {
public:
	vector<int> a, b;
	unordered_map<int, int> cnt;

	FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
		a = nums1, b = nums2;
		for (auto x : b) cnt[x]++;
	}

	void add(int index, int val) {
		cnt[b[index]]--;
		b[index] += val;
		cnt[b[index]]++;
	}

	int count(int tot) {
		int res = 0;
		for (auto x : a)
			res += cnt[tot - x];
		return res;
	}

};

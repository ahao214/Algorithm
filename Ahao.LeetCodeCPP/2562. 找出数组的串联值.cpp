#include<vector>
#include<string>

using namespace std;


/*
2562. �ҳ�����Ĵ���ֵ

����һ���±�� 0 ��ʼ���������� nums ��

�ֶ����������ֵ� ���� ������������ֵ���������γɵ������֡�

���磬15 �� 49 �Ĵ����� 1549 ��
nums �� ����ֵ ������� 0 ��ִ����������ֱ�� nums ��Ϊ�գ�

��� nums �д��ڲ�ֹһ�����֣��ֱ�ѡ�� nums �еĵ�һ��Ԫ�غ����һ��Ԫ�أ������ߴ����õ���ֵ�ӵ� nums �� ����ֵ �ϣ�Ȼ��� nums ��ɾ����һ�������һ��Ԫ�ء�
���������һ��Ԫ�أ��򽫸�Ԫ�ص�ֵ�ӵ� nums �Ĵ���ֵ�ϣ�Ȼ��ɾ�����Ԫ�ء�
����ִ�������в����� nums �Ĵ���ֵ��
*/

class Solution {
public:
	long long findTheArrayConcVal(vector<int>& nums) {
		long long ans = 0;
		for (int i = 0, j = nums.size() - 1; i <= j; i++, j--) {
			if (i != j) {
				ans += stoi(to_string(nums[i]) + to_string(nums[j]));
			}
			else {
				ans += nums[i];
			}
		}
		return ans;
	}
};

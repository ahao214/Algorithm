#include<vector>
#include<algorithm>

using namespace std;


/*
1846. ��С�������������������Ԫ��
����һ������������ arr ������� arr ִ��һЩ������Ҳ���Բ������κβ�������ʹ��������������������

arr �� ��һ�� Ԫ�ر���Ϊ 1 ��
������������Ԫ�صĲ�ľ���ֵ С�ڵ��� 1 ��Ҳ����˵����������� 1 <= i < arr.length �������±�� 0 ��ʼ���������� abs(arr[i] - arr[i - 1]) <= 1 ��abs(x) Ϊ x �ľ���ֵ��
�����ִ������ 2 �ֲ�������Σ�

��С arr ������Ԫ�ص�ֵ��ʹ���Ϊһ�� ��С�������� ��
�������� arr �е�Ԫ�أ������������˳���������С�
���㷵��ִ�����ϲ�����������ǰ�������������£�arr �п��ܵ� ���ֵ ��
*/
class Solution {
public:
	int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
		int n = arr.size();
		sort(arr.begin(), arr.end());
		int last = 1;
		for (int i = 1; i < n; i++)
			last = min(last + 1, arr[i]);
		return last;
	}

};
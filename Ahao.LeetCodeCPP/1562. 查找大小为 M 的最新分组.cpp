#include<vector>

using namespace std;


/*
1562. ���Ҵ�СΪ M �����·���
����һ������ arr ���������ʾһ���� 1 �� n ���������С���һ������Ϊ n �Ķ������ַ��������ַ����ϵ�����λ���������Ϊ 0 ��

�ڴ� 1 �� n ��ÿ������ i �У�����������ַ����� arr ���Ǵ� 1 ��ʼ����������£����������ַ�����λ��λ�� arr[i] ��λ������Ϊ 1 ��

����һ������ m �������ҳ��������ַ����ϴ��ڳ���Ϊ m ��һ�� 1 ������衣һ�� 1 ��һ�������ġ��� 1 ��ɵ��Ӵ������������߲����п�������� 1 ��

���ش��ڳ��� ǡ�� Ϊ m �� һ�� 1  ������衣��������������Ĳ��裬�뷵�� -1 ��
*/
class Solution {
public:
	vector<int> left, right;
	int get(int x) {
		return right[x] - x + 1;
	}
	int findLatestStep(vector<int>& arr, int m) {
		int n = arr.size();
		left.resize(n + 2), right.resize(n + 2);
		int cnt = 0, res = -1;
		for (int i = 0; i < arr.size(); i++)
		{
			int x = arr[i];
			if (left[x - 1] && right[x + 1]) {
				if (get(left[x - 1]) == m) cnt--;
				if (get(x + 1) == m) cnt--;
				right[left[x - 1]] = right[x + 1];
				left[right[x + 1]] = left[x - 1];
				if (get(left[x - 1]) == m) cnt++;
			}
			else if (left[x - 1]) {
				if (get(left[x - 1]) == m) cnt--;
				right[left[x - 1]] = x, left[x] = left[x - 1];
				if (get(left[x - 1]) == m) cnt++;
			}
			else if (right[x + 1]) {
				if (get(x + 1) == m) cnt--;
				right[x] = right[x + 1];
				left[right[x + 1]] = x;
				if (get(x) == m) cnt++;
			}
			else {
				left[x] = right[x] = x;
				if (m == 1) cnt++;
			}
			if (cnt) res = i + 1;
		}
		return res;
	}
};


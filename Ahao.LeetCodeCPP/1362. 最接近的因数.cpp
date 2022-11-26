#include<vector>

using namespace std;


/*
1362. ��ӽ�������
����һ������ num�������ҳ�ͬʱ��������ȫ��Ҫ�������������

�����˻�����  num + 1 �� num + 2
�Ծ��Բ���ж�����������С��ӽ�
����԰�����˳�򷵻�������������
*/
class Solution {
public:
	vector<int> closestDivisors(int num) {
		for (int i = sqrt(num + 2); i; i--)
		{
			if ((num + 1) % i == 0) return { i,(num + 1) / i };
			if ((num + 2) % i == 0) return { i,(num + 2) / i };
		}
		return {};
	}
};
#include<vector>

using namespace std;


/*
1342. �����ֱ�� 0 �Ĳ�������
����һ���Ǹ����� num �����㷵�ؽ������ 0 ����Ҫ�Ĳ����� �����ǰ������ż��������Ҫ�������� 2 �����򣬼�ȥ 1 ��
*/
class Solution {
public:
	int numberOfSteps(int num) {
		int ans = 0;
		while (num) {
			if (num % 2) num--;
			else num /= 2;
			ans++;
		}
		return ans;
	}
};
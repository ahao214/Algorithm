#include<vector>

using namespace std;


/*
231. 2 ����
����һ������ n�������жϸ������Ƿ���2���ݴη�������ǣ����� true ��
���򣬷��� false ��

�������һ������ x ʹ�� n == 2^ x ������Ϊ n �� 2 ���ݴη���
*/
class Solution {
public:
	bool isPowerOfTwo(int n) {
		return n > 0 && (1 << 30) % n == 0;
	}

	bool isPowerOfTwo(int n) {
		//n & -n ����n�Ķ����Ʊ�ʾ�����ұ�һ��1
		return n > 0 && (n & -n) == n;
	}
};

#include<vector>

using namespace std;


/*
1486. ����������
��������������n �� start ��

���� nums ����Ϊ��nums[i] = start + 2*i���±�� 0 ��ʼ���� n == nums.length ��

�뷵�� nums ������Ԫ�ذ�λ���XOR����õ��Ľ����
*/
class Solution {
public:
	int xorOperation(int n, int start) {
		int res = 0;
		for (int i = 0; i < n; i++)
			res ^= start + i * 2;
		return res;
	}
};
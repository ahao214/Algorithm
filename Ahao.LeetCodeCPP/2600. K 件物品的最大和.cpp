#include<vector>

using namespace std;

/*
2600. K ����Ʒ������

������װ��һЩ��Ʒ��ÿ����Ʒ�϶���������� 1 ��0 �� -1 ��

�����ĸ��Ǹ����� numOnes ��numZeros ��numNegOnes �� k ��

�������������

numOnes �����Ϊ 1 ����Ʒ��
numZeroes �����Ϊ 0 ����Ʒ��
numNegOnes �����Ϊ -1 ����Ʒ��
�ּƻ�����Щ��Ʒ��ǡ��ѡ�� k ����Ʒ���������п��з����У���Ʒ�����������֮�͵����ֵ��
*/


class Solution {
public:
	int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
		if (k <= numOnes) {
			return k;
		}
		else if (k <= numOnes + numZeros) {
			return numOnes;
		}
		else {
			return numOnes - (k - numOnes - numZeros);
		}
	}
};

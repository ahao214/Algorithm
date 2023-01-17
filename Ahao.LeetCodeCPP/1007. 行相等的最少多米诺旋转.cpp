#include<vector>

using namespace std;


/*
1007. ����ȵ����ٶ���ŵ��ת
��һ�Ŷ���ŵ�����У�A[i] �� B[i] �ֱ����� i ������ŵ���Ƶ��ϰ벿�ֺ��°벿�֡���һ������ŵ�������� 1 �� 6 ������ͬ��ƽ���γɵ� ���� ��ƽ�̵�ÿһ���϶���һ�����֡���

���ǿ�����ת�� i �Ŷ���ŵ��ʹ�� A[i] �� B[i] ��ֵ������

������ʹ A ������ֵ���� B ������ֵ����ͬ����С��ת������

����޷����������� -1.
*/
class Solution {
public:
	int helper(int val, vector<int>& A, vector<int>& B)
	{
		int n = A.size();
		int countA = 0, countB = 0;
		for (int i = 0; i < n; i++)
		{
			if (A[i] != val && B[i] != val)
			{
				return -1;
			}
			else if (A[i] != val)
			{
				countA++;
			}
			else if (B[i] != val)
			{
				countB++;
			}
		}
		return min(countA, countB);
	}

	int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
		int rotation = helper(tops[0], tops, bottoms);
		if (rotation != -1 || tops[0] == bottoms[0])
			return rotation;
		else
			return helper(bottoms[0], tops, bottoms);
	}
};


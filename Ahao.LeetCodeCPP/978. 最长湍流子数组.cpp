#include<vector>

using namespace std;

/*
978. �����������

����һ���������� arr ������ arr �� �������������ĳ��� ��

����ȽϷ������������е�ÿ������Ԫ�ض�֮�䷭ת������������� ���������� ��

����ʽ����˵���� arr �������� A[i], A[i+1], ..., A[j] �����������������ʱ�����ǳ���Ϊ���������飺

�� i <= k < j ��
�� k Ϊ����ʱ�� A[k] > A[k+1]����
�� k Ϊż��ʱ��A[k] < A[k+1]��
�� �� i <= k < j ��
�� k Ϊż��ʱ��A[k] > A[k+1] ����
�� k Ϊ����ʱ�� A[k] < A[k+1]��
*/
class Solution {
public:
	int maxTurbulenceSize(vector<int>& arr) {
		int res = 1;
		for (int i = 1, up = 1, down = 1; i < arr.size(); i++)
		{
			if (arr[i] > arr[i - 1])
			{
				up = down + 1;
				down = 1;
			}
			else if (arr[i] < arr[i - 1])
			{
				down = up + 1;
				up = 1;
			}
			else
			{
				down = up = 1;
			}
			res = max(res, max(up, down));
		}
		return res;
	}
};
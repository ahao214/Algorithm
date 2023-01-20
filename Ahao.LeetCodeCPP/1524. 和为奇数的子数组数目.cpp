#include<vector>

using namespace std;



/*
1524. ��Ϊ��������������Ŀ

����һ���������� arr �����㷵�غ�Ϊ ���� ����������Ŀ��

���ڴ𰸿��ܻ�ܴ����㽫����� 10^9 + 7 ȡ��󷵻ء�
*/
class Solution {
public:
	int numOfSubarrays(vector<int>& arr) {
		long oddCount = 0, evenCount = 1;
		long M = 1e9 + 7;
		long presum = 0;
		long res = 0;
		for (int i = 0; i < arr.size(); i++) {
			presum += arr[i];
			if (presum % 2 == 0)
				res += oddCount;
			else
				res += evenCount;
			res %= M;

			if (presum % 2 == 0)
				evenCount += 1;
			else
				oddCount += 1;
		}
		return res;
	}
};

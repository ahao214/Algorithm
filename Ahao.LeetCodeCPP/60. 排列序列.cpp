using namespace std;
#include<vector>
#include<string>

class Solution {
	/*
	60. ��������
	�������� [1,2,3,...,n]��������Ԫ�ع��� n! �����С�

	����С˳���г����������������һһ��ǣ��� n = 3 ʱ, �����������£�

	"123"
	"132"
	"213"
	"231"
	"312"
	"321"
	���� n �� k�����ص� k �����С�
	*/
public:
	/*
	Times:O(n^2)
	Space:O(1)
	*/
	string getPermutation(int n, int k) {
		vector<int> fact(n + 1, 1);
		for (int i = 1; i <= n; i++)
		{
			fact[i] = fact[i - 1] * i;
		}
		string ans;
		vector<bool> used(n + 1);
		for (int i = 0; i < n; i++)
		{
			int cnt = fact[n - i - 1];
			for (int j = 1; j <= n; j++)
			{
				if (used[j]) continue;
				if (k > cnt)
				{
					k -= cnt;
				}
				else
				{
					ans += j + '0';
					used[j] = true;
					break;
				}
			}
		}
		return ans;
	}

};
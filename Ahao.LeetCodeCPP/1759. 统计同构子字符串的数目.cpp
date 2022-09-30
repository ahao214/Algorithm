#include<vector>
#include<string>

using namespace std;


/*
1759. ͳ��ͬ�����ַ�������Ŀ
����һ���ַ��� s ������ s �� ͬ�����ַ��� ����Ŀ�����ڴ𰸿��ܴܺ�ֻ�践�ض� 109 + 7 ȡ�� ��Ľ����

ͬ���ַ��� �Ķ���Ϊ�����һ���ַ����е������ַ�����ͬ����ô���ַ�������ͬ���ַ�����

���ַ��� ���ַ����е�һ�������ַ����С�
*/
class Solution {
public:
	/*
	�Ƚ��ַ����ֳɼ��Σ�ʹÿ��������ַ�����ͬ
	����ÿ���������ַ����ĸ���������ÿ�εĳ���ΪK������Ϊ k*(k+1)/2
	*/
	int countHomogenous(string s) {
		typedef long long LL;
		const int MOD = 1e9 + 7;

		int res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int j = i + 1;
			while (j < s.size() && s[j] == s[i])
				j++;
			int k = j - i;
			res = (res + (LL)k * (k + 1) / 2) % MOD;
			i = j - 1;
		}
		return res;
	}
};

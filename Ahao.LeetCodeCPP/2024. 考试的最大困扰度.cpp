#include<vector>
#include <string>

using namespace std;


/*
2024. ���Ե�������Ŷ�

һλ��ʦ���ڳ�һ���� n ���ж��⹹�ɵĿ��ԣ�ÿ����Ĵ�Ϊ true ���� 'T' ��ʾ������ false ���� 'F' ��ʾ������ʦ������ѧ�����Լ������𰸵Ĳ�ȷ���ԣ������� ��� �� ������ͬ �������������Ҳ������������ true ������������ false����

����һ���ַ��� answerKey ������ answerKey[i] �ǵ� i ���������ȷ������������⣬������һ������ k ����ʾ���ܽ������²�������������

ÿ�β����У����������ȷ�𰸸�Ϊ 'T' ���� 'F' ��Ҳ���ǽ� answerKey[i] ��Ϊ 'T' ���� 'F' ����
���㷵���ڲ����� k �β���������£���� ���� 'T' ���� 'F' ����Ŀ��
*/
class Solution {
public:
	int lts(const string& s, int k, char c)
	{
		int n = s.size(), left = 0, right = 0, s1 = 0, s2 = 0, res = 0;
		while (right < n)
		{
			if (s[right] != c) s2++;
			while (s2 - s1 > k)
			{
				if (s[left] != c) s1++;
				left++;
			}
			res = max(res, right - left + 1);
		}
		return res;
	}

	int maxConsecutiveAnswers(string answerKey, int k) {
		return max(lts(answerKey, k, 'T'), lts(answerKey, k, 'F'));
	}
};
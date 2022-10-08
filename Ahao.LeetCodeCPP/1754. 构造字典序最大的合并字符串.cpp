#include<string>

using namespace std;



/*
1754. �����ֵ������ĺϲ��ַ���
���������ַ��� word1 �� word2 ������Ҫ��������ʽ����һ�����ַ��� merge ����� word1 �� word2 �ǿգ�ѡ�� ����ѡ��֮һ ����������

��� word1 �ǿգ��� word1 �еĵ�һ���ַ����ӵ� merge ��ĩβ��������� word1 ���Ƴ���
���磬word1 = "abc" �� merge = "dv" ����ִ�д�ѡ�����֮��word1 = "bc" ��ͬʱ merge = "dva" ��
��� word2 �ǿգ��� word2 �еĵ�һ���ַ����ӵ� merge ��ĩβ��������� word2 ���Ƴ���
���磬word2 = "abc" �� merge = "" ����ִ�д�ѡ�����֮��word2 = "bc" ��ͬʱ merge = "a" ��
��������Թ�����ֵ��� ��� �ĺϲ��ַ��� merge ��

������ͬ�������ַ��� a �� b �Ƚ��ֵ����С������� a �� b ���ֲ�ͬ�ĵ�һ��λ�ã�a ���ַ�����ĸ���еĳ���˳��λ�� b ����Ӧ�ַ�֮�󣬾���Ϊ�ַ��� a ���ֵ�����ַ��� b �������磬"abcd" ���ֵ���� "abcc" ������Ϊ�����ַ������ֲ�ͬ�ĵ�һ��λ���ǵ��ĸ��ַ����� d ����ĸ���еĳ���˳��λ�� c ֮��
*/
class Solution {
public:
	string largestMerge(string word1, string word2) {
		string res;
		int i = 0, j = 0;
		while (i < word1.size() || j < word2.size())
		{
			if (word1.substr(i) > word2.substr(j))
				res += word1[i++];
			else
				res += word2[j++];
		}
		return res;
	}
};


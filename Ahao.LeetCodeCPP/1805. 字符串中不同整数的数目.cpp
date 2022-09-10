#include<vector>
#include<string>
#include<unordered_set>

using namespace std;


/*
1805. �ַ����в�ͬ��������Ŀ
����һ���ַ��� word �����ַ��������ֺ�СдӢ����ĸ��ɡ�

�����ÿո��滻ÿ���������ֵ��ַ������磬"a123bc34d8ef34" ������ " 123  34 8  34" ��ע�⣬ʣ�µ���Щ����Ϊ�����ڱ˴�������һ���ո��������"123"��"34"��"8" �� "34" ��

���ض� word ����滻���γɵ� ��ͬ ��������Ŀ��

ֻ�е����������� ����ǰ���� ��ʮ���Ʊ�ʾ��ͬ�� ����Ϊ����������Ҳ��ͬ��
*/
class Solution {
public:
	int numDifferentIntegers(string word) {
		unordered_set<string> nums;
		for (int i = 0; i < word.size(); i++)
		{
			if (!isdigit(word[i])) continue;
			string s;
			int j = i;
			while (j < word.size() && isdigit(word[j]))
				s += word[j++];
			int k = 0;
			while (k + 1 < s.size() && s[k] == '0') k++;
			nums.insert(s.substr(k));
			i = j;
		}
		return nums.size();
	}
};
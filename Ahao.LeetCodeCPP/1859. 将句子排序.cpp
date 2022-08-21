#include<string>
#include<vector>
#include<algorithm>

using namespace std;


/*
1859. ����������
һ�� ���� ָ����һ�����еĵ����õ����ո������������ҿ�ͷ�ͽ�βû���κοո�ÿ�����ʶ�ֻ����Сд���дӢ����ĸ��

���ǿ��Ը�һ��������� �� 1 ��ʼ�ĵ���λ������ �����ҽ����������е��� ����˳�� ��

�ȷ�˵������ "This is a sentence" ���Ա�����˳��õ� "sentence4 a3 is2 This1" ���� "is2 sentence4 This1 a3" ��
����һ�� ����˳�� �ľ��� s ���������ĵ��ʲ����� 9 �����������¹��첢�õ�ԭ��˳��ľ��ӡ�
*/
class Solution {
public:
	string sortSentence(string s) {
		vector<pair<int, string>> q;
		for (int i = 0; i < s.size(); i++)
		{
			int j = i;
			string word;
			while (j < s.size() && s[j] != ' ')
				word += s[j++];
			i = j;
			q.push_back({ word.back() - '0',word.substr(0,word.size() - 1) });
		}
		sort(q.begin(), q.end());
		string res;
		for (auto& w : q)
		{
			res += w.second + ' ';
		}
		res.pop_back();
		return res;
	}

};

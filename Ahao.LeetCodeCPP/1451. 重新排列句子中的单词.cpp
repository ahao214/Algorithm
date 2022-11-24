#include<vector>
#include <string>
#include <algorithm>

using namespace std;

/*
1451. �������о����еĵ���
�����ӡ���һ���ÿո�ָ����ʵ��ַ���������һ������������ʽ�ľ��� text :

���ӵ�����ĸ��д
text �е�ÿ�����ʶ��õ����ո�ָ���
������������ text �еĵ��ʣ�ʹ���е��ʰ��䳤�ȵ��������С�����������ʵĳ�����ͬ����������ԭ�����е����˳��

��ͬ����������ʽ�����µľ��ӡ�
*/
class Solution {
public:
	string arrangeWords(string text) {
		stringstream ssin(text);
		vector<string> words;
		string word;
		while (ssin >> word) words.push_back(word);
		words[0][0] = tolower(words[0][0]);
		stable_sort(words.begin(), words.end(), [](string a, string b) {
			return a.size() < b.size();
			});
		words[0][0] = toupper(words[0][0]);

		string res;
		for (auto word : words) res += word + ' ';
		res.pop_back();
		return res;
	}
};
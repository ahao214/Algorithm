#include<string>
#include<vector>

using namespace std;


/*
1813. ���������� III
һ����������һЩ����������֮��ĵ����ո���ɣ��Ҿ��ӵĿ�ͷ�ͽ�βû�ж���ո񡣱ȷ�˵��"Hello World" ��"HELLO" ��"hello world hello world" ���Ǿ��ӡ�ÿ�����ʶ� ֻ ������д��СдӢ����ĸ��

����������� sentence1 �� sentence2 ������ͨ��������һ�����Ӳ���һ������ľ��ӣ������ǿվ��ӣ����õ���һ�����ӣ���ô���ǳ������������� ���Ƶ� ���ȷ�˵��sentence1 = "Hello my name is Jane" �� sentence2 = "Hello Jane" �����ǿ����� sentence2 �� "Hello" �� "Jane" ֮����� "my name is" �õ� sentence1 ��

������������ sentence1 �� sentence2 ����� sentence1 �� sentence2 �����Ƶģ����㷵�� true �����򷵻� false ��
*/
class Solution {
public:
	bool areSentencesSimilar(string sentence1, string sentence2) {
		if (sentence1.size() > sentence2.size())
			return areSentencesSimilar(sentence2, sentence1);
		stringstream s1(sentence1), s2(sentence2);
		vector<string>a, b;
		string s;
		while (s1 >> s) a.push_back(s);
		while (s2 >> s) b.push_back(s);

		int i = 0, j = a.size() - 1;
		for (int k = 0; k < b.size() && i < a.size(); k++)
			if (a[i] == b[k])
				i++;
			else
				break;
		for (int k = b.size() - 1; k >= 0 && j >= 0; k--)
			if (a[j] == b[k])
				j--;
			else
				break;
		return i > j;
	}

};

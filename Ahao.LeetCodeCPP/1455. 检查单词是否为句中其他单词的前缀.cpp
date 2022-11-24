#include<vector>
#include <string>

using namespace std;



/*
1455. ��鵥���Ƿ�Ϊ�����������ʵ�ǰ׺
����һ���ַ��� sentence ��Ϊ���Ӳ�ָ��������Ϊ searchWord �����о����������� �����ո� �ָ��ĵ�����ɡ������������ searchWord �Ƿ�Ϊ���� sentence �����ⵥ�ʵ�ǰ׺��

��� searchWord ��ĳһ�����ʵ�ǰ׺���򷵻ؾ��� sentence �иõ�������Ӧ���±꣨�±�� 1 ��ʼ������� searchWord �Ƕ�����ʵ�ǰ׺���򷵻�ƥ��ĵ�һ�����ʵ��±꣨��С�±꣩����� searchWord �����κε��ʵ�ǰ׺���򷵻� -1 ��

�ַ��� s �� ǰ׺ �� s ���κ�ǰ���������ַ�����
*/
class Solution {
public:
	int isPrefixOfWord(string sentence, string searchWord) {
		stringstream ssin(sentence);

		string word;
		for (int i = 1; ssin >> word; i++)
		{
			if (word.substr(0, searchWord.size()) == searchWord)
				return i;
		}
		return -1;
	}
};
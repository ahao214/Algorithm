#include<vector>
#include<string>


using namespace std;


/*
2000. ��ת����ǰ׺
����һ���±�� 0 ��ʼ���ַ��� word ��һ���ַ� ch ���ҳ� ch ��һ�γ��ֵ��±� i ����ת word �д��±� 0 ��ʼ��ֱ���±� i ���������±� i �����Ƕ��ַ������ word �в������ַ� ch ������������κβ�����

���磬��� word = "abcdefd" �� ch = "d" ����ô��Ӧ�� ��ת ���±� 0 ��ʼ��ֱ���±� 3 ���������±� 3 ��������ַ��������� "dcbaefd" ��
���� ����ַ��� ��
*/
class Solution {
public:
	string reversePrefix(string word, char ch) {
		int idx = 0;
		for (int i = 0; i < word.size(); ++i) {
			if (word[i] == ch) {
				idx = i;
				break;
			}
		}
		reverse(word.begin(), word.begin() + idx + 1);
		return word;
	}
};
#include<vector>
#include <string>
#include <unordered_set>

using namespace std;

/*
648. �����滻

��Ӣ���У�������һ������ �ʸ�(root) �ĸ�����Դʸ������������һЩ�������һ���ϳ��ĵ��ʡ������ǳ������Ϊ �̳д�(successor)�����磬�ʸ�an�������ŵ��� other(����)�������γ��µĵ��� another(��һ��)��

���ڣ�����һ�������ʸ���ɵĴʵ� dictionary ��һ���ÿո�ָ������γɵľ��� sentence������Ҫ�������е����м̳д��ôʸ��滻��������̳д����������γ����Ĵʸ���������̵Ĵʸ��滻����

����Ҫ����滻֮��ľ��ӡ�
*/

class Solution {
public:
	string replaceWords(vector<string>& dictionary, string sentence) {
		typedef unsigned long long ULL;
		const int p = 131;
		unordered_set<ULL> hash;
		for (auto& s : dictionary)
		{
			ULL h = 0;
			for (auto c : s) h = h * p + c;
			hash.insert(h);
		}

		stringstream ssin(sentence);
		string res, word;
		while (ssin >> word)
		{
			string s;
			ULL h = 0;
			for (auto c : word)
			{
				s += c;
				h = h * p + c;
				if (hash.count(h))
					break;
			}
			res += s + ' ';
		}
		res.pop_back();
		return res;
	}
};
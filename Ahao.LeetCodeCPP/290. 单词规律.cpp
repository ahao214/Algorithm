#include<vector>
#include <string>
#include <unordered_map>

using namespace std;



/*
290. ���ʹ���
����һ�ֹ��� pattern ��һ���ַ��� str ���ж� str �Ƿ���ѭ��ͬ�Ĺ��ɡ�

����� ��ѭ ָ��ȫƥ�䣬���磬 pattern ���ÿ����ĸ���ַ��� str �е�ÿ���ǿյ���֮�������˫�����ӵĶ�Ӧ���ɡ�
*/
class Solution {
public:
	bool wordPattern(string pattern, string s) {
		stringstream raw(s);
		vector<string> words;
		string word;
		while (raw >> word) words.push_back(word);
		unordered_map<char, string> ps;
		unordered_map<string, char> sp;
		if (pattern.size() != words.size()) return false;
		for (int i = 0; i < words.size(); i++)
		{
			char p = pattern[i];
			string str = words[i];
			if (!ps.count(p)) ps[p] = str;
			if (!sp.count(str)) sp[str] = p;
			if (ps[p] != str || sp[str] != p)return false;
		}
		return true;
	}
};

#include<vector>
#include<string>
#include<unordered_map>

using namespace std;



/*
1773. ͳ��ƥ������������Ʒ����
����һ������ items ������ items[i] = [typei, colori, namei] �������� i ����Ʒ�����͡���ɫ�Լ����ơ�

�����һ���������ַ��� ruleKey �� ruleValue ��ʾ�ļ�������

����� i ����Ʒ��������������֮һ������Ϊ����Ʒ������ļ������� ƥ�� ��

ruleKey == "type" �� ruleValue == typei ��
ruleKey == "color" �� ruleValue == colori ��
ruleKey == "name" �� ruleValue == namei ��
ͳ�Ʋ����� ƥ������������Ʒ���� ��
*/
class Solution {
public:
	int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
		int res = 0;
		for (auto& s : items)
		{
			if (ruleKey == "type" && s[0] == ruleValue) res++;
			else if (ruleKey == "color" && s[1] == ruleValue) res++;
			else if (ruleKey == "name" && s[2] == ruleValue) res++;
		}
		return res;
	}
};


class Solution {
public:
	int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
		unordered_map<string, int> dictionary = { {"type", 0}, {"color", 1}, {"name", 2} };
		int res = 0, index = dictionary[ruleKey];
		for (auto&& item : items) {
			if (item[index] == ruleValue) {
				res++;
			}
		}
		return res;
	}
};

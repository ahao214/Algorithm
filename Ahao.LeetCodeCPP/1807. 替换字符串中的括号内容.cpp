#include<vector>
#include<string>
#include <unordered_map>

using namespace std;


/*
1807. �滻�ַ����е���������
����һ���ַ��� s ��������һЩ���Ŷԣ�ÿ�������а���һ�� �ǿ� �ļ���

�ȷ�˵���ַ��� "(name)is(age)yearsold" �У��� ���� ���Ŷԣ��ֱ������ "name" �� "age" ��
��֪��������Ӧ��ֵ����Щ��ϵ�ɶ�ά�ַ������� knowledge ��ʾ������ knowledge[i] = [keyi, valuei] ����ʾ�� keyi ��Ӧ��ֵΪ valuei ��

����Ҫ�滻 ���� �����Ŷԡ������滻һ�����Ŷԣ����������ļ�Ϊ keyi ʱ������Ҫ��

�� keyi �������ö�Ӧ��ֵ valuei �滻��
����� knowledge ���޷���֪ĳ������Ӧ��ֵ������Ҫ�� keyi ���������ʺ� "?" �滻������Ҫ���ţ���
knowledge ��ÿ�������ֻ�����һ�Ρ�s �в�����Ƕ�׵����š�

���㷵���滻 ���� ���ŶԺ�Ľ���ַ�����
*/
class Solution {
public:
	string evaluate(string s, vector<vector<string>>& knowledge) {
		unordered_map<string, string> hash;
		for (auto& e : knowledge) hash[e[0]] = e[1];
		string res;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != '(') res += s[i];
			else
			{
				string key;
				int j = i + 1;
				while (s[j] != ')') key += s[j++];
				i = j;
				if (hash.count(key)) res += hash[key];
				else res += '?';
			}
		}
		return res;
	}
};

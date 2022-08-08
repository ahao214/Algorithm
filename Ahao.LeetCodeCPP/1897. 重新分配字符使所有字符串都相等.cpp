#include<vector>
#include<string>
#include<unordered_map>

using namespace std;


/*
	1897. ���·����ַ�ʹ�����ַ��������
	����һ���ַ������� words���±� �� 0 ��ʼ ��������

	��һ�������У�����ѡ������ ��ͬ �±� i �� j������ words[i] ��һ���ǿ��ַ��������Ž� words[i] �е� ��һ �ַ��ƶ��� words[j] �е� ��һ λ���ϡ�

	���ִ�����ⲽ��������ʹ words �е�ÿ���ַ�������ȣ����� true �����򣬷��� false ��
	*/
class Solution {
public:
	bool makeEqual(vector<string>& words) {
		unordered_map<char, int> cnt;
		for (auto& w : words)
			for (auto c : w)
				cnt[c]++;
		for (auto [k, v] : cnt)
			if (v % words.size())
				return false;
		return true;
	}

};

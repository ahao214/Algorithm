#include<vector>
#include <string>

using namespace std;


/*
833. �ַ����еĲ������滻

���õ�һ���ַ��� s (������ 0 ��ʼ)����������ִ�� k ���滻�������滻�������������Ⱦ�Ϊ k �Ĳ������������indices, sources,  targets��

Ҫ��ɵ� i ���滻����:

��� ���ַ���  sources[i] �Ƿ������ ԭ�ַ��� s ������ indices[i] ����
���û�г��֣� ʲôҲ���� ��
������֣����� targets[i] �滻 �����ַ�����
���磬��� s = "abcd" �� indices[i] = 0 , sources[i] = "ab"�� targets[i] = "eee" ����ô�滻�Ľ������ "eeecd" ��

�����滻�������� ͬʱ ����������ζ���滻������Ӧ��Ӱ��˴˵�����������������֤Ԫ�ؼ䲻���ص� ��

���磬һ�� s = "abc" ��  indices = [0,1] �� sources = ["ab"��"bc"] �Ĳ����������������ɣ���Ϊ "ab" �� "bc" �滻�ص���
�ڶ� s ִ�������滻�����󷵻� ����ַ��� ��

���ַ��� ���ַ������������ַ����С�



ʾ�� 1��



���룺s = "abcd", indexes = [0,2], sources = ["a","cd"], targets = ["eee","ffff"]
�����"eeebffff"
���ͣ�
"a" �� s �е����� 0 ��ʼ�����������滻Ϊ "eee"��
"cd" �� s �е����� 2 ��ʼ�����������滻Ϊ "ffff"��
ʾ�� 2��

���룺s = "abcd", indexes = [0,2], sources = ["ab","ec"], targets = ["eee","ffff"]
�����"eeecd"
���ͣ�
"ab" �� s �е����� 0 ��ʼ�����������滻Ϊ "eee"��
"ec" û�д�ԭʼ�� S �е����� 2 ��ʼ��������û�б��滻��


��ʾ��

1 <= s.length <= 1000
k == indices.length == sources.length == targets.length
1 <= k <= 100
0 <= indexes[i] < s.length
1 <= sources[i].length, targets[i].length <= 50
s ����СдӢ����ĸ���
sources[i] �� targets[i] ����СдӢ����ĸ���
*/
class Solution {
public:
	string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
		int n = indices.size();
		vector<int> id(n);
		for (int i = 0; i < n; i++)
			id[i] = i;
		sort(id.begin(), id.end(), [&](int a, int b) {
			return indices[a] < indices[b];
			});

		for (int i = n - 1; i >= 0; i--)
		{
			int k = id[i];
			int j = indices[k], left = sources[k].size();
			if (s.substr(j, left) == sources[k])
				s = s.substr(0, j) + targets[k] + s.substr(j + left);
		}
		return s;
	}
};
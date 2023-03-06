#include<vector>
#include<string>
#include <unordered_map>

using namespace std;



/*
763. ������ĸ����

����һ���ַ��� s ������Ҫ������ַ�������Ϊ�����ܶ��Ƭ�Σ�ͬһ��ĸ��������һ��Ƭ���С�

ע�⣬���ֽ����Ҫ���㣺�����л��ֽ����˳�����ӣ��õ����ַ�����Ȼ�� s ��

����һ����ʾÿ���ַ���Ƭ�εĳ��ȵ��б�
*/
class Solution {
public:
	vector<int> partitionLabels(string s) {
		vector<int> last(26, 0);
		for (int i = 0; i < s.size(); i++)
		{
			last[s[i] - 'a'] = i;
		}
		vector<int> res;
		int start = 0, end = 0;
		for (int i = 0; i < s.size(); i++)
		{
			end = max(end, last[s[i] - 'a']);
			if (end == i)
			{
				res.push_back(end - start + 1);
				start = end + 1;
			}
		}
		return res;
	}
};





class Solution {
public:
	vector<int> partitionLabels(string s) {
		unordered_map<char, int> last;
		for (int i = 0; i < s.size(); i++)
			last[s[i]] = i;
		vector<int> res;
		int start = 0, end = 0;
		for (int i = 0; i < s.size(); i++)
		{
			end = max(end, last[s[i]]);
			if (i == end)
			{
				res.push_back(end - start + 1);
				start = end = i + 1;
			}
		}
		return res;
	}
};

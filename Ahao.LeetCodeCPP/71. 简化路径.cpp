#include<string>
#include<stack>

using namespace std;




class Solution {
public:
	/*
	Times:O(n)
	Space:O(n)
	*/
	string simplifyPath(string path) {
		stack<string> stk;
		stringstream ss(path);
		string item;
		while (getline(ss, item, '/'))
		{
			if (item == "..")
			{
				if (!stk.empty())
					stk.pop();
			}
			else if (item != "." && item != "")
			{
				stk.push(item);
			}
		}
		string ans;
		while (!stk.empty())
		{
			ans = "/" + stk.top() + ans;
		}
		return ans.empty() ? "/" : ans;
	}
};




/*
71. ��·��
����һ���ַ��� path ����ʾָ��ĳһ�ļ���Ŀ¼�� Unix ��� ����·�� ���� '/' ��ͷ�������㽫��ת��Ϊ���Ӽ��Ĺ淶·����

�� Unix �����ļ�ϵͳ�У�һ���㣨.����ʾ��ǰĿ¼�������⣬������ ��..�� ��ʾ��Ŀ¼�л�����һ����ָ��Ŀ¼�������߶������Ǹ������·������ɲ��֡�������������б�ܣ�����'//'��������Ϊ����б�� '/' �� ���ڴ����⣬�κ�������ʽ�ĵ㣨���磬'...'��������Ϊ�ļ�/Ŀ¼���ơ�

��ע�⣬���ص� �淶·�� ������ѭ������ʽ��

ʼ����б�� '/' ��ͷ��
����Ŀ¼��֮�����ֻ��һ��б�� '/' ��
���һ��Ŀ¼����������ڣ����� �� '/' ��β��
���⣬·���������Ӹ�Ŀ¼��Ŀ���ļ���Ŀ¼��·���ϵ�Ŀ¼���������� '.' �� '..'����
���ؼ򻯺�õ��� �淶·�� ��
*/
class Solution {
public:
	string simplifyPath(string path) {
		path + = '/';
		string res, s;
		for (auto c : path)
		{
			if (res.empty()) res += c;
			else if (c != '/') s += c;
			else
			{
				if (s == "..")
				{
					if (res.size() > 1)
					{
						res.pop_back();
						while (res.back() != '/') res.pop_back();
					}
				}
				else if (s != "" && s != ".")
				{
					res += s + '/';
				}
				s = "";
			}
		}
		if (res.size() > 1) res.pop_back();
		return res;
	}
};
using namespace std;
#include<string>
#include<vector>
#include <unordered_set>

class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> emailSet;
		for (auto& email : emails) {
			string local;
			for (char c : email) {
				if (c == '+' || c == '@') {
					break;
				}
				if (c != '.') {
					local += c;
				}
			}
			emailSet.emplace(local + email.substr(email.find('@')));
		}
		return emailSet.size();
	}
};




/*
929. ���صĵ����ʼ���ַ
ÿ�� ��Ч�����ʼ���ַ ����һ�� ������ ��һ�� ���� ��ɣ��� '@' ���ŷָ�����Сд��ĸ֮�⣬�����ʼ���ַ�����Ժ���һ������ '.' �� '+' ��

���磬�� alice@leetcode.com�У� alice �� ������ ���� leetcode.com �� ���� ��
����ڵ����ʼ���ַ�� ������ �����е�ĳЩ�ַ�֮����Ӿ�㣨'.'��������������ʼ�����ת������������û�е��ͬһ��ַ����ע�⣬�˹��� ������������ ��

���磬"alice.z@leetcode.com�� �� ��alicez@leetcode.com�� ��ת����ͬһ�����ʼ���ַ��
����� ������ ����ӼӺţ�'+'���������Ե�һ���Ӻź�����������ݡ����������ĳЩ�����ʼ���ͬ�����˹��� ������������ ��

���� m.y+name@email.com ��ת���� my@email.com��
����ͬʱʹ������������

����һ���ַ������� emails�����ǻ���ÿ�� emails[i] ����һ������ʼ���
����ʵ���յ��ʼ��Ĳ�ͬ��ַ��Ŀ��
*/
class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> hash;
		for (auto email : emails)
		{
			int at = email.find('@');
			string name;
			for (char c : email.substr(0, at))
			{
				if (c == '+') break;
				else if (c != '.') name += c;
			}
			string domain = email.substr(at + 1);
			hash.insert(name + '@' + domain);
		}
		return hash.size();
	}
};
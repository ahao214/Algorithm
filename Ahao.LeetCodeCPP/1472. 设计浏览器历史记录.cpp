#include<vector>
#include<string>

using namespace std;


/*
1472. ����������ʷ��¼
����һ��ֻ֧�ֵ�����ǩҳ�� ����� ���ʼ���������ҳ�� homepage ������Է�����������վ url ��Ҳ�����������ʷ�к��� steps ����ǰ�� steps ����

����ʵ�� BrowserHistory �ࣺ

BrowserHistory(string homepage) ���� homepage ��ʼ��������ࡣ
void visit(string url) �ӵ�ǰҳ��ת���� url ��Ӧ��ҳ��  ��ִ�д˲�����������ʷǰ���ļ�¼ȫ��ɾ����
string back(int steps) �������ʷ�к��� steps ���������ֻ���������ʷ�к������� x ���� steps > x ����ô��ֻ���� x �����뷵�غ��� ���� steps ���Ժ�� url ��
string forward(int steps) �������ʷ��ǰ�� steps ���������ֻ���������ʷ��ǰ������ x ���� steps > x ����ô��ֻǰ�� x �����뷵��ǰ�� ���� steps���Ժ�� url ��
*/
class Solution {
public:
	vector<string> records;
	int cur;
	void	BrowserHistory(string homepage) {
		records.push_back(homepage);
		cur = 0;
	}

	void visit(string url) {
		records.erase(records.begin() + cur + 1, records.end());
		records.push_back(url);
		cur++;
	}

	string back(int steps) {
		cur = max(0, cur - steps);
		return records[cur];
	}

	string forward(int steps) {
		cur = min((int)records.size() - 1, cur + steps);
		return records[cur];
	}
};


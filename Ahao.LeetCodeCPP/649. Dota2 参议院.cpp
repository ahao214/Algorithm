#include<vector>
#include<string>

using namespace std;



/*
649. Dota2 ����Ժ

Dota2 ����������������Ӫ��Radiant����ԣ��� Dire��ҹ�ʣ�

Dota2 ����Ժ���������ɵĲ���Ա��ɡ����ڲ���Ժϣ����һ�� Dota2 ��Ϸ��ĸı�����������������һ��������Ϊ���̵�ͶƱ���С���ÿһ���У�ÿһλ����Ա��������ʹ����Ȩ���е� һ �

��ֹһ������Ա��Ȩ��������Ա��������һλ����Ա����һ�ֺ����ļ�����ɥʧ ���е�Ȩ�� ��
����ʤ�����������Ա������Ȩ��ͶƱ�Ĳ���Ա���� ͬһ����Ӫ�� ������������ʤ������������Ϸ�е��йر仯��
����һ���ַ��� senate ����ÿ������Ա����Ӫ����ĸ 'R' �� 'D'�ֱ������ Radiant����ԣ��� Dire��ҹ�ʣ���Ȼ������� n ������Ա�������ַ����Ĵ�С���� n��

����Ϊ�����Ĺ��̴Ӹ���˳��ĵ�һ������Ա��ʼ�����һ������Ա��������һ���̽�������ͶƱ����������ʧȥȨ���Ĳ���Ա���ڹ����б�������

����ÿһλ����Ա���㹻��������Ϊ�Լ�������������õĲ��ԣ�����ҪԤ����һ�����ջ�����ʤ������ Dota2 ��Ϸ�о����ı䡣���Ӧ���� "Radiant" �� "Dire" ��
*/
class Solution {
public:
	string predictPartyVictory(string senate) {
		queue<int> r, d;
		for (int i = 0; i < senate.size(); i++)
		{
			if (senate[i] == 'R') r.push(i);
			else d.push(i);
		}

		int n = senate.size();
		while (r.size() && d.size())
		{
			if (r.front() < d.front()) r.push(r.front() + n);
			else d.push(d.front() + n);
			r.pop(), d.pop();
		}
		if (r.size()) return "Radiant";
		return "Dire";
	}
};

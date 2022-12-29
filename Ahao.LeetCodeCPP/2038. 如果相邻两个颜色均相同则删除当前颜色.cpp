using namespace std;
#include<string>

/*
2038. �������������ɫ����ͬ��ɾ����ǰ��ɫ

�ܹ��� n ����ɫƬ���ų�һ�У�ÿ����ɫƬ��Ҫô�� 'A' Ҫô�� 'B' ������һ������Ϊ n ���ַ��� colors ������ colors[i] ��ʾ�� i ����ɫƬ�ε���ɫ��

Alice �� Bob ����һ����Ϸ������ ���� ������ַ�����ɾ����ɫ��Alice ���� ��

���һ����ɫƬ��Ϊ 'A' �� ����������ɫ ������ɫ 'A' ����ô Alice ����ɾ������ɫƬ�Ρ�Alice ������ ɾ���κ���ɫ 'B' Ƭ�Ρ�
���һ����ɫƬ��Ϊ 'B' �� ����������ɫ ������ɫ 'B' ����ô Bob ����ɾ������ɫƬ�Ρ�Bob ������ ɾ���κ���ɫ 'A' Ƭ�Ρ�
Alice �� Bob ���� ���ַ�������ɾ����ɫƬ�Ρ�
�������һ���޷����������������� �� ����Ϸ����һ��� ��ʤ ��
���� Alice �� Bob ���������Ų��ԣ���� Alice ��ʤ���뷵�� true������ Bob ��ʤ������ false��
*/

class Solution {
public:
	bool winnerOfGame(string colors) {
		int freq[2] = { 0,0 };
		char cur = 'C';
		int cnt = 0;
		for (char c : colors) {
			if (c != cur) {
				cur = c;
				cnt = 1;
			}
			else if (++cnt >= 3) {
				++freq[cur - 'A'];
			}
		}
		return freq[0] > freq[1];
	}
};
#include<vector>
#include <string>

using namespace std;



/*
299. ��������Ϸ
���ں�����һ���� �����֣�Bulls and Cows����Ϸ������Ϸ�������£�

д��һ���������֣��������Ѳ���������Ƕ��١�����ÿ�²�һ�Σ���ͻ����һ������������Ϣ����ʾ��

�²��������ж���λ�������ֺ�ȷ��λ�ö��¶��ˣ���Ϊ "Bulls"����ţ����
�ж���λ�������ֲ¶��˵���λ�ò��ԣ���Ϊ "Cows"����ţ����Ҳ����˵����β²����ж���λ�ǹ�ţ���ֿ���ͨ����������ת���ɹ�ţ���֡�
����һ���������� secret �����Ѳ²������ guess �����㷵�ض�������β²����ʾ��

��ʾ�ĸ�ʽΪ "xAyB" ��x �ǹ�ţ������ y ����ţ������A ��ʾ��ţ��B ��ʾ��ţ��

��ע���������ֺ����Ѳ²�����ֶ����ܺ����ظ����֡�
*/
class Solution {
public:
	string getHint(string secret, string guess) {
		int a = 0, b = 0, n = guess.size();
		int ds[10] = { 0 }, dg[10] = { 0 };
		for (int i = 0; i < n; i++)
		{
			int x = secret[i] - '0', y = guess[i] - '0';
			if (x == y) a++;
			ds[x]++, dg[y]++;
		}
		for (int i = 0; i < 10; i++)
			b += min(ds[i], dg[i]);
		b -= a;
		return to_string(a) + 'A' + to_string(b) + 'B';
	}
};
using namespace std;
#include<string>

/*
	12. ����ת��������
	�������ְ������������ַ�:I,V,X,L,C,D��M��
	�ַ�          ��ֵ
	I             1
	V             5
	X             10
	L             50
	C             100
	D             500
	M             1000
	���磬 �������� 2 д�� II ����Ϊ�������е� 1��12 д�� XII ����Ϊ X + II �� 27 д��  XXVII, ��Ϊ XX + V + II ��

	ͨ������£�����������С�������ڴ�����ֵ��ұߡ���Ҳ�������������� 4 ��д�� IIII������ IV������ 1 ������ 5 ����ߣ�����ʾ�������ڴ��� 5 ��С�� 1 �õ�����ֵ 4 ��ͬ���أ����� 9 ��ʾΪ IX���������Ĺ���ֻ�������������������

	I ���Է��� V (5) �� X (10) ����ߣ�����ʾ 4 �� 9��
	X ���Է��� L (50) �� C (100) ����ߣ�����ʾ 40 �� 90��
	C ���Է��� D (500) �� M (1000) ����ߣ�����ʾ 400 �� 900��
	����һ������������תΪ�������֡�
*/
class Solution {	
public:
	string intToRoman(int num) {
		string thousands[] = { "","M","MM","MMM" };
		string hundreds[] = { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
		string tens[] = { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
		string ones[] = { "","I","II","III","IV","V","VI","VII","VIII","IX" };
		return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
	}
};



/*
12. ����ת��������
�������ְ������������ַ��� I�� V�� X�� L��C��D �� M��
�ַ�          ��ֵ
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/
class Solution {
public:
	string intToRoman(int num) {
		int values[] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
		string reps[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };

		string res;
		for (int i = 0; i < 13; i++)
		{
			while (num >= values[i])
			{
				num -= values[i];
				res += reps[i];
			}
		}
		return res;
	}
};


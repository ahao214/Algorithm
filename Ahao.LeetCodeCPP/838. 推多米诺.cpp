#include<vector>
#include <string>

using namespace std;


/*
838. �ƶ���ŵ

n �Ŷ���ŵ�����ų�һ�У���ÿ�Ŷ���ŵ���ƴ�ֱ�������ڿ�ʼʱ��ͬʱ��һЩ����ŵ��������������ơ�

ÿ��һ�룬������ߵĶ���ŵ���ƻ��ƶ���������ڵĶ���ŵ���ơ�ͬ���أ������ұߵĶ���ŵ����Ҳ���ƶ����������Ҳ�����ڶ���ŵ���ơ�

���һ�Ŵ�ֱ�����Ķ���ŵ���Ƶ�����ͬʱ�ж���ŵ���Ƶ���ʱ����������ƽ�⣬ �ù�����Ȼ���ֲ��䡣

�����������ԣ����ǻ���Ϊһ�����ڵ��µĶ���ŵ���Ʋ�����������ڵ��»��Ѿ����µĶ���ŵ����ʩ�Ӷ��������

����һ���ַ��� dominoes ��ʾ��һ�ж���ŵ���Ƶĳ�ʼ״̬�����У�

dominoes[i] = 'L'����ʾ�� i �Ŷ���ŵ���Ʊ�������࣬
dominoes[i] = 'R'����ʾ�� i �Ŷ���ŵ���Ʊ������Ҳ࣬
dominoes[i] = '.'����ʾû���ƶ��� i �Ŷ���ŵ���ơ�
���ر�ʾ����״̬���ַ�����


ʾ�� 1��

���룺dominoes = "RR.L"
�����"RR.L"
���ͣ���һ�Ŷ���ŵ����û�и��ڶ���ʩ�Ӷ��������
ʾ�� 2��


���룺dominoes = ".L.R...LR..L.."
�����"LL.RR.LLRRLL.."


��ʾ��

n == dominoes.length
1 <= n <= 105
dominoes[i] Ϊ 'L'��'R' �� '.'
*/
class Solution {
public:
	string pushDominoes(string dominoes) {
		dominoes = 'L' + dominoes + 'R';
		int n = dominoes.size();
		vector<int> left(n), right(n);
		for (int i = 0, j = 0; i < n; i++)
		{
			if (dominoes[i] != '.') j = i;
			left[i] = j;
		}
		for (int i = n - 1, j = 0; i >= 0; i--)
		{
			if (dominoes[i] != '.') j = i;
			right[i] = j;
		}
		for (int i = 0; i < n; i++)
		{
			char L = dominoes[left[i]], R = dominoes[right[i]];
			if (L == 'L' && R == 'R')dominoes[i] = '.';
			else if (L == 'L' && R == 'L') dominoes[i] = 'L';
			else if (L == 'R' && R == 'R') dominoes[i] = 'R';
			else
			{
				if (i - left[i] < right[i] - i) dominoes[i] = 'R';
				else if (right[i] - i < i - left[i]) dominoes[i] = 'L';
				else dominoes[i] = '.';
			}
		}
		return dominoes.substr(1, n - 2);
	}
};

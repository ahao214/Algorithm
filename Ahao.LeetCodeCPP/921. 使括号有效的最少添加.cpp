#include<string>

using namespace std;


/*
921. ʹ������Ч���������

ֻ���������漸��֮һ�������ַ���������Ч�ģ�

����һ�����ַ���������
�����Ա�д�� AB ��A �� B ���ӣ�, ���� A �� B ������Ч�ַ���������
�����Ա�д�� (A)������ A ����Ч�ַ�����
����һ�������ַ��� s ���ƶ�N�Σ���Ϳ������ַ������κ�λ�ò���һ�����š�

���磬��� s = "()))" ������Բ���һ����ʼ����Ϊ "(()))" ���������Ϊ "())))" ��
���� Ϊʹ����ַ��� s ��Ч��������ӵ�������������
*/

class Solution {
public:
	int MinAddToMakeValid(string s) {
		int res = 0;
		int leftCount = 0;
		for (auto& c : s) {
			if (c == '(') {
				leftCount++;
			}
			else {
				if (leftCount > 0) {
					leftCount--;
				}
				else
				{
					res++;
				}
			}
		}
		res += leftCount;
		return res;
	}
};
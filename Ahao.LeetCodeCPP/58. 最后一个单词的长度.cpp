using namespace std;

#include<string>


class Solution {
	/*
	58. ���һ�����ʵĳ���
	����һ���ַ��� s�������ɵ�����ɣ�����ǰ����һЩ�ո��ַ������������ַ����� ���һ�� ���ʵĳ��ȡ�

	���� ��ָ������ĸ��ɡ��������κοո��ַ���������ַ�����
	*/
public:
	int lengthOfLastWord(string s) {
		/*
		�����������,��¼�µ�һ���ǿո��λ��,Ȼ���������
		��������һ���ո��λ��,��¼�¸�λ��
		����λ�������Ϊ��
		Times:O(n)
		Space:O(1)
		*/

		for (int i = s.size() - 1; i >= 0; i--)
		{
			//�����ո����
			if (s[i] == ' ') continue;
			int j = i - 1;
			while (j >= 0 && s[j] != ' ')
				j--;
			return i - j;
		}
		return 0;
	}
};
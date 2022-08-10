#include<vector>
#include<string>

using namespace std;



/*
1880. ���ĳ�����Ƿ����������֮��
��ĸ�� ��ĸֵ ȡ������ĸ����ĸ���е�λ�ã��� 0 ��ʼ ����������'a' -> 0��'b' -> 1��'c' -> 2���Դ����ơ�

��ĳ����Сд��ĸ��ɵ��ַ��� s ���ԣ��� ��ֵ �͵��ڽ� s ��ÿ����ĸ�� ��ĸֵ ��˳�� ���� �� ת�� �ɶ�Ӧ������

���磬s = "acb" ����������ÿ����ĸ����ĸֵ���Եõ� "021" ��ת��Ϊ�����õ� 21 ��
���������ַ��� firstWord��secondWord �� targetWord ��ÿ���ַ������ɴ� 'a' �� 'j' ���� 'a' �� 'j' ����СдӢ����ĸ��ɡ�

��� firstWord �� secondWord �� ��ֵ֮�� ���� targetWord ����ֵ������ true �����򣬷��� false ��
*/
class Solution {
public:
	int get(string s)
	{
		int res = 0;
		for (auto c : s)
			res = res * 10 + c - 'a';
		return res;
	}

	bool isSumEqual(string firstWord, string secondWord, string targetWord) {
		return get(firstWord) + get(secondWord) == get(targetWord);
	}

};



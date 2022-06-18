#include<vector>
#include<string>

using namespace std;


class Solution {
	/*
	68. �ı����Ҷ���
	����һ���������� words ��һ������ maxWidth �������Ű浥�ʣ�ʹ���Ϊÿ��ǡ���� maxWidth ���ַ������������˶�����ı���

	��Ӧ��ʹ�� ��̰���㷨�� �����ø����ĵ��ʣ�Ҳ����˵�������ܶ����ÿ���з��õ��ʡ���Ҫʱ���ÿո� ' ' ��䣬ʹ��ÿ��ǡ���� maxWidth ���ַ���

	Ҫ�󾡿��ܾ��ȷ��䵥�ʼ�Ŀո����������ĳһ�е��ʼ�Ŀո��ܾ��ȷ��䣬�������õĿո���Ҫ�����Ҳ�Ŀո�����

	�ı������һ��ӦΪ����룬�ҵ���֮�䲻�������Ŀո�

	ע��:

	������ָ�ɷǿո��ַ���ɵ��ַ����С�
	ÿ�����ʵĳ��ȴ��� 0��С�ڵ��� maxWidth��
	���뵥������ words ���ٰ���һ�����ʡ�
	*/
public:
	/*
	Times:O(n*m)
	Space:O(n*m)
	mΪ���ʵ���󳤶�
	*/
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> ans, cur;
		for (int i = 0, curWidth = 0; i < words.size(); i++)
		{
			//С����󳤶ȵ�ʱ��
			if (words[i].length() + curWidth + cur.size() <= maxWidth)
			{
				curWidth += words[i].length();
				cur.push_back(words[i]);
			}
			else
			{
				ans.push_back(fillSpace(cur, maxWidth, false));
				cur = vector<string>{ words[i] };
				curWidth = words[i].length();
			}
		}
		//�����ĵ��ʷ����ȥ
		ans.push_back(fillSpace(cur, maxWidth, true));
		return ans;
	}

	string fillSpace(vector<string>& words, int maxWidth, bool last)
	{
		int curWidth = 0;
		for (int i = 0; i < words.size(); i++)
		{
			if (i != words.size() - 1) words[i] += ' ';
			curWidth += words[i].length();
		}
		if (last || words.size() == 1)
		{
			words[words.size() - 1] += string(maxWidth - curWidth, ' ');
		}
		else
		{
			for (int i = 0; curWidth++ < maxWidth; i = (i + 1) % (words.size() - 1))
			{
				words[i] += ' ';
			}
		}

		string ans;
		for (int i = 0; i < words.size(); i++)
			ans += words[i];
		return ans;
	}
};

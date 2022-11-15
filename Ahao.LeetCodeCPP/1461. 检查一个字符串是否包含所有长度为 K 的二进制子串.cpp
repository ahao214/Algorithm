#include<vector>
#include <unordered_set>

using namespace std;


/*
1461. ���һ���ַ����Ƿ�������г���Ϊ K �Ķ������Ӵ�
����һ���������ַ��� s ��һ������ k ��������г���Ϊ k �Ķ������ַ������� s ���Ӵ����뷵�� true �������뷵�� false ��
*/
class Solution {
public:
	/*
	��s�����г���Ϊk���Ӵ����洢��һ����ϣ������
	�����ϣ�������ֵ���ܸ����Ƿ����2^k
	Ϊ�˽�ʡʱ��Ϳռ䣬��ϣ�����汣��ĳ���Ϊk���Ӵ�����Ӧ��ʮ��������
	*/
	bool hasAllCodes(string s, int k) {
		unordered_set<int> S;
		for (int i = 0, w = 0; i < s.size(); i++)
		{
			w = w * 2 + s[i] - '0';
			if (i >= k) w -= s[i - k] - '0' << k;
			if (i >= k - 1) S.insert(w);
		}
		return S.size() == (1 << k);
	}
};

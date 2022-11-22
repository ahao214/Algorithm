#include<vector>
#include <unordered_set>
#include <string>

using namespace std;


/*
1496. �ж�·���Ƿ��ཻ
����һ���ַ��� path������ path[i] ��ֵ������ 'N'��'S'��'E' ���� 'W'���ֱ��ʾ�򱱡����ϡ��򶫡������ƶ�һ����λ��

��Ӷ�άƽ���ϵ�ԭ�� (0, 0) ����ʼ�������� path ��ָʾ��·�����ߡ�

���·�����κ�λ�����������ཻ��Ҳ�����ߵ�֮ǰ�Ѿ��߹���λ�ã��뷵�� true �����򣬷��� false ��
*/
class Solution {
public:
	//����һ����ϣ�����߹��ĵ���뵽��ϣ���У��ж��Ƿ����ظ��ĵ�
	bool isPathCrossing(string path) {
		unordered_set<string> hash;
		hash.insert("0 0");
		int x = 0, y = 0;
		for (auto c : path)
		{
			if (c == 'N') x--;
			else if (c == 'S') x++;
			else if (c == 'W') y--;
			else y++;

			string s = to_string(x) + ' ' + to_string(y);
			if (hash.count(s)) return true;
		}
		return false;
	}
};

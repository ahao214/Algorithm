#include<vector>
#include <algorithm>
#include <queue>

using namespace std;


/*
1996. ��Ϸ������ɫ������

�����ڲμ�һ�����ɫ��Ϸ��ÿ����ɫ����������Ҫ���ԣ����� �� ���� ������һ����ά�������� properties ������ properties[i] = [attacki, defensei] ��ʾ��Ϸ�е� i ����ɫ�����ԡ�

�������һ��������ɫ�Ĺ����ͷ����ȼ� ���ϸ���� �ý�ɫ�Ĺ����ͷ����ȼ�������Ϊ�ý�ɫΪ ����ɫ ������ʽ�أ������Ϊ��ɫ i ���� ���ڵ���һ����ɫ j ����ô attackj > attacki �� defensej > defensei ��

���� ����ɫ ��������
*/
class Solution {
public:
	int numberOfWeekCharacters(vector<vector<int>>& properties) {
		sort(properties.begin(), properties.end(), [](const vector<int>& p1, const vector<int>& p2) {
			if (p1[0] != p2[0])
				return p1[0] < p2[0];
			return p1[1] < p2[1];
			});
		priority_queue<int> q;
		int n = properties.size(), mx = properties[n - 1][0], my = properties[n - 1][1], ans = 0;
		for (int i = n - 2; i >= 0; i--) {
			//�ϸ����
			if (properties[i][0] < mx && properties[i][1] < my)
				ans++;
			//x���ڵ�ǰmx����y�ϸ����֮ǰ��my
			else if (properties[i][0] == mx && !q.empty() && properties[i][1] < q.top())
				ans++;
			else if (properties[i][1] > my) {
				//����mx��my ��һ�������y����my
				q.push(my);
				mx = properties[i][0];
				my = properties[i][1];
			}
		}
		return ans;
	}
};
#include<vector>

using namespace std;



/*
2509. ��ѯ���л��ĳ���
����һ������ n ����ʾ����һ�ú��� 2n - 1 ���ڵ�� ��ȫ������ �����ڵ�ı���� 1 �����б����[1, 2n - 1 - 1] ֮�䣬���Ϊ val �Ľڵ㶼�������ӽڵ㣬���㣺

���ӽڵ�ı��Ϊ 2 * val
���ӽڵ�ı��Ϊ 2 * val + 1
����һ������Ϊ m �Ĳ�ѯ���� queries ������һ����ά�������飬���� queries[i] = [ai, bi] ������ÿ����ѯ�������������Ľ⣺

�ڽڵ���Ϊ ai �� bi ֮�����һ���ߡ�
���ͼ�л��ĳ��ȡ�
ɾ���ڵ���Ϊ ai �� bi ֮������ӵıߡ�
ע�⣺

�� �ǿ�ʼ�ͽ�����ͬһ�ڵ��һ��·����·����ÿ���߶�ֻ�ᱻ����һ�Ρ�
���ĳ����ǻ��бߵ���Ŀ��
��������Ӷ���ıߺ�������֮����ܻ��ж����ߡ�
���㷵��һ������Ϊ m ������ answer ������ answer[i] �ǵ� i ����ѯ�Ľ����
*/
class Solution {
public:
	vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
		vector<int> result;
		for (auto& q : queries) {
			int a = q[0];
			int b = q[1];
			int count = 0;
			while (a != b) {
				if (a > b) {
					a = a / 2;
				}
				else {
					b = b / 2;
				}
				count++;
			}
			result.push_back(count + 1);
		}
		return result;
	}
};

#include<vector>

using namespace std;


/*
1462. �γ̱� IV
���ܹ���Ҫ�� n �ſΣ��γ̱������Ϊ 0 �� n-1 ��

�еĿλ���ֱ�ӵ����޿γ̣�����������Ͽγ� 0 ����������Ͽγ� 1 ����ô���� [1,0] ���Ե���ʽ�������޿γ����ԡ�

����γ����� n ��һ��ֱ�����޿γ������б� prerequisite ��һ����ѯ���б� queries ��

����ÿ����ѯ�� queries[i] �����ж� queries[i][0] �Ƿ��� queries[i][1] �����޿γ̡�

�뷵��һ������ֵ�б��б���ÿ��Ԫ�����ηֱ��Ӧ queries ÿ����ѯ�Ե��жϽ����

ע�⣺����γ� a �ǿγ� b �����޿γ��ҿγ� b �ǿγ� c �����޿γ̣���ô�γ� a Ҳ�ǿγ� c �����޿γ̡�
*/
class Solution {
public:
	vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

		vector<vector<bool>> d(numCourses, vector<bool>(numCourses));

		for (auto e : prerequisites) d[e[0]][e[1]] = true;
		for (int k = 0; k < numCourses; k++)
		{
			for (int i = 0; i < numCourses; i++)
				for (int j = 0; j < numCourses; j++)
					if (d[i][k] && d[k][j])
						d[i][j] = true;
		}

		vector<bool> res;
		for (auto q : queries)
			res.push_back(d[q[0]][q[1]]);
		return res;
	}
};

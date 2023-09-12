#include<vector>
#include <queue>

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




class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> g(numCourses);
        vector<int> indgree(numCourses, 0);
        vector<vector<bool>> isPre(numCourses, vector<bool>(numCourses, false));
        for (auto& p : prerequisites) {
            ++indgree[p[1]];
            g[p[0]].push_back(p[1]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indgree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (auto& ne : g[cur]) {
                isPre[cur][ne] = true;
                for (int i = 0; i < numCourses; ++i) {
                    isPre[i][ne] = isPre[i][ne] | isPre[i][cur];
                }
                --indgree[ne];
                if (indgree[ne] == 0) {
                    q.push(ne);
                }
            }
        }
        vector<bool> res;
        for (auto& query : queries) {
            res.push_back(isPre[query[0]][query[1]]);
        }
        return res;
    }
};



class Solution {
public:
    void dfs(vector<vector<int>>& g, vector<vector<bool>>& isPre, vector<bool>& vi, int cur) {
        if (vi[cur]) {
            return;
        }
        vi[cur] = true;
        for (auto& ne : g[cur]) {
            dfs(g, isPre, vi, ne);
            isPre[cur][ne] = true;
            for (int i = 0; i < isPre.size(); ++i) {
                isPre[cur][i] = isPre[cur][i] | isPre[ne][i];
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> g(numCourses);
        vector<bool> vi(numCourses, false);
        vector<vector<bool>> isPre(numCourses, vector<bool>(numCourses, false));
        for (auto& p : prerequisites) {
            g[p[0]].push_back(p[1]);
        }
        for (int i = 0; i < numCourses; ++i) {
            dfs(g, isPre, vi, i);
        }
        vector<bool> res;
        for (auto& query : queries) {
            res.push_back(isPre[query[0]][query[1]]);
        }
        return res;
    }
};


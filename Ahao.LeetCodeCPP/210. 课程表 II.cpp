#include<vector>
#include <queue>

using namespace std;

/*
210. �γ̱� II

�������ܹ��� numCourses �ſ���Ҫѡ����Ϊ 0 �� numCourses - 1������һ������ prerequisites ������ prerequisites[i] = [ai, bi] ����ʾ��ѡ�޿γ� ai ǰ ���� ��ѡ�� bi ��

���磬��Ҫѧϰ�γ� 0 ������Ҫ����ɿγ� 1 ��������һ��ƥ������ʾ��[0,1] ��
������Ϊ��ѧ�����пγ������ŵ�ѧϰ˳�򡣿��ܻ��ж����ȷ��˳����ֻҪ���� ����һ�� �Ϳ����ˡ����������������пγ̣����� һ�������� ��

*/


class Solution {
private:
    // �洢����ͼ
    vector<vector<int>> edges;
    // ���ÿ���ڵ��״̬��0=δ������1=�����У�2=�����
    vector<int> visited;
    // ��������ģ��ջ���±� 0 Ϊջ�ף�n-1 Ϊջ��
    vector<int> result;
    // �ж�����ͼ���Ƿ��л�
    bool valid = true;

public:
    void dfs(int u) {
        // ���ڵ���Ϊ�������С�
        visited[u] = 1;
        // ���������ڽڵ�
        // ֻҪ�����л�������ֹͣ����
        for (int v : edges[u]) {
            // �����δ��������ô�������ڽڵ�
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            }
            // ����������С�˵���ҵ��˻�
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        // ���ڵ���Ϊ������ɡ�
        visited[u] = 2;
        // ���ڵ���ջ
        result.push_back(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        // ÿ����ѡһ����δ�������Ľڵ㣬��ʼ���������������
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        if (!valid) {
            return {};
        }
        // ���û�л�����ô������������
        // ע���±� 0 Ϊջ�ף������Ҫ�����鷴�����
        reverse(result.begin(), result.end());
        return result;
    }
};



class Solution {
private:
    // �洢����ͼ
    vector<vector<int>> edges;
    // �洢ÿ���ڵ�����
    vector<int> indeg;
    // �洢��
    vector<int> result;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        // ���������Ϊ 0 �Ľڵ���������
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            // �Ӷ���ȡ��һ���ڵ�
            int u = q.front();
            q.pop();
            // �������
            result.push_back(u);
            for (int v : edges[u]) {
                --indeg[v];
                // ������ڽڵ� v �����Ϊ 0���Ϳ���ѡ v ��Ӧ�Ŀγ���
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (result.size() != numCourses) {
            return {};
        }
        return result;
    }
};


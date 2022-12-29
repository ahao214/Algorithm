using namespace std;
#include<vector>
#include<queue>

/*
2039. ������е�ʱ��

����һ���� n ���������ļ�������磬���������Ϊ 0 �� n - 1 ��ͬʱ����һ����ά�������� edges ������ edges[i] = [ui, vi] ��ʾ������ ui �� vi ֮����һ����Ϣ��·���� һ�� ������֮����Դ��� ���� ��Ŀ����Ϣ���ٸ���һ������Ϊ n ���±�� 0 ��ʼ���������� patience ��

��Ŀ��֤���з��������� ��ͨ �ģ�Ҳ����˵һ����Ϣ�����������������������ͨ����Щ��Ϣ��·ֱ�ӻ��ӵص����κ�������������

���Ϊ 0 �ķ������� �� ������������������Ϊ ���� ��������ÿ�����ݷ�������Ҫ����������������Ϣ�����ȴ��ظ�����Ϣ�ڷ�����֮�䰴 ���� ��·���䣬Ҳ����˵ÿ����Ϣ������ ����ʱ�� �����������������������ᴦ�� ���� �µ������Ϣ�� ���� ����ÿ����Ϣ��ʱ��·�� ������ ���ͻظ���Ϣ��

�� 0 ��Ŀ�ʼ���������ݷ��������ᷢ�͸�����Ҫ�������Ϣ���ӵ� 1 �뿪ʼ��ÿ һ���� ��ʼ ʱ��ÿ�����ݷ��������������Ƿ��յ������������Ļظ���Ϣ�������·�����Ϣ�Ļظ���Ϣ����

�����û�յ��κλظ���Ϣ����ô�÷������������� �ط� ��Ϣ�����ݷ����� i ÿ patience[i] �붼���ط�һ����Ϣ��Ҳ����˵�����ݷ����� i ����һ�η�����Ϣ������������� patience[i] �� �� ���ط�һ����Ϣ������������
���򣬸����ݷ����� �����ط� ��Ϣ��
��û���κ���Ϣ����·�ϴ�����ߵ���ĳ������ʱ���ü���������Ϊ ���� ״̬��

�뷵�ؼ���������Ϊ ���� ״̬�� �������� ��
*/

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);
        for (auto& v : edges) {
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
        }

        queue<int> qu;
        qu.emplace(0);
        visit[0] = true;
        int dist = 1;
        int ans = 0;
        while (!qu.empty()) {
            int sz = qu.size();
            for (int i = 0; i < sz; ++i) {
                int curr = qu.front();
                qu.pop();
                for (auto& v : adj[curr]) {
                    if (visit[v]) {
                        continue;
                    }
                    qu.emplace(v);
                    int time = patience[v] * ((2 * dist - 1) / patience[v]) + 2 * dist + 1;
                    ans = max(ans, time);
                    visit[v] = true;
                }
            }
            dist++;
        }
        return ans;
    }
};

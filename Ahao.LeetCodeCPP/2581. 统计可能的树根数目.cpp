#include<vector>
#include<unordered_set>


using namespace std;



/*
2581. ͳ�ƿ��ܵ�������Ŀ

Alice ��һ�� n ���ڵ�������ڵ���Ϊ 0 �� n - 1 ������һ������Ϊ n - 1 �Ķ�ά�������� edges ��ʾ������ edges[i] = [ai, bi] ����ʾ���нڵ� ai �� bi ֮����һ���ߡ�

Alice ��Ҫ Bob �ҵ�������ĸ��������� Bob ��������������ɴ� �²� ��ÿһ�β²⣬Bob ���������飺

ѡ������ ����� ������ u �� v �������б�����ڱ� [u, v] ��
Bob �²����� u �� v �� ���ڵ� ��
Bob �Ĳ²��ö�ά�������� guesses ��ʾ������ guesses[j] = [uj, vj] ��ʾ Bob �� uj �� vj �ĸ��ڵ㡣

Alice �ǳ���������������ش� Bob �Ĳ²⣬ֻ���� Bob ��Щ�²����� ���� �� k ���²�Ľ��Ϊ true ��

�����ά�������� edges ��Bob �����в²������ k �����㷵�ؿ��ܳ�Ϊ������ �ڵ���Ŀ �����û�������������򷵻� 0��
*/
class Solution {
    vector<int> next[100005];
    unordered_set<int> guess[100005];
    int k;
    int ret = 0;
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        this->k = k;
        int n = edges.size() + 1;
        for (auto& e : edges)
        {
            next[e[0]].push_back(e[1]);
            next[e[1]].push_back(e[0]);
        }
        for (auto& g : guesses)
            guess[g[0]].insert(g[1]);

        int count = dfs(0, -1);

        dfs2(0, -1, count);

        return ret;
    }

    int dfs(int cur, int parent)
    {
        int count = 0;
        for (int nxt : next[cur])
        {
            if (nxt == parent) continue;
            count += dfs(nxt, cur);
            if (guess[cur].find(nxt) != guess[cur].end())
                count += 1;
        }
        return count;
    }

    void dfs2(int cur, int parent, int count)
    {
        if (count >= k) ret++;
        for (int nxt : next[cur])
        {
            if (nxt == parent) continue;
            int temp = count;
            if (guess[cur].find(nxt) != guess[cur].end())
                temp -= 1;
            if (guess[nxt].find(cur) != guess[nxt].end())
                temp += 1;
            dfs2(nxt, cur, temp);
        }
    }
};
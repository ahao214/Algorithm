#include<vector>
#include <numeric>


using namespace std;


/*
1566. 重复至少 K 次且长度为 M 的模式
给你一个正整数数组 arr，请你找出一个长度为 m 且在数组中至少重复 k 次的模式。

模式 是由一个或多个值组成的子数组（连续的子序列），连续 重复多次但 不重叠 。 模式由其长度和重复次数定义。

如果数组中存在至少重复 k 次且长度为 m 的模式，则返回 true ，否则返回  false 。
*/
class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        for (int i = 0; i + k * m <= n; i++)
        {
            bool flag = true;
            for (int j = i; j < i + k * m; j++)
            {
                if (arr[j] != arr[i + (j - i) % m])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return true;
        }
        return false;
    }
};



/*
1467. 两个盒子中球的颜色数相同的概率
*/
class Solution {
    int C[10][10];
    vector<int>balls;
    long long all = 0;
    long long good = 0;
public:
    double getProbability(vector<int>& balls)
    {
        int n = balls.size();
        this->balls = balls;

        for (int i = 0; i <= 8; ++i) {
            C[i][i] = C[i][0] = 1;
            for (int j = 1; j < i; ++j) {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }

        vector<int>set1(n);
        vector<int>set2(n);
        dfs(0, set1, set2);

        return good * 1.0 / all;
    }

    void dfs(int k, vector<int>& set1, vector<int>& set2)
    {
        if (k == balls.size())
        {
            if (accumulate(set1.begin(), set1.end(), 0) != accumulate(set2.begin(), set2.end(), 0))
                return;

            long long p = 1;
            for (int i = 0; i < balls.size(); i++)
                p *= C[balls[i]][set1[i]];

            all += p;

            int cnt1 = 0, cnt2 = 0;
            for (auto x : set1) if (x > 0) cnt1 += 1;
            for (auto x : set2) if (x > 0) cnt2 += 1;

            if (cnt1 == cnt2)
                good += p;

            return;
        }

        for (int i = 0; i <= balls[k]; i++)
        {
            set1[k] += i;
            set2[k] += balls[k] - i;
            dfs(k + 1, set1, set2);
            set1[k] -= i;
            set2[k] -= balls[k] - i;
        }
    }
};
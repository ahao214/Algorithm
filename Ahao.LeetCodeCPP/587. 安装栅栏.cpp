using namespace std;
#include<vector>
#include <stack>
#include <algorithm>


//����һ��Jarvis�㷨
class Solution {
public:
    int cross(vector<int>& p, vector<int>& q, vector<int>& r) {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n < 4) {
            return trees;
        }
        int leftMost = 0;
        for (int i = 0; i < n; i++) {
            if (trees[i][0] < trees[leftMost][0]) {
                leftMost = i;
            }
        }

        vector<vector<int>> res;
        vector<bool> visit(n, false);
        int p = leftMost;
        do {
            int q = (p + 1) % n;
            for (int r = 0; r < n; r++) {
                /* ��� r �� pq ���Ҳ࣬�� q = r */
                if (cross(trees[p], trees[q], trees[r]) < 0) {
                    q = r;
                }
            }
            /* �Ƿ���ڵ� i, ʹ�� p ��q ��i ��ͬһ��ֱ���� */
            for (int i = 0; i < n; i++) {
                if (visit[i] || i == p || i == q) {
                    continue;
                }
                if (cross(trees[p], trees[q], trees[i]) == 0) {
                    res.emplace_back(trees[i]);
                    visit[i] = true;
                }
            }
            if (!visit[q]) {
                res.emplace_back(trees[q]);
                visit[q] = true;
            }
            p = q;
        } while (p != leftMost);
        return res;
    }
};

//������: Graham �㷨
class Solution {
public:
    int cross(const vector<int>& p, const vector<int>& q, const vector<int>& r) {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }

    int distance(const vector<int>& p, const vector<int>& q) {
        return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n < 4) {
            return trees;
        }
        int bottom = 0;
        /* �ҵ� y ��С�ĵ� bottom*/
        for (int i = 0; i < n; i++) {
            if (trees[i][1] < trees[bottom][1]) {
                bottom = i;
            }
        }
        swap(trees[bottom], trees[0]);
        /* �� bottom ԭ�㣬���ռ�����ĽǶȴ�С�������� */
        sort(trees.begin() + 1, trees.end(), [&](const vector<int>& a, const vector<int>& b) {
            int diff = cross(trees[0], a, b) - cross(trees[0], b, a);
            if (diff == 0) {
                return distance(trees[0], a) < distance(trees[0], b);
            }
            else {
                return diff > 0;
            }
            });
        /* ����͹���������ͬһ��ֱ�ߵ�Ԫ�ذ��վ����С����������� */
        int r = n - 1;
        while (r >= 0 && cross(trees[0], trees[n - 1], trees[r]) == 0) {
            r--;
        }
        for (int l = r + 1, h = n - 1; l < h; l++, h--) {
            swap(trees[l], trees[h]);
        }
        stack<int> st;
        st.emplace(0);
        st.emplace(1);
        for (int i = 2; i < n; i++) {
            int top = st.top();
            st.pop();
            /* �����ǰԪ����ջ��������Ԫ�ع��ɵ�����˳ʱ����ת���򵯳�ջ��Ԫ�� */
            while (!st.empty() && cross(trees[st.top()], trees[top], trees[i]) < 0) {
                top = st.top();
                st.pop();
            }
            st.emplace(top);
            st.emplace(i);
        }

        vector<vector<int>> res;
        while (!st.empty()) {
            res.emplace_back(trees[st.top()]);
            st.pop();
        }
        return res;
    }
};


//������: Andrew �㷨
class Solution {
public:
    int cross(const vector<int>& p, const vector<int>& q, const vector<int>& r) {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n < 4) {
            return trees;
        }
        /* ���� x ��С����������� x ��ͬ������ y �Ĵ�С�������� */
        sort(trees.begin(), trees.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
            });
        vector<int> hull;
        vector<bool> used(n, false);
        /* hull[0] ��Ҫ��ջ���Σ������б�� */
        hull.emplace_back(0);
        /* ���͹�����°벿�� */
        for (int i = 1; i < n; i++) {
            while (hull.size() > 1 && cross(trees[hull[hull.size() - 2]], trees[hull.back()], trees[i]) < 0) {
                used[hull.back()] = false;
                hull.pop_back();
            }
            used[i] = true;
            hull.emplace_back(i);
        }
        int m = hull.size();
        /* ���͹�����ϰ벿�� */
        for (int i = n - 2; i >= 0; i--) {
            if (!used[i]) {
                while (hull.size() > m && cross(trees[hull[hull.size() - 2]], trees[hull.back()], trees[i]) < 0) {
                    used[hull.back()] = false;
                    hull.pop_back();
                }
                used[i] = true;
                hull.emplace_back(i);
            }
        }
        /* hull[0] ͬʱ����͹�����ϰ벿�ּ�⣬�����ȥ���ظ��� hull[0] */
        hull.pop_back();
        vector<vector<int>> res;
        for (auto& v : hull) {
            res.emplace_back(trees[v]);
        }
        return res;
    }
};

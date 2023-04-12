#include<vector>
#include <string>
#include <random>

using namespace std;

/*
1147. 段式回文

你会得到一个字符串 text 。你应该把它分成 k 个子字符串 (subtext1, subtext2，…， subtextk) ，要求满足:

subtexti 是 非空 字符串
所有子字符串的连接等于 text ( 即subtext1 + subtext2 + ... + subtextk == text )
对于所有 i 的有效值( 即 1 <= i <= k ) ，subtexti == subtextk - i + 1 均成立
返回k可能最大值。
*/

class Solution {
public:
    bool judge(const string& text, int l1, int l2, int len) {
        while (len--) {
            if (text[l1] != text[l2]) {
                return false;
            }
            ++l1;
            ++l2;
        }
        return true;
    }
    int longestDecomposition(string text) {
        int n = text.size();
        int res = 0;
        int l = 0, r = n - 1;
        while (l <= r) {
            int len = 1;
            while (l + len - 1 < r - len + 1) {
                if (judge(text, l, r - len + 1, len)) {
                    res += 2;
                    break;
                }
                ++len;
            }
            if (l + len - 1 >= r - len + 1) {
                ++res;
            }
            l += len;
            r -= len;
        }
        return res;
    }
};


class Solution {
public:
    vector<long long> pre1, pre2;
    vector<long long> pow1, pow2;
    static constexpr int MOD1 = 1000000007;
    static constexpr int MOD2 = 1000000009;
    int Base1, Base2;

    void init(string& s) {
        mt19937 gen{ random_device{}() };
        Base1 = uniform_int_distribution<int>(1e6, 1e7)(gen);
        Base2 = uniform_int_distribution<int>(1e6, 1e7)(gen);
        while (Base2 == Base1) {
            Base2 = uniform_int_distribution<int>(1e6, 1e7)(gen);
        }
        int n = s.size();
        pow1.resize(n);
        pow2.resize(n);
        pre1.resize(n + 1);
        pre2.resize(n + 1);
        pow1[0] = pow2[0] = 1;
        pre1[1] = pre2[1] = s[0];
        for (int i = 1; i < n; ++i) {
            pow1[i] = (pow1[i - 1] * Base1) % MOD1;
            pow2[i] = (pow2[i - 1] * Base2) % MOD2;
            pre1[i + 1] = (pre1[i] * Base1 + s[i]) % MOD1;
            pre2[i + 1] = (pre2[i] * Base2 + s[i]) % MOD2;
        }
    }

    pair<int, int> getHash(int l, int r) {
        return { (pre1[r + 1] - ((pre1[l] * pow1[r + 1 - l]) % MOD1) + MOD1) % MOD1, (pre2[r + 1] - ((pre2[l] * pow2[r + 1 - l]) % MOD2) + MOD2) % MOD2 };
    }

    int longestDecomposition(string text) {
        init(text);
        int n = text.size();
        int res = 0;
        int l = 0, r = n - 1;
        while (l <= r) {
            int len = 1;
            while (l + len - 1 < r - len + 1) {
                if (getHash(l, l + len - 1) == getHash(r - len + 1, r)) {
                    res += 2;
                    break;
                }
                ++len;
            }
            if (l + len - 1 >= r - len + 1) {
                ++res;
            }
            l += len;
            r -= len;
        }
        return res;
    }
};

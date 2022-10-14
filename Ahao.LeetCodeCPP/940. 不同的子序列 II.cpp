#include<vector>
#include<string>

using namespace std;


/*
940. ��ͬ�������� II
����һ���ַ��� s������ s �� ��ͬ�ǿ������� �ĸ�������Ϊ������ܴܺ����Է��ش���Ҫ�� 10^9 + 7 ȡ�� ��

�ַ����� ������ �Ǿ���ԭ�ַ���ɾ��һЩ��Ҳ���ܲ�ɾ�����ַ������ı�ʣ���ַ����λ�õ�һ�����ַ�����

���磬"ace" �� "abcde" ��һ�������У��� "aec" ���ǡ�
*/

class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> last(26, -1);

        int n = s.size();
        vector<int> f(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (last[j] != -1) {
                    f[i] = (f[i] + f[last[j]]) % mod;
                }
            }
            last[s[i] - 'a'] = i;
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (last[i] != -1) {
                ans = (ans + f[last[i]]) % mod;
            }
        }
        return ans;
    }

private:
    static constexpr int mod = 1000000007;
};



class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> g(26, 0);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int total = 1;
            for (int j = 0; j < 26; ++j) {
                total = (total + g[j]) % mod;
            }
            g[s[i] - 'a'] = total;
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + g[i]) % mod;
        }
        return ans;
    }

private:
    static constexpr int mod = 1000000007;
};



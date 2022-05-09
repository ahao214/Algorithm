using namespace std;
#include<vector>
#include<string>

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length(), lo = 0, hi = n;
        vector<int> perm(n + 1);
        for (int i = 0; i < n; ++i) {
            perm[i] = s[i] == 'I' ? lo++ : hi--;
        }
        perm[n] = lo; // ���ʣ��һ��������ʱ lo == hi
        return perm;
    }
};

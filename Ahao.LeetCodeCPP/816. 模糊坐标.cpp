#include<vector>
#include <string>

using namespace std;


/*
816. ģ������

������һЩ��ά���꣬�� "(1, 3)" �� "(2, 0.5)"��Ȼ�������Ƴ����ж��ţ�С����Ϳո񣬵õ�һ���ַ���S���������п��ܵ�ԭʼ�ַ�����һ���б��С�

ԭʼ�������ʾ��������ڶ�����㣬���Բ������������"00", "0.0", "0.00", "1.0", "001", "00.01"��һЩ������С��������ʾ���ꡣ���⣬һ��С����ǰ���ٴ���һ����������Ҳ������֡�.1����ʽ�����֡�

��󷵻ص��б����������˳��ġ�����ע�ⷵ�ص����������м䣨����֮�󣩶���һ���ո�
*/

class Solution {
public:
    vector<string> getPos(string s) {
        vector<string> pos;
        if (s[0] != '0' || s == "0") pos.push_back(s);
        for (int p = 1; p < s.size(); ++p) {
            if ((p != 1 && s[0] == '0') || s.back() == '0') continue;
            pos.push_back(s.substr(0, p) + "." + s.substr(p));
        }
        return pos;
    }
    vector<string> ambiguousCoordinates(string s) {
        int n = s.size() - 2;
        vector<string> res;
        s = s.substr(1, s.size() - 2);
        for (int l = 1; l < n; ++l) {
            vector<string> lt = getPos(s.substr(0, l));
            if (lt.empty()) continue;
            vector<string> rt = getPos(s.substr(l));
            if (rt.empty()) continue;
            for (auto& i : lt) {
                for (auto& j : rt) {
                    res.push_back("(" + i + ", " + j + ")");
                }
            }
        }
        return res;
    }
};

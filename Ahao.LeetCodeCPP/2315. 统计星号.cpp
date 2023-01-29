#include<vector>
#include <string>

using namespace std;

/*
2315. ͳ���Ǻ�

����һ���ַ��� s ��ÿ ���� �������� '|' Ϊ һ�� ������֮����һ���͵ڶ��� '|' Ϊһ�ԣ��������͵��ĸ� '|' Ϊһ�ԣ��Դ����ơ�

���㷵�� ���� ���߶�֮�䣬s �� '*' ����Ŀ��

ע�⣬ÿ������ '|' ���� ǡ�� ����һ���ԡ�
*/


class Solution {
public:
    int countAsterisks(string s) {
        bool valid = true;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '|') {
                valid = !valid;
            }
            else if (c == '*' && valid) {
                res++;
            }
        }
        return res;
    }
};

#include<vector>
#include <string>

using namespace std;


/*
2696. ɾ���Ӵ�����ַ�����С����

����һ������ ��д Ӣ���ַ���ɵ��ַ��� s ��

����ԶԴ��ַ���ִ��һЩ��������ÿһ�������У�����Դ� s ��ɾ�� ��һ�� "AB" �� "CD" ���ַ�����

ͨ��ִ�в�����ɾ������ "AB" �� "CD" �Ӵ������ؿɻ�õ������ַ����� ��С ���ܳ��ȡ�

ע�⣬ɾ���Ӵ����������ӳ����ַ������ܻ�����µ� "AB" �� "CD" �Ӵ���

*/

class Solution {
public:
    int minLength(string s) {
        vector<int> st;
        for (char c : s) {
            st.push_back(c);
            int m = st.size();
            if (m >= 2 &&
                (st[m - 2] == 'A' && st[m - 1] == 'B' ||
                    st[m - 2] == 'C' && st[m - 1] == 'D')) {
                st.pop_back();
                st.pop_back();
            }
        }
        return st.size();
    }
};

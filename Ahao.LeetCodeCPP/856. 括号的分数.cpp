#include<vector>
#include<string>
#include<stack>

using namespace std;


//����һ������
class Solution {
public:
    int scoreOfParentheses(string s) {
        if (s.size() == 2) {
            return 1;
        }
        int bal = 0, n = s.size(), len;
        for (int i = 0; i < n; i++) {
            bal += (s[i] == '(' ? 1 : -1);
            if (bal == 0) {
                len = i + 1;
                break;
            }
        }
        if (len == n) {
            return 2 * scoreOfParentheses(s.substr(1, n - 2));
        }
        else {
            return scoreOfParentheses(s.substr(0, len)) + scoreOfParentheses(s.substr(len, n - len));
        }
    }
};


//��������ջ
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for (auto c : s) {
            if (c == '(') {
                st.push(0);
            }
            else {
                int v = st.top();
                st.pop();
                st.top() += max(2 * v, 1);
            }
        }
        return st.top();
    }
};


//���������������շ�����
class Solution {
public:
    int scoreOfParentheses(string s) {
        int bal = 0, n = s.size(), res = 0;
        for (int i = 0; i < n; i++) {
            bal += (s[i] == '(' ? 1 : -1);
            if (s[i] == ')' && s[i - 1] == '(') {
                res += 1 << bal;
            }
        }
        return res;
    }
};


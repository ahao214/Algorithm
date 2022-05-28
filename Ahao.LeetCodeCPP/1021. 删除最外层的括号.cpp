using namespace std;

#include<string>
#include<stack>

//����һ��ջ
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        stack<char> st;
        for (auto c : s) {
            if (c == ')') {
                st.pop();
            }
            if (!st.empty()) {
                res.push_back(c);
            }
            if (c == '(') {
                st.emplace(c);
            }
        }
        return res;
    }
};


//������������
class Solution {
public:
    string removeOuterParentheses(string s) {
        int level = 0;
        string res;
        for (auto c : s) {
            if (c == ')') {
                level--;
            }
            if (level) {
                res.push_back(c);
            }
            if (c == '(') {
                level++;
            }
        }
        return res;
    }
};


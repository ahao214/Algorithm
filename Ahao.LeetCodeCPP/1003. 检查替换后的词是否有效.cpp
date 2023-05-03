#include<vector>
#include<string>

using namespace std;


/*
1003. ����滻��Ĵ��Ƿ���Ч

����һ���ַ��� s �������ж����Ƿ� ��Ч ��
�ַ��� s ��Ч ��Ҫ���㣺���迪ʼ��һ�����ַ��� t = "" �������ִ�� ����� ���������� t ת��Ϊ s ��

���ַ��� "abc" ���뵽 t �е�����λ�á���ʽ�ϣ�t ��Ϊ tleft + "abc" + tright������ t == tleft + tright ��ע�⣬tleft �� tright ����Ϊ �� ��
����ַ��� s ��Ч���򷵻� true�����򣬷��� false��
*/

class Solution {
public:
    bool isValid(string s) {
        string stk;
        for (auto c : s) {
            stk.push_back(c);
            if (stk.size() >= 3 && stk.substr(stk.size() - 3, 3) == "abc") {
                stk.erase(stk.end() - 3, stk.end());
            }
        }
        return stk.empty();
    }
};

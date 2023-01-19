#include<vector>
#include <string>
#include<unordered_set>

using namespace std;

/*
2299. ǿ��������� II

���һ���������������������������ǳ�����һ�� ǿ ���룺

�������� 8 ���ַ���
���ٰ��� һ��СдӢ�� ��ĸ��
���ٰ��� һ����дӢ�� ��ĸ��
���ٰ��� һ������ ��
���ٰ��� һ�������ַ� �������ַ�Ϊ��"!@#$%^&*()-+" �е�һ����
�� �� ���� 2 ��������ͬ���ַ����ȷ�˵ "aab" �����ϸ����������� "aba" ���ϸ���������
����һ���ַ��� password ���������һ�� ǿ ���룬���� true�����򷵻� false ��
*/


class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) {
            return false;
        }

        unordered_set<char> specials = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+' };
        int n = password.size();
        bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
        for (int i = 0; i < n; ++i) {
            if (i != n - 1 && password[i] == password[i + 1]) {
                return false;
            }

            char ch = password[i];
            if (islower(ch)) {
                hasLower = true;
            }
            else if (isupper(ch)) {
                hasUpper = true;
            }
            else if (isdigit(ch)) {
                hasDigit = true;
            }
            else if (specials.count(ch)) {
                hasSpecial = true;
            }
        }

        return hasLower && hasUpper && hasDigit && hasSpecial;
    }
};

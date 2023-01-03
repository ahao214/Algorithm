#include<vector>
#include<string>

using namespace std;

/*
2042. �������е������Ƿ����

������������ token ��ɵ�һ���б�token ���� ���� �ո�ָ�������û��ǰ����β��ո�ÿ�� token Ҫô��һ�������� 0-9 ��ɵĲ���ǰ����� ������ ��Ҫô��һ����СдӢ����ĸ��ɵ� ���� ��

ʾ����"a puppy has 2 eyes 4 legs" ��һ���� 7 �� token ��ɵľ��ӣ�"2" �� "4" �����֣������� "puppy" ������ tokens ���ڵ��ʡ�
����һ����ʾ���ӵ��ַ��� s ������Ҫ��� s �е� ȫ�� �����Ƿ�������ϸ�����������������һ�����֣�s �е� ÿ�� ���ֶ��ϸ�С���� �Ҳ� �����֣���

���������ĿҪ�󣬷��� true �����򣬷��� false ��

*/

class Solution {
public:
    bool areNumbersAscending(string s) {
        int pre = 0, pos = 0;
        while (pos < s.size()) {
            if (isdigit(s[pos])) {
                int cur = 0;
                while (pos < s.size() && isdigit(s[pos])) {
                    cur = cur * 10 + s[pos] - '0';
                    pos++;
                }
                if (cur <= pre) {
                    return false;
                }
                pre = cur;
            }
            else {
                pos++;
            }
        }
        return true;
    }
};


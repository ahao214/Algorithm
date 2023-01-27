#include<vector>
#include <string>
#include <unordered_set>

using namespace std;

/*
2309. ��ߴ�Сд�����Ӣ����ĸ

����һ����Ӣ����ĸ��ɵ��ַ��� s �������ҳ������� s �е� ��� Ӣ����ĸ�����ص���ĸ����Ϊ��д��ʽ�����������������������ĸ���򷵻�һ�����ַ�����

��� Ӣ����ĸ�Ĵ�д��Сд��ʽ���� �� �� s �г��֡�

Ӣ����ĸ b ����һ��Ӣ����ĸ a ���� ��ǰ���ǣ�Ӣ����ĸ���У�b �� a ֮ �� ���֡�
*/


//��ϣ��
class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> ht(s.begin(), s.end());
        for (int i = 25; i >= 0; i--) {
            if (ht.count('a' + i) > 0 && ht.count('A' + i) > 0) {
                return string(1, 'A' + i);
            }
        }
        return "";
    }
};

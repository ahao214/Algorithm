#include<vector>
#include <string>
#include <unordered_map>

using namespace std;


/*
2182. ���������ظ����ַ���
����һ���ַ��� s ��һ������ repeatLimit ���� s �е��ַ�����һ�����ַ��� repeatLimitedString ��ʹ�κ���ĸ ���� ���ֵĴ����������� repeatLimit �Ρ��㲻��ʹ�� s �е�ȫ���ַ���

���� �ֵ������� repeatLimitedString ��

������ַ��� a �� b ��ͬ�ĵ�һ��λ�ã��ַ��� a �е���ĸ����ĸ���г���ʱ����ַ��� b ��Ӧ����ĸ������Ϊ�ַ��� a ���ַ��� b �ֵ������ ������ַ�����ǰ min(a.length, b.length) ���ַ�����ͬ����ô�ϳ����ַ����ֵ������
*/
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int>m;
        for (auto item : s)
        {
            m[item]++;
        }
        string ans = "";
        char last = '1';
        int len = 0;
        bool flag = true;
        while (flag)
        {
            for (int now = 'z'; now >= 'a'; now--)
            {
                if (m[now] && (now != last || (len < repeatLimit)))
                {
                    ans += now;
                    m[now]--;
                    if (now == last)
                        len++;
                    else
                    {
                        len = 1;
                        last = now;
                    }
                    break;
                }
                if (now == 'a')
                    flag = false;
            }
        }
        return ans;
    }
};
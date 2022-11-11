#include<vector>
#include<string>

using namespace std;

/*
1684. ͳ��һ���ַ�������Ŀ

��

����һ���ɲ�ͬ�ַ���ɵ��ַ��� allowed ��һ���ַ������� words �����һ���ַ�����ÿһ���ַ����� allowed �У��ͳ�����ַ����� һ���ַ��� ��

���㷵�� words ������ һ���ַ��� ����Ŀ��
*/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;
        for (auto c : allowed) {
            mask |= 1 << (c - 'a');
        }
        int res = 0;
        for (auto&& word : words) {
            int mask1 = 0;
            for (auto c : word) {
                mask1 |= 1 << (c - 'a');
            }
            if ((mask1 | mask) == mask) {
                res++;
            }
        }
        return res;
    }
};


class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = 0;
        for (auto& word : words)
        {
            bool flag = true;
            for (auto c : word)
            {
                if (allowed.find(c) == -1)
                {
                    flag = false;
                    break;
                }
            }
            if (flag) res++;
        }
        return res;
    }
};
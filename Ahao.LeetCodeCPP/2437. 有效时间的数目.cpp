#include<vector>
#include <string>
#include <functional>

using namespace std;

/*
2437. ��Чʱ�����Ŀ

����һ������Ϊ 5 ���ַ��� time ����ʾһ������ʱ�ӵ�ǰ��ʱ�䣬��ʽΪ "hh:mm" ������ ���ܵ�ʱ���� "00:00" ������ ���ܵ�ʱ���� "23:59" ��

���ַ��� time �У����ַ� ? �滻������λ�� δ֪�� �����滻�����ֿ����� 0 �� 9 �е��κ�һ����

���㷵��һ������ answer ����ÿһ�� ? ���� 0 �� 9 ��һ�������滻�󣬿��Եõ�����Чʱ�����Ŀ��
*/


class Solution {
public:
    bool check(const string& time) {
        int hh = stoi(time);
        int mm = stoi(time.substr(3));
        if (hh < 24 && mm < 60) {
            return true;
        }
        else {
            return false;
        }
    }

    int countTime(string time) {
        int res = 0;
        function<void(int)> dfs = [&](int pos) {
            if (pos == time.size()) {
                if (check(time)) {
                    res++;
                }
                return;
            }
            if (time[pos] == '?') {
                for (int i = 0; i <= 9; i++) {
                    time[pos] = '0' + i;
                    dfs(pos + 1);
                    time[pos] = '?';
                }
            }
            else {
                dfs(pos + 1);
            }
        };
        dfs(0);
        return res;
    }
};


class Solution {
public:
    int countTime(string time) {
        int countHour = 0;
        int countMinute = 0;
        for (int i = 0; i < 24; i++) {
            int hiHour = i / 10;
            int loHour = i % 10;
            if ((time[0] == '?' || time[0] == hiHour + '0') &&
                (time[1] == '?' || time[1] == loHour + '0')) {
                countHour++;
            }
        }
        for (int i = 0; i < 60; i++) {
            int hiMinute = i / 10;
            int loMinute = i % 10;
            if ((time[3] == '?' || time[3] == hiMinute + '0') &&
                (time[4] == '?' || time[4] == loMinute + '0')) {
                countMinute++;
            }
        }
        return countHour * countMinute;
    }
};

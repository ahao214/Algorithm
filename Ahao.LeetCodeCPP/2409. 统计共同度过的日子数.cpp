#include<vector>
#include <string>

using namespace std;


/*
2409. ͳ�ƹ�ͬ�ȹ���������

Alice �� Bob �ƻ��ֱ�ȥ�����ᡣ

�����ĸ��ַ��� arriveAlice ��leaveAlice ��arriveBob �� leaveBob ��Alice �������� arriveAlice �� leaveAlice ֮���ڳ��������Ϊ�����䣩���� Bob ������ arriveBob �� leaveBob ֮���ڳ��������Ϊ�����䣩��ÿ���ַ��������� 5 ���ַ�����ʽΪ "MM-DD" ����Ӧ��һ�����ڵ��º��ա�

���㷵�� Alice�� Bob ͬʱ�������������

����Լ����������ڶ��� ͬһ�� ��Ȼ�꣬���� ���� ���ꡣÿ���·ݵ������ֱ�Ϊ��[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31] ��
*/

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> datesOfMonths = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        vector<int> prefixSum(1, 0);
        for (int date : datesOfMonths) {
            prefixSum.emplace_back(prefixSum.back() + date);
        }

        int arriveAliceDay = calculateDayOfYear(arriveAlice, prefixSum);
        int leaveAliceDay = calculateDayOfYear(leaveAlice, prefixSum);
        int arriveBobDay = calculateDayOfYear(arriveBob, prefixSum);
        int leaveBobDay = calculateDayOfYear(leaveBob, prefixSum);
        return max(0, min(leaveAliceDay, leaveBobDay) - max(arriveAliceDay, arriveBobDay) + 1);
    }

    int calculateDayOfYear(string day, const vector<int>& prefixSum) {
        int month = stoi(day.substr(0, 2));
        int date = stoi(day.substr(3));
        return prefixSum[month - 1] + date;
    }
};

#include<vector>
#include <string>
#include<unordered_map>
#include <algorithm>

using namespace std;


/*
1604. ����һСʱ��ʹ����ͬԱ�������ڵ������ε���

���۹�˾��Ա����ʹ��Ա���������칫�ҵ��š�ÿ��һ��Ա��ʹ��һ������Ա����������ϵͳ���¼��Ա�������ֺ�ʹ��ʱ�䡣���һ��Ա����һСʱʱ����ʹ��Ա�����Ĵ������ڵ������Σ����ϵͳ���Զ�����һ�� ���� ��

�����ַ������� keyName �� keyTime ������ [keyName[i], keyTime[i]] ��Ӧһ���˵����ֺ����� ĳһ�� ��ʹ��Ա������ʱ�䡣

ʹ��ʱ��ĸ�ʽ�� 24Сʱ�� ������ "HH:MM" ���ȷ�˵ "23:51" �� "09:49" ��

���㷵��ȥ�غ���յ�ϵͳ�����Ա�����֣������ǰ� �ֵ������� ����󷵻ء�

��ע�� "10:00" - "11:00" ��Ϊһ��Сʱʱ�䷶Χ�ڣ��� "23:51" - "00:10" ������ΪһСʱ�ڣ���Ϊϵͳ��¼����ĳһ���ڵ�ʹ�������
*/

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> timeMap;
        int n = keyName.size();
        for (int i = 0; i < n; i++) {
            string name = keyName[i];
            string time = keyTime[i];
            int hour = (time[0] - '0') * 10 + (time[1] - '0');
            int minute = (time[3] - '0') * 10 + (time[4] - '0');
            timeMap[name].emplace_back(hour * 60 + minute);
        }
        vector<string> res;
        for (auto& [name, list] : timeMap) {
            sort(list.begin(), list.end());
            int size = list.size();
            for (int i = 2; i < size; i++) {
                int time1 = list[i - 2], time2 = list[i];
                int difference = time2 - time1;
                if (difference <= 60) {
                    res.emplace_back(name);
                    break;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

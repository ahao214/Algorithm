#include<vector>
#include <algorithm>

using namespace std;


/*
274. H ָ��

����һ���������� citations ������ citations[i] ��ʾ�о��ߵĵ� i ƪ���ı����õĴ��������㲢���ظ��о��ߵ� h ָ����

����ά���ٿ��� h ָ���Ķ��壺h ���������ô����� ��һ��������Ա�� h ָ�� ��ָ�����������ٷ����� h ƪ���ģ�����ÿƪ���� ���� ������ h �Ρ���� h �ж��ֿ��ܵ�ֵ��h ָ�� �����������Ǹ���
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h = 0, i = citations.size() - 1;
        while (i >= 0 && citations[i] > h) {
            h++;
            i--;
        }
        return h;
    }
};


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), tot = 0;
        vector<int> counter(n + 1);
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n) {
                counter[n]++;
            }
            else {
                counter[citations[i]]++;
            }
        }
        for (int i = n; i >= 0; i--) {
            tot += counter[i];
            if (tot >= i) {
                return i;
            }
        }
        return 0;
    }
};


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, right = citations.size();
        int mid = 0, cnt = 0;
        while (left < right) {
            // +1 ��ֹ��ѭ��
            mid = (left + right + 1) >> 1;
            cnt = 0;
            for (int i = 0; i < citations.size(); i++) {
                if (citations[i] >= mid) {
                    cnt++;
                }
            }
            if (cnt >= mid) {
                // Ҫ�ҵĴ��� [mid,right] ������
                left = mid;
            }
            else {
                // Ҫ�ҵĴ��� [0,mid) ������
                right = mid - 1;
            }
        }
        return left;
    }
};

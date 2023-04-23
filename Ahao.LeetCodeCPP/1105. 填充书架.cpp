#include<vector>

using namespace std;


/*
1105. ������

����һ������ books ������ books[i] = [thicknessi, heighti] ��ʾ�� i ����ĺ�Ⱥ͸߶ȡ���Ҳ��õ�һ������ shelfWidth ��

��˳�� ����Щ��ڷŵ��ܿ��Ϊ shelfWidth ������ϡ�

��ѡ�������������ϣ����ǵĺ��֮��С�ڵ�����ܵĿ�� shelfWidth ����Ȼ���ٽ�һ����ܡ��ظ�������̣�ֱ�������е��鶼��������ϡ�

��Ҫע����ǣ����������̵�ÿ�������У��ڷ����˳����������õ�˳����ͬ��

���磬��������� 5 ���飬��ô���ܵ�һ�ְڷ�����ǣ���һ�͵ڶ�������ڵ�һ������ϣ�����������ڵڶ�������ϣ����ĺ͵��屾��������һ������ϡ�
ÿһ�����ڷŵ�������߶Ⱦ�����һ����ܵĲ�ߣ��������ĸ߶�Ϊ�����֮�͡�

�����ַ�ʽ������ܣ��������������ܵ���С�߶ȡ�
*/


class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, 1000000);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            int maxHeight = 0, curWidth = 0;
            for (int j = i; j >= 0; --j) {
                curWidth += books[j][0];
                if (curWidth > shelfWidth) {
                    break;
                }
                maxHeight = max(maxHeight, books[j][1]);
                dp[i + 1] = min(dp[i + 1], dp[j] + maxHeight);
            }
        }
        return dp[n];
    }
};

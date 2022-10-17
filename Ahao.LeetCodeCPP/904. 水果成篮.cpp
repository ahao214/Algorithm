#include<vector>
#include<unordered_map>


using namespace std;

/*
904. ˮ������

������̽��һ��ũ����ũ����������ֲ��һ�Ź�������Щ����һ���������� fruits ��ʾ������ fruits[i] �ǵ� i �����ϵ�ˮ�� ���� ��

����Ҫ�����ܶ���ռ�ˮ����Ȼ����ũ���������趨��һЩ�ϸ�Ĺ�أ�����밴��Ҫ���ժˮ����

��ֻ�� ���� ���ӣ�����ÿ������ֻ��װ ��һ���� ��ˮ����ÿ�������ܹ�װ��ˮ������û�����ơ�
�����ѡ������һ������ʼ��ժ�������� ÿ�� ����������ʼ��ժ�������� ǡ��ժһ��ˮ�� ����ժ��ˮ��Ӧ�����������е�ˮ�����͡�ÿ��ժһ�Σ��㽫�������ƶ�����һ��������������ժ��
һ�����ߵ�ĳ����ǰ����ˮ�����������ӵ�ˮ�����ͣ���ô�ͱ���ֹͣ��ժ��
����һ���������� fruits ������������ռ���ˮ���� ��� ��Ŀ��
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> cnt;

        int left = 0, ans = 0;
        for (int right = 0; right < n; ++right) {
            ++cnt[fruits[right]];
            while (cnt.size() > 2) {
                auto it = cnt.find(fruits[left]);
                --it->second;
                if (it->second == 0) {
                    cnt.erase(it);
                }
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

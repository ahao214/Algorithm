#include<vector>
#include<string>

using namespace std;

/*
1177. �������Ĵ����

����һ���ַ��� s������� s ���Ӵ����м�⡣

ÿ�μ�⣬�����Ӵ������Ա�ʾΪ queries[i] = [left, right, k]�����ǿ��� �������� �Ӵ� s[left], ..., s[right]��������ѡ�� ��� k ���滻���κ�СдӢ����ĸ��

����������������У��Ӵ����Ա�ɻ�����ʽ���ַ�������ô�����Ϊ true��������Ϊ false��

���ش����� answer[]������ answer[i] �ǵ� i �������Ӵ� queries[i] �ļ������

ע�⣺���滻ʱ���Ӵ��е�ÿ����ĸ��������Ϊ ������ ����м�����Ҳ����˵����� s[left..right] = "aaa" �� k = 2������ֻ���滻���е�������ĸ�������⣬�κμ�ⶼ�����޸�ԭʼ�ַ��� s��������Ϊÿ�μ�ⶼ�Ƕ����ģ�
*/

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> count(n + 1);
        for (int i = 0; i < n; i++) {
            count[i + 1] = count[i] ^ (1 << (s[i] - 'a'));
        }
        vector<bool> res;
        for (auto& query : queries) {
            int l = query[0], r = query[1], k = query[2];
            int bits = 0, x = count[r + 1] ^ count[l];
            while (x > 0) {
                x &= x - 1;
                bits++;
            }
            res.push_back(bits <= k * 2 + 1);
        }
        return res;
    }
};

#include<vector>
#include <unordered_map>

using namespace std;

/*
2283. �ж�һ���������ּ����Ƿ������λ��ֵ

����һ���±�� 0 ��ʼ����Ϊ n ���ַ��� num ����ֻ�������֡�

������� ÿ�� 0 <= i < n ���±� i ����������λ i �� num �г����� num[i]�Σ���ô���㷵�� true �����򷵻� false ��
*/

class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int, int> h;
        int n = num.size();
        for (int i = 0; i < n; i++) {
            int digit = num[i] - '0';
            h[num[i] - '0']++;
        }
        for (int i = 0; i < n; i++) {
            int v = num[i] - '0';
            if (h[i] != v) {
                return false;
            }
        }
        return true;
    }
};


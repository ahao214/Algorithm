#include<vector>
#include<string>

using namespace std;

/*
2451. ��ֵ���鲻ͬ���ַ���

����һ���ַ������� words ��ÿһ���ַ������ȶ���ͬ���������ַ����ĳ��ȶ�Ϊ n ��

ÿ���ַ��� words[i] ���Ա�ת��Ϊһ������Ϊ n - 1 �� ��ֵ�������� difference[i] �����ж��� 0 <= j <= n - 2 �� difference[i][j] = words[i][j+1] - words[i][j] ��ע��������ĸ�Ĳ�ֵ����Ϊ��������ĸ���� λ�� ֮�Ҳ����˵ 'a' ��λ���� 0 ��'b' ��λ���� 1 ��'z' ��λ���� 25 ��

�ȷ�˵���ַ��� "acb" �Ĳ�ֵ���������� [2 - 0, 1 - 2] = [2, -1] ��
words �������ַ��� ����һ���ַ������� �������ַ����Ĳ�ֵ�������鶼��ͬ������Ҫ�ҵ��Ǹ���ͬ���ַ�����

���㷵�� words�� ��ֵ�������� ��ͬ���ַ�����
*/

class Solution {
public:
    vector<int> get(string& word) {
        vector<int> diff(word.size() - 1);
        for (int i = 0; i + 1 < word.size(); i++) {
            diff[i] = word[i + 1] - word[i];
        }
        return diff;
    }

    string oddString(vector<string>& words) {
        auto diff0 = get(words[0]);
        auto diff1 = get(words[1]);
        if (diff0 == diff1) {
            for (int i = 2; i < words.size(); i++) {
                if (diff0 != get(words[i])) {
                    return words[i];
                }
            }
        }
        return diff0 == get(words[2]) ? words[1] : words[0];
    }
};

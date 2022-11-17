#include<vector>
#include <string>
#include<queue>

using namespace std;

/*
792. ƥ�������еĵ�����

�е�

�����ַ��� s ���ַ������� words, ����  words[i] ����s�������еĵ��ʸ��� ��

�ַ����� ������ �Ǵ�ԭʼ�ַ��������ɵ����ַ��������Դ���ɾȥһЩ�ַ�(������none)�������ı������ַ������˳��

���磬 ��ace�� �� ��abcde�� �������С�
*/




//��ָ��
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<queue<pair<int, int>>> queues(26);
        for (int i = 0; i < words.size(); ++i) {
            queues[words[i][0] - 'a'].emplace(i, 0);
        }
        int res = 0;
        for (char c : s) {
            auto& q = queues[c - 'a'];
            int size = q.size();
            while (size--) {
                auto [i, j] = q.front();
                q.pop();
                ++j;
                if (j == words[i].size()) {
                    ++res;
                }
                else {
                    queues[words[i][j] - 'a'].emplace(i, j);
                }
            }
        }
        return res;
    }
};

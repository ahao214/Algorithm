#include<vector>
#include <string>

using namespace std;

/*
1255. �÷���ߵĵ��ʼ���

�㽫��õ�һ�ݵ��ʱ� words��һ����ĸ�� letters �����ܻ����ظ���ĸ�����Լ�ÿ����ĸ��Ӧ�ĵ÷������ score��

�����æ��������ڵ���ƴд��Ϸ�����ܻ�õġ���ߵ÷֡����ܹ��� letters �����ĸƴд���� ���� ���� words �����Ӽ��У�������ߵĵ��ʼ��ϵĵ÷֡�

����ƴд��Ϸ�Ĺ���������£�

�����Ҫ����ĸ�� letters �����ĸ��ƴд���ʱ� words �еĵ��ʡ�
����ֻʹ����ĸ�� letters �еĲ�����ĸ������ÿ����ĸ��౻ʹ��һ�Ρ�
���ʱ� words ��ÿ������ֻ�ܼƷ֣�ʹ�ã�һ�Ρ�
������ĸ�÷������score����ĸ 'a', 'b', 'c', ... , 'z' ��Ӧ�ĵ÷ֱַ�Ϊ score[0], score[1], ..., score[25]��
������Ϸ�ġ��÷֡���ָ�������ƴд���ĵ��ʼ����������������ĸ�ĵ÷�֮�͡�
*/

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size(), res = 0;
        vector<int> count(26);
        for (auto c : letters) {
            count[c - 'a']++;
        }
        for (int s = 1; s < (1 << n); s++) {
            vector<int> wordCount(26); // ͳ���Ӽ� s ���е��ʵ���ĸ��Ŀ
            for (int k = 0; k < n; k++) {
                if ((s & (1 << k)) == 0) { // words[k] �����Ӽ� s ��
                    continue;
                }
                for (auto c : words[k]) {
                    wordCount[c - 'a']++;
                }
            }
            bool ok = true; // �ж��Ӽ� s �Ƿ�Ϸ�
            int sum = 0; // �����Ӽ� s �ĵ÷�
            for (int i = 0; i < 26; i++) {
                sum += score[i] * wordCount[i];
                ok = ok && (wordCount[i] <= count[i]);
            }
            if (ok) {
                res = max(res, sum);
            }
        }
        return res;
    }
};

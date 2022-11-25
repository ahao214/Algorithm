#include<vector>
#include <string>


using namespace std;

/*
809. ��зḻ������

��ʱ�����ǻ����ظ�дһЩ��ĸ����ʾ����ĸ��ܣ����� "hello" -> "heeellooo", "hi" -> "hiii"�����ǽ�������ĸ����ͬ��һ���ַ�����Ϊ��ͬ��ĸ�飬���磺"h", "eee", "ll", "ooo"��

����һ���������ַ��� S �������һ�������ܹ�ͨ����һЩ��ĸ�����ŴӶ�ʹ��� S ��ͬ�����ǽ�������ʶ���Ϊ�����ŵģ�stretchy�������Ų����������£�ѡ��һ����ĸ�飨������ĸ c ����Ȼ�������������ͬ����ĸ c ʹ�䳤�ȴﵽ 3 �����ϡ�

���磬�� "hello" Ϊ�������ǿ��Զ���ĸ�� "o" ���ŵõ� "hellooo"�������޷���ͬ���ķ����õ� "helloo" ��Ϊ��ĸ�� "oo" ����С�� 3�����⣬���ǿ��Խ�����һ������ "ll" -> "lllll" �Ի�� "helllllooo"����� S = "helllllooo"����ô��ѯ�� "hello" �ǿ����ŵģ���Ϊ���Զ���ִ�����������Ų���ʹ�� query = "hello" -> "hellooo" -> "helllllooo" = S��

����һ���ѯ���ʣ�������п����ŵĵ���������
*/

class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        for (const string& word : words) {
            if (expand(s, word)) {
                ++ans;
            }
        }
        return ans;
    }

private:
    bool expand(const string& s, const string& t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] != t[j]) {
                return false;
            }
            char ch = s[i];
            int cnti = 0;
            while (i < s.size() && s[i] == ch) {
                ++cnti;
                ++i;
            }
            int cntj = 0;
            while (j < t.size() && t[j] == ch) {
                ++cntj;
                ++j;
            }
            if (cnti < cntj) {
                return false;
            }
            if (cnti != cntj && cnti < 3) {
                return false;
            }
        }
        return i == s.size() && j == t.size();
    }
};

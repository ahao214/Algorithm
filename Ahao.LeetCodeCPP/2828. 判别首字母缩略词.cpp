#include<vector>
#include<string>

using namespace std;

/*
2828. �б�����ĸ���Դ�

����һ���ַ������� words ��һ���ַ��� s �������ж� s �ǲ��� words �� ����ĸ���Դ� ��

������԰�˳���� words ��ÿ���ַ����ĵ�һ���ַ��γ��ַ��� s ������Ϊ s �� words ������ĸ���Դʡ����磬"ab" ������ ["apple", "banana"] �γɣ������޷��� ["bear", "aardvark"] �γɡ�

��� s �� words ������ĸ���Դʣ����� true �����򣬷��� false ��
*/



class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if (s.size() != words.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            if (words[i][0] != s[i]) {
                return false;
            }
        }
        return true;
    }
};

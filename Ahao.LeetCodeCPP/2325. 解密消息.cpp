#include<vector>
#include <string>
#include <unordered_map>

using namespace std;


/*
2325. ������Ϣ

�����ַ��� key �� message ���ֱ��ʾһ��������Կ��һ�μ�����Ϣ������ message �Ĳ������£�

ʹ�� key �� 26 ��Ӣ��Сд��ĸ��һ�γ��ֵ�˳����Ϊ�滻���е���ĸ ˳�� ��
���滻������ͨӢ����ĸ����룬�γɶ��ձ�
���ն��ձ� �滻 message �е�ÿ����ĸ��
�ո� ' ' ���ֲ��䡣
���磬key = "happy boy"��ʵ�ʵļ�����Կ�������ĸ����ÿ����ĸ ����һ�Σ����ݴˣ����Եõ����ֶ��ձ�'h' -> 'a'��'a' -> 'b'��'p' -> 'c'��'y' -> 'd'��'b' -> 'e'��'o' -> 'f'����
���ؽ��ܺ����Ϣ��
*/


class Solution {
public:
    string decodeMessage(string key, string message) {
        char cur = 'a';
        unordered_map<char, char> rules;

        for (char c : key) {
            if (c != ' ' && !rules.count(c)) {
                rules[c] = cur;
                ++cur;
            }
        }

        for (char& c : message) {
            if (c != ' ') {
                c = rules[c];
            }
        }

        return message;
    }
};

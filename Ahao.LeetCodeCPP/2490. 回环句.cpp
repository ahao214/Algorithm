#include<vector>
#include<string>

using namespace std;


/*
2490. �ػ���

���� ���ɵ����ո�ָ���һ�鵥�ʣ��Ҳ���ǰ����β��ո�

���磬"Hello World"��"HELLO"��"hello world hello world" ���Ƿ���Ҫ��ľ��ӡ�
���� �� �ɴ�д��СдӢ����ĸ��ɡ��Ҵ�д��Сд��ĸ��������ͬ�ַ���

���������������ȫ������������Ϊ����һ�� �ػ��� ��

���ʵ����һ���ַ�����һ�����ʵĵ�һ���ַ���ȡ�
���һ�����ʵ����һ���ַ��͵�һ�����ʵĵ�һ���ַ���ȡ�
���磬"leetcode exercises sound delightful"��"eetcode"��"leetcode eats soul" ���ǻػ��䡣Ȼ����"Leetcode is cool"��"happy Leetcode"��"Leetcode" �� "I like Leetcode" �� �� �ǻػ��䡣

����һ���ַ��� sentence �������ж����ǲ���һ���ػ��䡣����ǣ����� true �����򣬷��� false ��
*/


class Solution {
public:
    bool isCircularSentence(string sentence) {
        if (sentence.back() != sentence.front()) {
            return false;
        }
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ' && sentence[i + 1] != sentence[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

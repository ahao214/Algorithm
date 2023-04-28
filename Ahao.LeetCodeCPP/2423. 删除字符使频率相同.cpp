#include<vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
2423. ɾ���ַ�ʹƵ����ͬ

����һ���±�� 0 ��ʼ���ַ��� word ���ַ���ֻ����СдӢ����ĸ������Ҫѡ�� һ�� �±겢 ɾ�� �±괦���ַ���ʹ�� word ��ʣ��ÿ����ĸ���� Ƶ�� ��ͬ��

���ɾ��һ����ĸ��word ��ʣ��������ĸ�ĳ���Ƶ�ʶ���ͬ����ô���� true �����򷵻� false ��

ע�⣺

��ĸ x �� Ƶ�� �������ĸ���ַ����г��ֵĴ�����
�� ���� ǡ��ɾ��һ����ĸ������һ����ĸ����ɾ����
*/


class Solution {
public:
    bool equalFrequency(string word) {
        int charCount[26] = { 0 };
        for (char& c : word) {
            charCount[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (charCount[i] == 0) {
                continue;
            }
            charCount[i]--;
            unordered_set<int> frequency;
            for (int f : charCount) {
                if (f > 0) {
                    frequency.insert(f);
                }
            }
            if (frequency.size() == 1) {
                return true;
            }
            charCount[i]++;
        }
        return false;
    }
};



class Solution {
public:
    bool equalFrequency(string word) {
        int charCount[26] = { 0 };
        for (char c : word) {
            charCount[c - 'a']++;
        }
        unordered_map<int, int> freqCount;
        for (int c : charCount) {
            if (c > 0) {
                freqCount[c]++;
            }
        }
        for (int c : charCount) {
            if (c == 0) {
                continue;
            }
            freqCount[c]--;
            if (freqCount[c] == 0) {
                freqCount.erase(c);
            }
            if (c - 1 > 0) {
                freqCount[c - 1]++;
            }
            if (freqCount.size() == 1) {
                return true;
            }
            if (c - 1 > 0) {
                freqCount[c - 1]--;
                if (freqCount[c - 1] == 0) {
                    freqCount.erase(c - 1);
                }
            }
            freqCount[c]++;
        }
        return false;
    }
};

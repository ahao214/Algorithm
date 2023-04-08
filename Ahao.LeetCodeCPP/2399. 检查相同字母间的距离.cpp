#include<vector>
#include <string>

using namespace std;

/*
2399. �����ͬ��ĸ��ľ���

����һ���±�� 0 ��ʼ���ַ��� s �����ַ�������СдӢ����ĸ��ɣ�s �е�ÿ����ĸ�� ǡ�� ���� ���� �������һ���±�� 0 ��ʼ������Ϊ 26 �ĵ��������� distance ��

��ĸ���е�ÿ����ĸ���� 0 �� 25 ���α�ţ�����'a' -> 0, 'b' -> 1, 'c' -> 2, ... , 'z' -> 25����

��һ�� ���� �ַ����У��� i ����ĸ�����γ���֮�����ĸ������ distance[i] ������� i ����ĸû���� s �г��֣���ô distance[i] ���� ���� ��

��� s ��һ�� ���� �ַ��������� true �����򣬷��� false ��
*/

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j] && distance[s[i] - 'a'] != j - i - 1) {
                    return false;
                }
            }
        }
        return true;
    }
};



class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> firstIndex(26);
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if (firstIndex[idx] && i - firstIndex[idx] != distance[idx]) {
                return false;
            }
            firstIndex[idx] = i + 1;
        }
        return true;
    }
};

#include<vector>
#include <map>

using namespace std;

/*
2363. �ϲ����Ƶ���Ʒ

����������ά�������� items1 �� items2 ����ʾ������Ʒ���ϡ�ÿ������ items ���������ʣ�

items[i] = [valuei, weighti] ���� valuei ��ʾ�� i ����Ʒ�� ��ֵ ��weighti ��ʾ�� i ����Ʒ�� ���� ��
items ��ÿ����Ʒ�ļ�ֵ���� Ψһ�� ��
���㷵��һ����ά���� ret������ ret[i] = [valuei, weighti]�� weighti �����м�ֵΪ valuei ��Ʒ�� ����֮�� ��

ע�⣺ret Ӧ�ð���ֵ ���� ����󷵻ء�
*/

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp;
        for (auto& v : items1) {
            mp[v[0]] += v[1];
        }
        for (auto& v : items2) {
            mp[v[0]] += v[1];
        }

        vector<vector<int>> res;
        for (auto& [k, v] : mp) {
            res.push_back({ k, v });
        }
        return res;
    }
};

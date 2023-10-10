#include<vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
2512. 奖励最顶尖的 K 名学生

给你两个字符串数组 positive_feedback 和 negative_feedback ，分别包含表示正面的和负面的词汇。不会 有单词同时是正面的和负面的。

一开始，每位学生分数为 0 。每个正面的单词会给学生的分数 加 3 分，每个负面的词会给学生的分数 减  1 分。

给你 n 个学生的评语，用一个下标从 0 开始的字符串数组 report 和一个下标从 0 开始的整数数组 student_id 表示，其中 student_id[i] 表示这名学生的 ID ，这名学生的评语是 report[i] 。每名学生的 ID 互不相同。

给你一个整数 k ，请你返回按照得分 从高到低 最顶尖的 k 名学生。如果有多名学生分数相同，ID 越小排名越前。
*/



class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<std::string, int> words;
        for (const auto& word : positive_feedback) {
            words[word] = 3;
        }
        for (const auto& word : negative_feedback) {
            words[word] = -1;
        }
        vector<vector<int>> A;
        for (int i = 0; i < report.size(); i++) {
            stringstream ss; //stream根据空格分词
            string w;
            int score = 0;
            ss << report[i];
            while (ss >> w) {
                if (words.count(w)) {
                    score += words[w];
                }
            }
            A.push_back({ -score, student_id[i] });
        }
        sort(A.begin(), A.end());
        vector<int> top_k;
        for (int i = 0; i < k; i++) {
            top_k.push_back(A[i][1]);
        }
        return top_k;
    }
};

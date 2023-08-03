#include<vector>
#include <string>

using namespace std;

/*
722. ɾ��ע��

��һ�� C++ ����ɾ�������е�ע�͡��������source��һ�����飬����source[i]��ʾ�� i ��Դ�롣 ���ʾÿ��Դ���� '\n' �ָ���

�� C++ ��������ע�ͷ������ע�ͺͿ�ע�͡�

�ַ���// ��ʾ��ע�ͣ���ʾ//�����Ҳ�������ַ�Ӧ�ñ����ԡ�


����ַ���//�����ڿ�ע���лᱻ���ԡ�
ͬ��������ַ���/*�������л��ע����Ҳ�ᱻ���ԡ�
���һ����ɾ��ע��֮���Ϊ���ַ�������ô��Ҫ������С��������б��е�ÿ���ַ������Ƿǿյġ�

������û�п����ַ��������Ż�˫�����ַ���


���Ǳ�֤ÿһ����ע�����ն��ᱻ�պϣ� �������л��ע��֮���/*���ǿ�ʼ�µ�ע�͡�

�����ʽ���з�����ͨ����ע��ɾ���� �й���ϸ��Ϣ������������ʾ����

��Դ������ɾ��ע�ͺ���Ҫ����ͬ�ĸ�ʽ����Դ���롣
*/

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        string new_line = "";
        bool in_block = false;
        for (auto& line : source) {
            for (int i = 0; i < line.size(); i++) {
                if (in_block) {
                    if (i + 1 < line.size() && line[i] == '*' && line[i + 1] == '/') {
                        in_block = false;
                        i++;
                    }
                }
                else {
                    if (i + 1 < line.size() && line[i] == '/' && line[i + 1] == '*') {
                        in_block = true;
                        i++;
                    }
                    else if (i + 1 < line.size() && line[i] == '/' && line[i + 1] == '/') {
                        break;
                    }
                    else {
                        new_line += line[i];
                    }
                }
            }
            if (!in_block && new_line != "") {
                res.push_back(new_line);
                new_line = "";
            }
        }
        return res;
    }
};

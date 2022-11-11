#include<string>

using namespace std;

class Solution {
public:
    string interpret(string command) {
        string res;
        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'G') {
                res += "G";
            }
            else if (command[i] == '(') {
                if (command[i + 1] == ')') {
                    res += "o";
                }
                else {
                    res += "al";
                }
            }
        }
        return res;
    }
};




/*
1678. ��� Goal ������
�������һ�����Խ����ַ��� command �� Goal ������ ��command �� "G"��"()" ��/�� "(al)" ��ĳ��˳����ɡ�Goal �������Ὣ "G" ����Ϊ�ַ��� "G"��"()" ����Ϊ�ַ��� "o" ��"(al)" ����Ϊ�ַ��� "al" ��Ȼ�󣬰�ԭ˳�򽫾����͵õ����ַ������ӳ�һ���ַ�����

�����ַ��� command ������ Goal ������ �� command �Ľ��ͽ����
*/
class Solution {
public:
    string interpret(string command) {
        string res;
        for (int i = 0; i < command.size(); i++)
        {
            if (command[i] == 'G')
                res += 'G';
            else if (command.substr(i, 4) == "(al)") {
                res += "al";
                i += 3;
            }
            else {
                res += 'o';
                i++;
            }
        }
        return res;
    }
};
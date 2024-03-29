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
1678. 设计 Goal 解析器
请你设计一个可以解释字符串 command 的 Goal 解析器 。command 由 "G"、"()" 和/或 "(al)" 按某种顺序组成。Goal 解析器会将 "G" 解释为字符串 "G"、"()" 解释为字符串 "o" ，"(al)" 解释为字符串 "al" 。然后，按原顺序将经解释得到的字符串连接成一个字符串。

给你字符串 command ，返回 Goal 解析器 对 command 的解释结果。
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
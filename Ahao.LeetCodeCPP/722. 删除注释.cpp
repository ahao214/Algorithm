#include<vector>
#include <string>

using namespace std;

/*
722. 删除注释

给一个 C++ 程序，删除程序中的注释。这个程序source是一个数组，其中source[i]表示第 i 行源码。 这表示每行源码由 '\n' 分隔。

在 C++ 中有两种注释风格，行内注释和块注释。

字符串// 表示行注释，表示//和其右侧的其余字符应该被忽略。


如果字符串//出现在块注释中会被忽略。
同样，如果字符串/*出现在行或块注释中也会被忽略。
如果一行在删除注释之后变为空字符串，那么不要输出该行。即，答案列表中的每个字符串都是非空的。

样例中没有控制字符，单引号或双引号字符。


我们保证每一个块注释最终都会被闭合， 所以在行或块注释之外的/*总是开始新的注释。

最后，隐式换行符可以通过块注释删除。 有关详细信息，请参阅下面的示例。

从源代码中删除注释后，需要以相同的格式返回源代码。
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

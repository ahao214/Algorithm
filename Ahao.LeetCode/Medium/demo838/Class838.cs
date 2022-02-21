using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo838
{
    /*
     838. 推多米诺
n 张多米诺骨牌排成一行，将每张多米诺骨牌垂直竖立。在开始时，同时把一些多米诺骨牌向左或向右推。

每过一秒，倒向左边的多米诺骨牌会推动其左侧相邻的多米诺骨牌。同样地，倒向右边的多米诺骨牌也会推动竖立在其右侧的相邻多米诺骨牌。

如果一张垂直竖立的多米诺骨牌的两侧同时有多米诺骨牌倒下时，由于受力平衡， 该骨牌仍然保持不变。

就这个问题而言，我们会认为一张正在倒下的多米诺骨牌不会对其它正在倒下或已经倒下的多米诺骨牌施加额外的力。

给你一个字符串 dominoes 表示这一行多米诺骨牌的初始状态，其中：

dominoes[i] = 'L'，表示第 i 张多米诺骨牌被推向左侧，
dominoes[i] = 'R'，表示第 i 张多米诺骨牌被推向右侧，
dominoes[i] = '.'，表示没有推动第 i 张多米诺骨牌。
返回表示最终状态的字符串。
     */
    public class Class838
    {
        public string PushDominoes(string dominoes)
        {
            char[] c = dominoes.ToCharArray();
            int n = c.Length, i = 0;
            char left = 'L';
            while (i < n)
            {
                int j = i;
                while (j < n && c[j] == '.')
                {
                    j++;
                }
                char right;
                if (j < n)
                {
                    right = c[j];
                }
                else
                {
                    right = 'R';
                }
                if (left == right)
                {
                    while (i < j)
                    {
                        c[i++] = right;
                    }
                }
                else if (left == 'R' && right == 'L')
                {
                    int tmp = j - 1;
                    while (i < tmp)
                    {
                        c[i++] = 'R';
                        c[tmp--] = 'L';
                    }
                }

                left = right;
                i = j + 1;
            }
            return new string(c);
        }
    }
}

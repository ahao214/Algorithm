using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1189
{
    /*
     1189. “气球” 的最大数量
给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。

字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。
     */
    public class Class1189
    {
        public int MaxNumberOfBalloons(string text)
        {
            if (string.IsNullOrEmpty(text))
                return 0;
            int[] count = new int[5];
            foreach (char c in text)
            {
                if (c == 'b')
                {
                    count[0]++;
                }
                else if (c == 'a')
                {
                    count[1]++;
                }
                else if (c == 'l')
                {
                    count[2]++;
                }
                else if (c == 'o')
                {
                    count[3]++;
                }
                else if (c == 'n')
                {
                    count[4]++;
                }
            }
            count[2] /= 2;
            count[3] /= 2;
            return count.Min();
        }
    }
}

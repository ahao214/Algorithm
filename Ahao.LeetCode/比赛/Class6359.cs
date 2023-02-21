using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.比赛
{
    /*
     6359. 替换一个数字后的最大差值 
给你一个整数 num 。你知道 Danny Mittal 会偷偷将 0 到 9 中的一个数字 替换 成另一个数字。

请你返回将 num 中 恰好一个 数字进行替换后，得到的最大值和最小值的差位多少。

注意：

当 Danny 将一个数字 d1 替换成另一个数字 d2 时，Danny 需要将 nums 中所有 d1 都替换成 d2 。
Danny 可以将一个数字替换成它自己，也就是说 num 可以不变。
Danny 可以将数字分别替换成两个不同的数字分别得到最大值和最小值。
替换后得到的数字可以包含前导 0 。
Danny Mittal 获得周赛 326 前 10 名，让我们恭喜他。

输入：num = 11891
输出：99009
解释：
为了得到最大值，我们将数字 1 替换成数字 9 ，得到 99899 。
为了得到最小值，我们将数字 1 替换成数字 0 ，得到 890 。
两个数字的差值为 99009 。
     */
    public class Class6359
    {
        public int MinMaxDifference(int num)
        {
            int res = 0;
            if (num >= 1 && num <= 9)
                return 9;
            int max = num;
            string ans = num.ToString();
            for (int i = 0; i < ans.Length; i++)
            {
                if (ans[i] != '9')
                {
                    max = Convert.ToInt32(ans.Replace(ans[i], '9'));
                    break;
                }
            }

            int min = Convert.ToInt32(ans.Replace(Convert.ToChar(ans.Substring(0, 1)), '0'));
            res = max - min;

            return res;
        }


        public int MinMaxDifference2(int num)
        {
            int maxVal = num;
            int minVal = num;
            string ans = num.ToString();
            for (int i = 0; i < ans.Length; i++)
            {
                if (ans[i] != '9')
                {
                    maxVal = Convert.ToInt32(ans.Replace(ans[i], '9'));
                    break;
                }
            }
            for (int i = 0; i < ans.Length; i++)
            {
                if (ans[i] != '0')
                {
                    minVal = Convert.ToInt32(ans.Replace(ans[i], '0'));
                    break;
                }
            }
            return maxVal - minVal;
        }

    }
}

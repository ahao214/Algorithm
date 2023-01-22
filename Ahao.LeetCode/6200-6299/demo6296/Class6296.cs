using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._6200_6299.demo6296
{
    /*
     6296. 交替数字和 

给你一个正整数 n 。n 中的每一位数字都会按下述规则分配一个符号：

最高有效位 上的数字分配到 正 号。
剩余每位上数字的符号都与其相邻数字相反。
返回所有数字及其对应符号的和。
    示例 1：

输入：n = 521
输出：4
解释：(+5) + (-2) + (+1) = 4
     */
    public class Class6296
    {
        public int AlternateDigitSum(int n)
        {
            int result = 0;
            int len = n.ToString().Length;
            string num = n.ToString();
            for (int i = 0; i < len; i++)
            {
                if (i % 2 == 0)
                    result += Convert.ToInt32(num.Substring(i, 1));
                else
                    result -= Convert.ToInt32(num.Substring(i, 1));
            }
            return result;
        }
    }
}

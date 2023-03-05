using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.比赛
{
    /*
     6312. 最小和分割 

给你一个正整数 num ，请你将它分割成两个非负整数 num1 和 num2 ，满足：

num1 和 num2 直接连起来，得到 num 各数位的一个排列。
换句话说，num1 和 num2 中所有数字出现的次数之和等于 num 中所有数字出现的次数。
num1 和 num2 可以包含前导 0 。
请你返回 num1 和 num2 可以得到的和的 最小 值。

注意：

num 保证没有前导 0 。
num1 和 num2 中数位顺序可以与 num 中数位顺序不同。

示例 1：

输入：num = 4325
输出：59
解释：我们可以将 4325 分割成 num1 = 24 和 num2 = 35 ，和为 59 ，59 是最小和。
     */
    public class Class6312
    {
        public int SplitNum(int num)
        {
            int res = 0;
            List<int> lst = new List<int>();
            while (num != 0)
            {
                if (num % 10 != 0)
                {
                    lst.Add(num % 10);
                }                
                num /= 10;
            }
            int[] arr = lst.ToArray();
            Array.Sort(arr);
            int evenSum = 0;
            int oddSum = 0;
            for(int i =0;i< arr.Length; i++)
            {
                if (i % 2 == 0)
                {
                    evenSum = evenSum * 10 + arr[i];
                }
                else
                {
                    oddSum = oddSum * 10 + arr[i];
                }
            }
            res = evenSum + oddSum;
            return res;
        }
    }
}

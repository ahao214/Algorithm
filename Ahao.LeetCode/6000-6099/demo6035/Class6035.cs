using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._6000_6099.demo6035
{
    /*
     6035. 选择建筑的方案数 显示英文描述 
题目难度Medium
给你一个下标从 0 开始的二进制字符串 s ，它表示一条街沿途的建筑类型，其中：

s[i] = '0' 表示第 i 栋建筑是一栋办公楼，
s[i] = '1' 表示第 i 栋建筑是一间餐厅。
作为市政厅的官员，你需要随机 选择 3 栋建筑。然而，为了确保多样性，选出来的 3 栋建筑 相邻 的两栋不能是同一类型。

比方说，给你 s = "001101" ，我们不能选择第 1 ，3 和 5 栋建筑，因为得到的子序列是 "011" ，有相邻两栋建筑是同一类型，所以 不合 题意。
请你返回可以选择 3 栋建筑的 有效方案数 。
     */
    public class Class6035
    {
        public long NumberOfWays(string s)
        {
            return GetLong(s, "101") + GetLong(s, "010");
        }

        private long GetLong(string s, string t)
        {
            long a = 0, b = 0, c = 0;
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == t[2])
                    c += b;
                if (s[i] == t[1])
                    b += a;
                if (s[i] == t[0])
                    a += 1;
            }

            return c;
        }
    }
}

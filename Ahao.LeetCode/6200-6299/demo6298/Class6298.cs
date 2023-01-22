using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._6200_6299.demo6298
{
    /*
      6298. 执行逐位运算使字符串相等 

给你两个下标从 0 开始的 二元 字符串 s 和 target ，两个字符串的长度均为 n 。你可以对 s 执行下述操作 任意 次：

选择两个 不同 的下标 i 和 j ，其中 0 <= i, j < n 。
同时，将 s[i] 替换为 (s[i] OR s[j]) ，s[j] 替换为 (s[i] XOR s[j]) 。
例如，如果 s = "0110" ，你可以选择 i = 0 和 j = 2，然后同时将 s[0] 替换为 (s[0] OR s[2] = 0 OR 1 = 1)，并将 s[2] 替换为 (s[0] XOR s[2] = 0 XOR 1 = 1)，最终得到 s = "1110" 。

如果可以使 s 等于 target ，返回 true ，否则，返回 false 。
     示例 1：

输入：s = "1010", target = "0110"
输出：true
解释：可以执行下述操作：
- 选择 i = 2 和 j = 0 ，得到 s = "0010".
- 选择 i = 2 和 j = 1 ，得到 s = "0110".
可以使 s 等于 target ，返回 true 。
     */
    public class Class6298
    {
        public bool MakeStringsEqual(string s, string target)
        {
            int n = s.Length;
            int i = 0;
            if (s == target)
                return false;
            for (i = 0; i < n; i++)
            {
                if (target[i] == '1')
                    break;
            }
            if (i == n)
                return false;
            for (i = 0; i < n; i++)
            {
                if (s[i] == '1')
                    break;
            }
            if (i == n)
                return false;
            return true;
        }

        public bool makeStringsEqual2(string s, string target)
        {
            int cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == '1')
                {
                    cnt1++;
                }
                if (target[i] == '1')
                {
                    cnt2++;
                }
            }
            if (cnt1 == 0)
            {
                return cnt2 == 0;
            }
            else
            {
                return cnt2 > 0;
            }

        }
    }
}

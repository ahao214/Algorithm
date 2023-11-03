using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0400_0499.demo421
{
    public class Class421
    {
        // 最高位的二进制位编号为 30
        const int HIGH_BIT = 30;

        public int FindMaximumXOR(int[] nums)
        {
            int x = 0;
            for (int k = HIGH_BIT; k >= 0; --k)
            {
                ISet<int> seen = new HashSet<int>();
                // 将所有的 pre^k(a_j) 放入哈希表中
                foreach (int num in nums)
                {
                    // 如果只想保留从最高位开始到第 k 个二进制位为止的部分
                    // 只需将其右移 k 位
                    seen.Add(num >> k);
                }

                // 目前 x 包含从最高位开始到第 k+1 个二进制位为止的部分
                // 我们将 x 的第 k 个二进制位置为 1，即为 x = x*2+1
                int xNext = x * 2 + 1;
                bool found = false;

                // 枚举 i
                foreach (int num in nums)
                {
                    if (seen.Contains(xNext ^ (num >> k)))
                    {
                        found = true;
                        break;
                    }
                }

                if (found)
                {
                    x = xNext;
                }
                else
                {
                    // 如果没有找到满足等式的 a_i 和 a_j，那么 x 的第 k 个二进制位只能为 0
                    // 即为 x = x*2
                    x = xNext - 1;
                }
            }
            return x;
        }


    }
}

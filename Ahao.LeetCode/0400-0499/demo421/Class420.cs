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




        // 字典树的根节点
        Trie root = new Trie();
        // 最高位的二进制位编号为 30
        const int HIGH_BIT2 = 30;

        public int FindMaximumXOR2(int[] nums)
        {
            int n = nums.Length;
            int x = 0;
            for (int i = 1; i < n; ++i)
            {
                // 将 nums[i-1] 放入字典树，此时 nums[0 .. i-1] 都在字典树中
                Add(nums[i - 1]);
                // 将 nums[i] 看作 ai，找出最大的 x 更新答案
                x = Math.Max(x, Check(nums[i]));
            }
            return x;
        }

        public void Add(int num)
        {
            Trie cur = root;
            for (int k = HIGH_BIT; k >= 0; --k)
            {
                int bit = (num >> k) & 1;
                if (bit == 0)
                {
                    if (cur.left == null)
                    {
                        cur.left = new Trie();
                    }
                    cur = cur.left;
                }
                else
                {
                    if (cur.right == null)
                    {
                        cur.right = new Trie();
                    }
                    cur = cur.right;
                }
            }
        }

        public int Check(int num)
        {
            Trie cur = root;
            int x = 0;
            for (int k = HIGH_BIT; k >= 0; --k)
            {
                int bit = (num >> k) & 1;
                if (bit == 0)
                {
                    // a_i 的第 k 个二进制位为 0，应当往表示 1 的子节点 right 走
                    if (cur.right != null)
                    {
                        cur = cur.right;
                        x = x * 2 + 1;
                    }
                    else
                    {
                        cur = cur.left;
                        x = x * 2;
                    }
                }
                else
                {
                    // a_i 的第 k 个二进制位为 1，应当往表示 0 的子节点 left 走
                    if (cur.left != null)
                    {
                        cur = cur.left;
                        x = x * 2 + 1;
                    }
                    else
                    {
                        cur = cur.right;
                        x = x * 2;
                    }
                }
            }
            return x;
        }


        class Trie
        {
            // 左子树指向表示 0 的子节点
            public Trie left = null;
            // 右子树指向表示 1 的子节点
            public Trie right = null;
        }




    }
}

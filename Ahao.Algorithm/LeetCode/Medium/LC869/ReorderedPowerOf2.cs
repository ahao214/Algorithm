using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 869. 重新排序得到 2 的幂
    /// </summary>
    public class ReorderedPowerOf2
    {
        bool[] vis;
        public bool Method(int n)
        {
            char[] nums = n.ToString().ToCharArray();
            Array.Sort(nums);
            vis = new bool[nums.Length];
            return Backtrack(nums, 0, 0);
        }

        public bool Backtrack(char[] nums, int idx, int num)
        {
            if (idx == nums.Length)
            {
                return IsPowerOfTwo(num);
            }
            for (int i = 0; i < nums.Length; ++i)
            {
                // 不能有前导零
                if ((num == 0 && nums[i] == '0') || vis[i] || (i > 0 && !vis[i - 1] && nums[i] == nums[i - 1]))
                {
                    continue;
                }
                vis[i] = true;
                if (Backtrack(nums, idx + 1, num * 10 + nums[i] - '0'))
                {
                    return true;
                }
                vis[i] = false;
            }
            return false;
        }

        public bool IsPowerOfTwo(int n)
        {
            return (n & (n - 1)) == 0;
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0200_0299.demo283
{
    public class Class283
    {
        public void MoveZeroes(int[] nums)
        {
            if (nums == null || nums.Length == 0)
                return;
            for (int i = 0, cur = 0; i < nums.Length; i++)
            {
                if (nums[i] == 0) continue;
                if (cur != i)
                {
                    nums[cur] = nums[i];
                    nums[i] = 0;
                }
                cur++;
            }
        }
    }
}

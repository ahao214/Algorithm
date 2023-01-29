using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.比赛
{
    /*
     6340. 统计上升四元组

 给你一个长度为 n 下标从 0 开始的整数数组 nums ，它包含 1 到 n 的所有数字，请你返回上升四元组的数目。

 如果一个四元组 (i, j, k, l) 满足以下条件，我们称它是上升的：

 0 <= i < j < k < l < n 且
 nums[i] < nums[k] < nums[j] < nums[l] 。


 示例 1：

 输入：nums = [1,3,2,4,5]
 输出：2
 解释：
 - 当 i = 0 ，j = 1 ，k = 2 且 l = 3 时，有 nums[i] < nums[k] < nums[j] < nums[l] 。
 - 当 i = 0 ，j = 1 ，k = 2 且 l = 4 时，有 nums[i] < nums[k] < nums[j] < nums[l] 。
 没有其他的四元组，所以我们返回 2 。
     */
    public class Class6340
    {
        public long CountQuadruplets(int[] nums)
        {
            long res = 0;
            int n = nums.Length;            
            int minCount = 0;
            int maxCount = 0;
            for(int i = 1;i < n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (nums[j] > nums[i])
                        minCount++;                    
                }
                for(int k = i + 1;k < n; k++)
                {
                    if (nums[k] > nums[i])
                        maxCount++;
                }
                res += Math.Max(minCount, maxCount);
            }
            return res;
        }

    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo18
{
    /*
     18. 四数之和
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。
     */
    public class Class18
    {
        public IList<IList<int>> FourSum(int[] nums, int target)
        {
            IList<IList<int>> resultList = new List<IList<int>>();
            int Length = nums.Length;
            if (nums == null || Length < 4) return resultList;
            Array.Sort(nums);
            for (int i = 0; i < Length; i++)
            {
                if (i > 0 && nums[i] == nums[i - 1]) continue;//去重
                for (int j = i + 1; j < Length; j++)
                {
                    if (j > i + 1 && nums[j] == nums[j - 1]) continue;//去重
                    int L = j + 1;
                    int R = Length - 1;
                    while (L < R)
                    {
                        int sum = nums[i] + nums[j] + nums[L] + nums[R];
                        if (sum == target)
                        {
                            resultList.Add(new List<int> { nums[i], nums[j], nums[L], nums[R] });
                            while (L < R && nums[L] == nums[L + 1]) L++;//去重
                            while (L < R && nums[R] == nums[R - 1]) R--;//去重
                            L++;
                            R--;
                        }
                        else if (sum > target) R--;
                        else if (sum < target) L++;
                    }
                }
            }
            return resultList;
        }
    }
}

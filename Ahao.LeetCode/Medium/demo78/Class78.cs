using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo78
{
    /*
     78. 子集
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
     */
    public class Class78
    {
        List<IList<int>> result = new List<IList<int>>();
        public IList<IList<int>> Subsets(int[] nums)
        {
            List<int> temp = new List<int>();
            int start = 0;
            int len = nums.Length;
            Dfs(start, len, temp, nums);
            return result;
        }

        public void Dfs(int start, int len, List<int> temp, int[] nums)
        {
            result.Add(new List<int>(temp));
            for (; start < len; start++)
            {
                temp.Add(nums[start]);
                Dfs(start + 1, len, temp, nums);
                temp.RemoveAt(temp.Count - 1);
            }
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo90
{
    /*
     90. 子集 II
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
     */
    public class Class90
    {
        public IList<IList<int>> SubsetsWithDup(int[] nums)
        {
            IList<IList<int>> lstAllRes = new List<IList<int>>();
            if (nums.Length == 0) return lstAllRes;

            Array.Sort(nums);

            Stack<int> path = new Stack<int>();
            dfs(nums, 0, path, lstAllRes);
            return lstAllRes;
        }

        private void dfs(int[] nums, int begin, Stack<int> path, IList<IList<int>> lstAllRes)
        {
            lstAllRes.Add(new List<int>(path));

            for (int i = begin; i < nums.Length; i++)
            {
                //剪枝
                if (i > begin && nums[i] == nums[i - 1])
                    continue;
                path.Push(nums[i]);
                dfs(nums, i + 1, path, lstAllRes);
                path.Pop();
            }
        }
    }
}

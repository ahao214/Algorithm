using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._6000_6099.demo6041
{
    /*
     6041. 多个数组求交集 
通过的用户数1546
尝试过的用户数1647
用户总通过次数1549
用户总提交次数1937
题目难度Easy
给你一个二维整数数组 nums ，其中 nums[i] 是由 不同 正整数组成的一个非空数组，按 升序排列 返回一个数组，数组中的每个元素在 nums 所有数组 中都出现过。
     */
    public class Class6041
    {
        public IList<int> Intersection(int[][] nums)
        {
            //int[][] nums = new int[3][];
            //nums[0] = new int[5] { 4, 1, 2, 3, 5 };
            //nums[1] = new int[4] { 1, 3, 2, 4 };
            //nums[2] = new int[4] { 3, 4, 5, 6 };
            IList<int> res = new List<int>();
            Dictionary<int, int> dic = new Dictionary<int, int>();

            for (int i = 0; i < nums.Length; i++)
            {
                Array.Sort(nums[i]);
                for (int j = 0; j < nums[i].Length; j++)
                {
                    if (!dic.ContainsKey(nums[i][j]))
                    {
                        dic.Add(nums[i][j], 1);
                    }
                    else
                    {
                        dic[nums[i][j]]++;
                    }
                }
            }

            foreach (KeyValuePair<int, int> ns in dic)
            {
                if (ns.Value == nums.Length)
                    res.Add(ns.Key);
            }

            return res;
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium
{
    /*
     5991. 按符号重排数组
     给你一个下标从 0 开始的整数数组 nums ，数组长度为 偶数 ，由数目相等的正整数和负整数组成。

你需要 重排 nums 中的元素，使修改后的数组满足下述条件：

任意 连续 的两个整数 符号相反
对于符号相同的所有整数，保留 它们在 nums 中的 顺序 。
重排后数组以正整数开头。
重排元素满足上述条件后，返回修改后的数组。
     */
    public class Class5991
    {
        public int[] RearrangeArray(int[] nums)
        {
            List<int> lstA = new List<int>();
            List<int> lstB = new List<int>();
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] > 0)
                    lstA.Add(nums[i]);
                else
                    lstB.Add(nums[i]);
            }
            int n = nums.Length;
            n /= 2;
            List<int> res = new List<int>();
            for (int i = 0; i < n; i++)
            {
                res.Add(lstA[i]);
                res.Add(lstB[i]);
            }
            return res.ToArray();
        }       
    }
}

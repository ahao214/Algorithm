using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo18
{
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

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 18.四数之和
    /// </summary>
    public class FourSum
    {
        public IList<IList<int>> Method(int[] nums, int target)
        {
            var result = new List<IList<int>>();
            if (nums == null || nums.Length < 4)
            {
                return result;
            }
            Array.Sort(nums);
            for (int i = 0; i < nums.Length; i++)
            {
                if (i > 0 && nums[i] == nums[i - 1]) continue;//去重
                for (int j = i + 1; j < nums.Length; j++)
                {
                    if (j > i + 1 && nums[j] == nums[j - 1]) continue;//去重
                    int L = j + 1;
                    int R = nums.Length - 1;
                    while (L < R)
                    {
                        int sum = nums[i] + nums[j] + nums[L] + nums[R];
                        if (sum == target)
                        {
                            result.Add(new List<int> { nums[i], nums[j], nums[L], nums[R] });
                            while (L < R && nums[L] == nums[L + 1])
                            {
                                L++;
                            }
                            while (L < R && nums[R] == nums[R - 1])
                            {
                                R--;
                            }
                            L++;
                            R--;
                        }
                        else if (sum > target)
                        {
                            R--;
                        }
                        else if (sum < target)
                        {
                            L++;
                        }
                    }
                }
            }
            return result;
        }
    }
}

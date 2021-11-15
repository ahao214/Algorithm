using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 368. 最大整除子集
    /// </summary>
    public class LargestDivisibleSubset
    {
        public IList<int> Method(int[] nums)
        {
            Array.Sort(nums);
            List<int> lst = new List<int>();
            if (nums.Length == 1)
            {
                lst.Add(nums[0]);
                return lst;
            }
            int[] arr = new int[nums.Length];
            int maxIndex = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                arr[i] = 1;
                for (int j = 0; j < i; j++)
                {
                    if (nums[i] % nums[j] == 0)
                        arr[i] = Math.Max(arr[i], arr[j] + 1);
                }
                if (arr[i] > arr[maxIndex])
                    maxIndex = i;
            }
            List<int> newLst = new List<int>();

            newLst.Add(nums[maxIndex]);

            for (int i = nums.Length - 1; i >= 0 && arr[maxIndex] > 1; i--)
            {
                if (arr[maxIndex] - 1 == arr[i] && nums[maxIndex] % nums[i] == 0)
                {
                    newLst.Add(nums[i]);
                    maxIndex = i;
                }
            }
            return newLst;
        }
    }
}

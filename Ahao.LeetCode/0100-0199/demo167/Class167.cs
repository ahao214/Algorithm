using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0100_0199.demo167
{
    internal class Class167
    {
        public int[] TwoSum(int[] numbers, int target)
        {
            int left = 0;
            int right = numbers.Length - 1;
            while (left < right)
            {
                if (numbers[left] + numbers[right] < target)
                {
                    left++;
                }
                else if (numbers[left] + numbers[right] > target)
                {
                    right--;
                }
                else
                {
                    break;
                }
            }
            return new int[] { left + 1, right + 1 };
        }

    }
}

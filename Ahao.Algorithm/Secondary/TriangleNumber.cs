using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 611. 有效三角形的个数
    /// </summary>
    public class TriangleNumber
    {
        public int Method(int[] nums)
        {
            int result = 0;

            Array.Sort(nums);
            int len = nums.Length;
            for (int i = 0; i < len; i++)
            {
                for (int j = i + 1; j < len; j++)
                {
                    for (int k = j + 1; k < len; k++)
                    {
                        if (nums[i] + nums[j] > nums[k])
                            result++;
                    }
                }
            }

            return result;
        }

        public int Methods(int[] nums)
        {
            int result = 0;
            Array.Sort(nums);
            int len = nums.Length;
            for (int i = 0; i < len; i++)
            {
                for (int j = i + 1; j < len; ++j)
                {
                    int left = j + 1;
                    int right = len - 1;
                    int k = j;
                    while (left <= right)
                    {
                        int mid = (left + right) / 2;
                        if (nums[mid] < nums[i] + nums[j])
                        {
                            k = mid;
                            left = mid + 1;
                        }
                        else
                        {
                            right = mid - 1;
                        }
                    }
                    result += k - j;
                }
            }
            return result;
        }     
    }
}

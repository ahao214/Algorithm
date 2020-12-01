using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 34. 在排序数组中查找元素的第一个和最后一个位置
    /// </summary>
    public class SearchRange
    {
        public int[] Method(int[] nums, int target)
        {            
            if (nums.Length == 1 && nums[0] == target)
            {
                return new int[] { 0, 0 };
            }


            for (var i = 0; i < nums.Length; i++)
            {
                if (nums[i] == target)
                {
                    for (int j = nums.Length - 1; j >= 0; j--)
                    {
                        if (nums[j] == target)
                        {
                            return new[] { i, j };
                        }
                    }
                }
            }
            return new[] { -1, -1 };
        }
    }

}

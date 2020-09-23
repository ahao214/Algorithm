using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 217.存在重复元素
    /// </summary>
    public class ContainsDuplicate
    {
        public bool Method(int[] nums)
        {
            bool IsTrue = false;
            Array.Sort(nums);
            for (var i = 0; i < nums.Length - 1; i++)
            {
                if (nums[i] == nums[i + 1])
                {
                    IsTrue = true;
                    break;
                }
            }

            return IsTrue;
        }
    }
}

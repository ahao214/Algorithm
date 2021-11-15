using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Management;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 724. 寻找数组的中心索引
    /// </summary>
    public class PivotIndex
    {
        /// <summary>
        /// 获取第一个中心索引
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int Method(int[] nums)
        {
            int result = -1;
            if (nums.Length == 0)
            {
                return result;
            }

            int allSum = 0;
            int leftSum = 0;

            for (int i = 0; i < nums.Length; i++)
            {
                allSum += nums[i];
            }
            for (int j = 0; j < nums.Length; j++)
            {
                if (j != 0)
                {
                    leftSum += nums[j - 1];
                }
                allSum -= nums[j];
                if (leftSum == allSum)
                {                   
                    result = j;
                    break;
                }
            }

            return result;
        }

        /// <summary>
        /// 获取所有的中心索引
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public List<int> Method2(int[] nums)
        {            
            var result = new List<int>();
            if (nums.Length == 0)
            {
                return result;
            }

            int allSum = 0;
            int leftSum = 0;

            for (int i = 0; i < nums.Length; i++)
            {
                allSum += nums[i];
            }
            for (int j = 0; j < nums.Length; j++)
            {
                if (j != 0)
                {
                    leftSum += nums[j - 1];
                }
                allSum -= nums[j];
                if (leftSum == allSum)
                {
                    result.Add(j);
                }
            }

            return result;
        }
    }
}

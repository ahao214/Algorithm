using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 求解n-m问题
    /// </summary>
    public class TestFindSingleNumber
    {
        public static int FindSingleNumber(int[] nums, int m, int n)
        {
            Dictionary<int, int> dict = new Dictionary<int, int>();
            for (int i = 0; i < nums.Length; i++)
            {
                if (dict.ContainsKey(nums[i]))
                {
                    //如果数字已经存在，则更新存在次数
                    dict[nums[i]] = dict[nums[i]] + 1;
                }
                else
                {
                    //数字不存在则添加到字典中
                    dict.Add(nums[i], 1);
                }
            }

            foreach (var item in dict)
            {
                if (item.Value == m)
                {
                    return item.Key;
                }
            }
            return 0;
        }

    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 如何找出数组总出现奇数次的数
    /// </summary>
    public class TestGetOddNumberHash
    {
        /// <summary>
        /// Hash方法
        /// </summary>
        /// <param name="arr"></param>
        public static void GetOddNumberHash(int[] arr)
        {
            if (arr == null || arr.Length < 1)
            {
                Console.WriteLine("参数不合法");
                return;
            }

            Dictionary<int, int> map = new Dictionary<int, int>();
            int i;
            for (i = 0; i < arr.Length; i++)
            {
                //map中没有这个数字，说明第一次出现，value赋值为1
                if (!map.ContainsKey(arr[i]))
                {
                    map.Add(arr[i], 1);
                }
                //当前遍历的值在map中，说明前面出现过，value赋值为0
                else
                {
                    map[arr[i]] = 0;
                }
            }
            foreach (var item in map)
            {
                if (item.Value == 1)
                {
                    Console.WriteLine(item.Key);
                }
            }
        }

/// <summary>
/// 异或法
/// </summary>
/// <param name="arr"></param>
        public static void GetOddNumberYH(int[] arr)
        {
            
        }
        
    }

}
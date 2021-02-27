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
            if (arr == null || arr.Length < 1)
            {
                Console.WriteLine("参数不合法");
                return;
            }

            int result = 0;
            int position = 0;
            //计算数组中所有数字异或的结果
            for (int i = 0; i < arr.Length - 1; i++)
            {
                result = result ^ arr[i];
            }

            int tmpResult = result; //临时保存异或结果
            //找出异或结果中其中一个位值为1的为数(如1100，位值为1位数未2和3)
            for (int i = result; (i & 1) == 0; i = i >> 1)
            {
                position++;
            }

            for (int i = 0; i < arr.Length; i++)
            {
                //异或的结果与所有第position位为1的异或数，结果一定是出现一次的两个数中其中一个
                if (((arr[i] >> position) & 1) == 1)
                {
                    result = result ^ arr[i];
                }
            }
            Console.WriteLine(result);
            //得到另外一个出现一次的数
            Console.WriteLine(result ^ tmpResult);
        }
        
    }

}
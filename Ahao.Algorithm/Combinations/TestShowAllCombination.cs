using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Combinations
{
    /// <summary>
    /// 求正整数n所有可能的整数组合
    /// </summary>
    public class TestShowAllCombination
    {
        /// <summary>
        /// 求和为n的所有整数组合
        /// </summary>
        /// <param name="sum"></param>
        /// <param name="result"></param>
        /// <param name="count"></param>
        private static void GetAllCombination(int sum, int[] result, int count)
        {
            if (sum < 0)
                return;
            int i;
            //数字的组合满足和为sum的条件，打印出所有的组合
            if (sum == 0)
            {
                Console.WriteLine("满足条件的组合:");
                for (i = 0; i < count; i++)
                {
                    Console.WriteLine(result[i] + " ");
                }
                Console.WriteLine();
                return;
            }

            //打印debug信息，为了便于理解
            Console.WriteLine("---当前组合:");
            for (i = 0; i < count; i++)
                Console.WriteLine(result[i] + " ");
            Console.WriteLine("---");
            //确定组合中下一个取值
            i = (count == 0 ? 1 : result[count - 1]);
            Console.WriteLine("---" + "i=" + i + " count=" + count + "---");
            for (; i <= sum;)
            {
                result[count++] = i;
                GetAllCombination(sum - i, result, count);  //求和为sum-i的组合
                count--;    //递归完成后，去掉最后一个组合的数字
                i++;            //找下一个数字作为组合中的数字
            }
        }

        /// <summary>
        /// 找出和为n的所有整数的组合
        /// </summary>
        /// <param name="n"></param>
        public static void ShowAllCombination(int n)
        {
            if (n < 1)
            {
                Console.WriteLine("参数不满足要求");
                return;
            }
            int[] result = new int[n];  //存储和为n的组合方式
            GetAllCombination(n, result, 0);
        }

    }
}

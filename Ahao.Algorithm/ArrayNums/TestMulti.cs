using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 进行大整数相乘
    /// </summary>
    public class TestMulti
    {
        public static void Multi(string num1, string num2)
        {
            //字符串转数组
            int[] a = num1.ToCharArray().ToList().Select(p => int.Parse(p.ToString())).ToArray();
            int[] b = num2.ToCharArray().ToList().Select(p => Convert.ToInt32(p.ToString())).ToArray();

            int aLength = a.Length;
            int bLength = b.Length;

            int[] ret = new int[aLength + bLength];
            for (int i = aLength - 1; i >= 0; i--)
            {
                //关键点，记录结果在数组中的存储位置
                int k = aLength - i - 1;
                for (int j = bLength - 1; j >= 0; j--)
                {
                    ret[k] += a[i] * b[j];
                    k++;
                }
            }

            for (int i = 0; i < ret.Length; i++)
            {
                if (ret[i] >= 10)
                {
                    //注意检查每一位的累加和，看是否需要进位
                    ret[i + 1] += ret[i] / 10;
                    ret[i] = ret[i] % 10;
                }
            }

            for (int i = ret.Length - 1; i >= 0; i--)
            {
                Console.Write(ret[i]);
            }

        }
    }
}

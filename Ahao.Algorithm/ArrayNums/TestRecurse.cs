using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 求集合的所有子集
    /// </summary>
    public class TestRecurse
    {
        public static void SubSet(string str)
        {
            List<string> list = new List<string>();
            for (int i = 1; i <= str.Length; i++)
            {
                Recurse(str, i, list);
            }
        }

        static void Recurse(string str, int i, List<string> list)
        {
            if (i == 0)
            {
                if (list != null && list.Count > 0)
                {
                    Console.WriteLine(string.Join(",", list));
                }
                list = new List<string>();
            }

            if (str.Length != 0)
            {
                //选中第一个元素
                list.Add(str.First().ToString());
                Recurse(str.Substring(1), i - 1, list);
                //不选中第一个元素
                list.Remove(str.First().ToString());
                Recurse(str.Substring(1), i, list);
            }
        }


        public static void Find(string[] array)
        {
            int n = array.Length;
            //循环2^n次
            for (int i = 0; i < (1 << n); i++)
            {
                //将int值转换成二进制的字符串
                String setStr = Convert.ToString(i, 2);
                //需要做对其处理，切记
                int unChoose = n - setStr.Length;
                for (int j = 0; j < setStr.Length; j++)
                {
                    if (setStr[j] == '1')  //1表示被选中，0表示没有被选中
                        Console.Write(array[unChoose + j]);
                }
                Console.WriteLine();
            }
        }


    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Combinations
{
    /// <summary>
    /// 如何拿到最多的金币
    /// </summary>
    public class TestGetMaxNum
    {
        public static bool GetMaxNum(int n)
        {
            if (n < 1)
            {
                Console.WriteLine("参数不合法");
                return false;
            }


            int i;
            int[] a = new int[n];
            //随机生成n个房间里金币的个数
            Random random = new Random();
            for (i = 0; i < n; i++)
            {
                a[i] = random.Next(n) + 1;  //生成1-n的随机数
            }

            //找出前四个房间中最多的金币个数
            int max4 = 0;
            for (i = 0; i < 4; i++)
            {
                if (a[i] > max4)
                    max4 = a[i];
            }
            for (i = 4; i < n - 1; i++)
            {
                if (a[i] > max4)
                    return true;
            }
            return false;
        }



    }
}

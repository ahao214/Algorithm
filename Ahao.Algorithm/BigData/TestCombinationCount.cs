using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.BigData
{
    /// <summary>
    /// 组合1、2、5这三个数字使其和为100
    /// </summary>
    public class TestCombinationCount
    {
        #region 蛮力方法

        public static int CombinationCount(int n)
        {
            int count = 0;
            int num1 = n;           //1 最多的个数
            int num2 = n / 2;      //2 最多的个数
            int num5 = n / 5;       //5 最多的个数
            for (int x = 0; x <= num1; x++)
            {
                for (int y = 0; y <= num2; y++)
                {
                    for (int z = 0; z <= num5; z++)
                    {
                        if (x + 2 * y + 5 * z == n)    //满足条件
                        {
                            count++;
                        }
                    }
                }
            }
            return count;
        }

        #endregion

    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Lintcode._0001_0099
{
    public class Class56
    {

        #region 56 · 两数之和

        /*
         给一个整数数组，找到两个数使得他们的和等于一个给定的数 target。

        你需要实现的函数twoSum需要返回这两个数的下标, 并且第一个下标小于第二个下标。注意这里下标的范围是 0 到 n-1。
         */

        #endregion

        public int[] twoSum(int[] numbers, int target)
        {
            for (int i = 0; i < numbers.Length; i++)
            {
                int tmp = target - numbers[i];
                int j = Array.IndexOf(numbers, tmp, i + 1);
                if (j >= 0)
                    return new int[] { i, j };
            }
            return Array.Empty<int>();
        }
    }
}

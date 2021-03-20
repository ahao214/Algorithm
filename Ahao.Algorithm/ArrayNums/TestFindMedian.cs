using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 求2个有序数组合并后的中位数
    /// </summary>
    public class TestFindMedian
    {
        public static int FindMedian(int[] a, int n1, int[] b, int n2)
        {
            int m1 = (n1 - 1) / 2, m2 = (n2 - 1) / 2;
            if (n1 == 1)
            {
                //递归结束条件
                if (n2 == 1)
                {
                    return a[0] < b[0] ? a[0] : b[0];
                }
                if (n2 % 2 == 0)
                {
                    if (a[0] >= b[m2 + 1])
                        return b[m2 + 1];
                    else if (a[0] <= b[m2])
                        return b[m2];
                    else
                        return a[0];
                }
                else
                {
                    if (a[0] >= b[m2])
                        return b[m2];
                    else if (a[0] <= b[m2 - 1])
                        return b[m2 - 1];
                    else
                        return a[0];
                }
            }
            else if (n2 == 1)
            {
                //递归结束条件
                if (n1 % 2 == 0)
                {
                    if (b[0] >= a[m1 + 1])
                        return a[m1 + 1];
                    else if (b[0] <= a[m1])
                        return a[m1];
                    else
                        return b[0];
                }
                else
                {
                    if (b[0] >= a[m1])
                        return a[m1];
                    else if (b[0] <= a[m1 - 1])
                        return a[m1 - 1];
                    else
                        return b[0];
                }
            }
            else
            {
                int cutLen = n1 / 2 > n2 / 2 ? n2 / 2 : n1 / 2;
                //如果每次减去短数组的一半，如果数组长度n是奇数，一半是值(n-1)/2
                if (a[m1] == b[m2])
                    return a[m1];
                else if (a[m1] < b[m2])
                {
                    int[] temp = new int[n1 - cutLen];
                    Array.Copy(a, cutLen, temp, 0, n1 - cutLen);
                    return FindMedian(temp, n1 - cutLen, b, n2 - cutLen);
                }
                else
                {
                    int[] temp = new int[n2 - cutLen];
                    Array.Copy(b, cutLen, temp, 0, n2 - cutLen);
                    return FindMedian(a, n1 - cutLen, temp, n2 - cutLen);
                }
            }

        }
    }
}

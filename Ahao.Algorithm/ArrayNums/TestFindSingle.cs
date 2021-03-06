using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 找出数组中出现1次的数
    /// </summary>
    public class TestFindSingle
    {
        //判断数字n的二进制数从右往左数第i位是否为1
        private bool isOne(int n, int i)
        {
            return ((n & (1 << i)) == 1);
        }

        public int FindSingle(int[] arr)
        {
            int count1, count0, result1, result0;
            int i, j;
            int size = arr.Length;
            for (i = 0; i < 32; i++)
            {
                result1 = result0 = count0 = count1 = 0;
                for (j = 0; j < size; j++)
                {
                    if (isOne(arr[j], i))
                    {
                        result1 ^= arr[j];  //第i位为1的值异或操作
                        count1++;           //第i位为1的数字个数
                    }
                    else
                    {
                        result0 ^= arr[j];  //第i位为0的值异或操作
                        count0++;           //第i位为0的数字个数
                    }
                }

                //bit值为1的子数组元素个数为奇数，且出现1次的数字被分配到bit值为
                //0的子数组说明只有一个出现1次的数字被分配到bit值为1的子数组中，
                //异或结果急事这个出现一次的数字
                if (count1 % 2 == 1 && result0 != 0)
                {
                    return result1;
                }
                //只有一个出现一次的数字被分配到bit值为0的子数组中
                if (count0 % 2 == 1 && result1 != 0)
                {
                    return result0;
                }
            }
            return -1;
        }



    }
}

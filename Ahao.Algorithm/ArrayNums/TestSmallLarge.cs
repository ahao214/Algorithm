using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 找出数组中左边的数都小于等于它，右边的数都大于等于它的数
    /// </summary>
    public class TestSmallLarge
    {
        public static void SmallLarge(int [] array)
        {
            //数据元素必须达到2个以上
            if (array ==null || array .Length <1)
            {
                throw new Exception("数据元素必须达到2个以上");
            }

            int[] rightMin = new int[array.Length];
            rightMin[array.Length - 1] = array[array.Length - 1];
            //将数组rightMin赋值
            for (int i=array .Length-2;i>=0;i--)
            {
                if(array [i]<rightMin [i+1])
                {
                    rightMin[i] = array[i];
                }
                else
                {
                    rightMin[i] = rightMin[i + 1];
                }
            }

            int leftMax = int.MinValue;
            for(int i=0;i<array .Length;i++)
            {
                if(leftMax <=array [i])
                {
                    leftMax = array[i];
                    if(leftMax ==rightMin [i])
                    {
                        Console.Write(leftMax.ToString() + " ");
                    }
                }
            }

        }



    }
}

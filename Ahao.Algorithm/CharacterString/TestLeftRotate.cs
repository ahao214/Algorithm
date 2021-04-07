using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 左旋转字符串
    /// </summary>
    public class TestLeftRotate
    {
        public static void LeftRotate(string[] array, int k)
        {
            if (array == null)
                return;
            int nLen = array.Length;
            int nNumOfGroup = MaxCommonDivisorpublic(nLen, k);
            int nElemInSub = nLen / nNumOfGroup;
            //整个数组分为nNumOfGroup组，每组有nElemInSub个元素
            int i = 0, j = 0;
            for (i = 0; i < nNumOfGroup; i++)
            {
                string cTemp = array[i];

                //每组内循环nElemInSub-1次
                for (j = 0; j < nElemInSub - 1; j++)
                {
                    array[(i + j * k) % nLen] = array[(i + (j + 1) * k) % nLen];
                }
                array[(i + j * k) % nLen] = cTemp;
            }
        }

        static int MaxCommonDivisorpublic(int n1, int n2)
        {
            int temp = Math.Max(n1, n2);
            n2 = Math.Min(n1, n2);  //n2中存放两个数中最小的
            n1 = temp;  //n1中存放两个数中最大的
            while (n2 != 0)
            {
                n1 = n1 > n2 ? n1 : n2; //是n1中的数大于n2中的数
                int m = n1 % n2;
                n1 = n2;
                n2 = m;
            }
            return n1;
        }
    }
}

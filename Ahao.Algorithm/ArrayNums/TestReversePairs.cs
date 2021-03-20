using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 求解数组中逆序对的个数
    /// </summary>
    public class TestReversePairs
    {
        static int count = 0;
        public static long ReversePairs(int[] array)
        {
            if (array.Length <= 1)
                return 0;
            Merge(array, 0, array.Length - 1);
            return count;
        }

        static int[] Merge(int[] array, int start, int end)
        {
            if (start == end)
            {
                return new int[] { array[start] };
            }

            int mid = (start + end) / 2;
            int[] a1 = Merge(array, start, mid);
            int[] a2 = Merge(array, mid + 1, end);
            int i = a1.Length - 1;
            int j = a2.Length - 1;
            int k = a1.Length + a2.Length - 1;
            int[] sort = new int[a1.Length + a2.Length];
            while (i >= 0 && j >= 0)
            {
                if (a1[i] > a2[j])
                {
                    count += (j + 1);
                    sort[k--] = a1[i--];
                }
                else
                {
                    sort[k--] = a2[j--];
                }
            }
            while (i >= 0)
            {
                sort[k--] = a1[i--];
            }
            while (j >= 0)
            {
                sort[k--] = a2[j--];
            }
            return sort;
        }
    }
}

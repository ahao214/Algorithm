using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0600_0699.demo670
{
    public class Class670
    {
        /// <summary>
        /// 方法一：直接遍历
        /// </summary>
        /// <param name="num"></param>
        /// <returns></returns>
        public int MaximumSwap(int num)
        {
            char[] charArray = num.ToString().ToCharArray();
            int n = charArray.Length;
            int maxNum = num;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    Swap(charArray, i, j);
                    maxNum = Math.Max(maxNum, int.Parse(new string(charArray)));
                    Swap(charArray, i, j);
                }
            }
            return maxNum;
        }


        /// <summary>
        /// 方法二：贪心
        /// </summary>
        /// <param name="num"></param>
        /// <returns></returns>
        public int MaximumSwap2(int num)
        {
            char[] charArray = num.ToString().ToCharArray();
            int n = charArray.Length;
            int maxIdx = n - 1;
            int idx1 = -1, idx2 = -1;
            for (int i = n - 1; i >= 0; i--)
            {
                if (charArray[i] > charArray[maxIdx])
                {
                    maxIdx = i;
                }
                else if (charArray[i] < charArray[maxIdx])
                {
                    idx1 = i;
                    idx2 = maxIdx;
                }
            }
            if (idx1 >= 0)
            {
                Swap(charArray, idx1, idx2);
                return int.Parse(new string(charArray));
            }
            else
            {
                return num;
            }
        }

        public void Swap(char[] charArray, int i, int j)
        {
            char temp = charArray[i];
            charArray[i] = charArray[j];
            charArray[j] = temp;
        }

    }
}

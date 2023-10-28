using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0200_0299.demo274
{
    public class Class274
    {
        public int HIndex(int[] citations)
        {
            Array.Sort(citations);
            int h = 0, i = citations.Length - 1;
            while (i >= 0 && citations[i] > h)
            {
                h++;
                i--;
            }
            return h;
        }


        public int HIndex2(int[] citations)
        {
            int n = citations.Length, tot = 0;
            int[] counter = new int[n + 1];
            for (int i = 0; i < n; i++)
            {
                if (citations[i] >= n)
                {
                    counter[n]++;
                }
                else
                {
                    counter[citations[i]]++;
                }
            }
            for (int i = n; i >= 0; i--)
            {
                tot += counter[i];
                if (tot >= i)
                {
                    return i;
                }
            }
            return 0;
        }



        public int HIndex3(int[] citations)
        {
            int left = 0, right = citations.Length;
            int mid = 0, cnt = 0;
            while (left < right)
            {
                // +1 防止死循环
                mid = (left + right + 1) >> 1;
                cnt = 0;
                for (int i = 0; i < citations.Length; i++)
                {
                    if (citations[i] >= mid)
                    {
                        cnt++;
                    }
                }
                if (cnt >= mid)
                {
                    // 要找的答案在 [mid,right] 区间内
                    left = mid;
                }
                else
                {
                    // 要找的答案在 [0,mid) 区间内
                    right = mid - 1;
                }
            }
            return left;
        }


    }
}

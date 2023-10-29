using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0200_0299.demo275
{
    public class Class275
    {
        public int HIndex(int[] citations)
        {
            int n = citations.Length;
            int left = 0, right = n - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (citations[mid] >= n - mid)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            return n - left;
        }

    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2500_2599.demo2517
{
    public class Class2551
    {

        public int MaximumTastiness(int[] price, int k)
        {
            Array.Sort(price);
            int n = price.Length;
            int left = 0;
            int right = price[n - 1] - price[0];
            while (left < right)
            {
                int mid = (left + right + 1) / 2;
                if (Check(price, k, mid))
                {
                    left = mid;
                }
                else
                {
                    right = mid - 1;
                }
            }
            return left;
        }

        public bool Check(int[] price, int k, int tastiness)
        {
            int prev = int.MinValue / 2;
            int cnt = 0;
            foreach (int p in price)
            {
                if (p - prev >= tastiness)
                {
                    cnt++;
                    prev = p;
                }
            }
            return cnt >= k;
        }

    }
}

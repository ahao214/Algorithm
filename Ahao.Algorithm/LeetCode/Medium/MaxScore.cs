using System;
using System.Collections.Generic;
using System.IO.IsolatedStorage;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 1423. 可获得的最大点数
    /// </summary>
    public class MaxScore
    {
        public int Method(int[] cardPoints, int k)
        {
            int len = cardPoints.Length;
            if (k >= len)
            {
                return cardPoints.Sum();
            }
            else
            {
                int[] arr = new int[k];
                for (int i = 0; i < k; i++)
                {
                    arr[i] = cardPoints[i];
                }
                int max = arr.Sum();
                int sum = max;
                int left = arr.Length - 1;
                int right = cardPoints.Length - 1;
                while (left >= 0)
                {
                    sum =sum - arr[left] + cardPoints[right];
                    left--;
                    right--;
                    max = Math.Max(sum, max);
                }
                return max;
            }            
        }
    }
}

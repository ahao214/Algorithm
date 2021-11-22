using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.LessHard.NC128
{
    /// <summary>
    /// NC128 接雨水问题
    /// </summary>
    public class Class128
    {
        public long maxWater(List<int> arr)
        {
            if (arr == null || arr.Count == 0)
            {
                return 0;
            }
            int N = arr.Count;
            int L = 1;
            int R = N - 2;
            int leftMax = arr[0];
            int rightMax = arr[N - 1];
            int water = 0;
            while (L <= R)
            {
                if (leftMax <= rightMax)
                {
                    water += Math.Max(0, leftMax - arr[L]);
                    leftMax = Math.Max(leftMax, arr[L++]);
                }
                else
                {
                    water += Math.Max(0, rightMax - arr[R]);
                    rightMax = Math.Max(rightMax, arr[R--]);
                }
            }
            return water;
        }
    }
}

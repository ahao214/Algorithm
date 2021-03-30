using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 找出和最接近0的子数组
    /// </summary>
    public class TestSubarraySumClosest
    {
        class Pair
        {
            public int Sum { get; set; }
            public int Index { get; set; }
            public Pair(int s,int i)
            {
                Sum = s;
                Index = i;
            }
        }


        public static int []SubarraySumClosest(int[] nums )
        {
            int[] res = new int[2];
            if(nums ==null || nums .Length ==0)
            {
                return res;
            }
            int len = nums.Length;
            if (len ==1)
            {
                return res;
            }
            Pair[] sums = new Pair[len + 1];
            //这里是为只有第一个元素的子数组准备的
            int prev = 0;
            sums[0] = new Pair(0, 0);
            for(int i=1;i<=len;i++)
            {
                sums[i] = new Pair(prev + nums[i - 1], i);
                prev = sums[i].Sum;
            }
            //对Pair里sum项排序
            sums = sums.OrderBy(p => p.Sum).ToArray();
            int max = int.MaxValue;
            //有了上面的排序，那结果一定是出在相邻的两项里，大大减少了计算量
            for(int i=1;i<=len;i++)
            {
                if(max>(sums [i].Sum -sums [i-1].Sum ))
                {
                    max = sums[i].Sum - sums[i - 1].Sum;
                    int[] temp = new int[] { sums[i].Index, sums[i - 1].Index };
                    Array.Sort(temp);

                    res[0] = temp[0];
                    res[1] = temp[1] - 1;
                }
            }
            return res;

        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple
{
    public class Class1725
    {
        public int CountGoodRectangles(int[][] rectangles)
        {
            //int[][] rectangles = new int[4][] { new int[] { 5, 8 }, new int[] { 3, 9 }, new int[] { 5, 12 }, new int[] { 16, 5 } };            

            int result = 0;
            int maxLen = 0;
            Dictionary<int, int> dic = new Dictionary<int, int>();
            foreach (int[] rec in rectangles)
            {
                int minValue = Math.Min(rec[0], rec[1]);
                if (!dic.ContainsKey(minValue))
                {
                    dic.Add(minValue, 1);
                }
                else
                {
                    dic[minValue]++;
                }
            }
            //获取最大的边长
            foreach (var item in dic)
            {
                maxLen = Math.Max(maxLen, item.Key);
            }
            result = dic.GetValueOrDefault(maxLen);
            return result;
        }

        public int CountGoodRectangles1(int[][] rectangles)
        {
            int res = 0, maxLen = 0;
            foreach (int[] rec in rectangles)
            {
                int i = rec[0], j = rec[1];
                int k = Math.Min(i, j);
                if (k == maxLen)
                {
                    ++res;
                }
                else if (k > maxLen)
                {
                    res = 1;
                    maxLen = k;
                }
            }
            return res;
        }

    }
}

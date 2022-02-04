using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple
{
    /*
    1725. 可以形成最大正方形的矩形数目
    给你一个数组 rectangles ，其中 rectangles[i] = [li, wi] 表示第 i 个矩形的长度为 li 、宽度为 wi 。
    如果存在 k 同时满足 k <= li 和 k <= wi ，就可以将第 i 个矩形切成边长为 k 的正方形。例如，矩形 [4,6] 可以切成边长最大为 4 的正方形。
    设maxLen 为可以从矩形数组 rectangles 切分得到的 最大正方形 的边长。
    请你统计有多少个矩形能够切出边长为 maxLen 的正方形，并返回矩形 数目 。
     */
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

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.CodingInterviewGuide.Chapter01.P09
{
    public class RecSize
    {
        public int MaxRecSize(int[][] map)
        {
            if (map == null || map.Length == 0 || map[0].Length == 0)
            {
                return 0;
            }

            int maxArea = 0;
            int[] height = new int[map[0].Length];
            for (int i = 0; i < map.Length; i++)
            {
                for (int j = 0; j < map[0].Length; j++)
                {
                    height[j] = map[i][j] == 0 ? 0 : height[j] + 1;
                }
                maxArea = Math.Max(maxArea, MaxRecFromBottom(height));
            }
            return maxArea;

        }


        public int MaxRecFromBottom(int[] height)
        {
            if (height == null || height.Length == 0)
            {
                return 0;
            }
            int maxArea = 0;
            Stack<int> stk = new Stack<int>();
            for (int i = 0; i < height.Length; i++)
            {
                while (stk.Count != 0 && height[i] <= height[stk.Peek()])
                {
                    int j = stk.Pop();
                    int k = stk.Count == 0 ? -1 : stk.Peek();
                    int curArea = (i - k - 1) * height[i];
                    maxArea = Math.Max(maxArea, curArea);
                }
                stk.Pop();
            }
            while (stk.Count != 0)
            {
                int j = stk.Pop();
                int k = stk.Count == 0 ? -1 : stk.Peek();
                int curArea = (height.Length - k - 1) * height[j];
                maxArea = Math.Max(maxArea, curArea);
            }
            return maxArea;
        }


    }
}

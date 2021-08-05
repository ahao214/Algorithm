using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 802. 找到最终的安全状态
    /// </summary>
    public class EventualSafeNodes
    {
        public IList<int> Method(int[][] graph)
        {
            int n = graph.Length;
            int[] color = new int[n];
            IList<int> result = new List<int>();
            for (int i = 0; i < n; i++)
            {
                if (Safe(graph, color, i))
                {
                    result.Add(i);
                }
            }
            return result;
        }

        public bool Safe(int[][] graph, int[] color, int x)
        {
            if (color[x] > 0)
            {
                return color[x] == 2;
            }
            color[x] = 1;
            foreach (int y in graph[x])
            {
                if (!Safe(graph, color, y))
                {
                    return false;
                }
            }
            color[x] = 2;
            return true;
        }
    }
}

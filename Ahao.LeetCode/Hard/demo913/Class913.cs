using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo913
{
    /// <summary>
    /// 913. 猫和老鼠
    /// </summary>
    public class Class913
    {
        const int MOUSE_WIN = 1;
        const int CAT_WIN = 2;
        const int DRAW = 0;
        int n;
        int[][] graph;
        int[,,] dp;

        public int CatMouseGame(int[][] graph)
        {
            this.n = graph.Length;
            this.graph = graph;
            this.dp = new int[n, n, n * 2];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < n * 2; k++)
                    {
                        dp[i, j, k] = -1;
                    }
                }
            }
            return GetResult(1, 2, 0);
        }

        public int GetResult(int mouse, int cat, int turns)
        {
            if (turns == n * 2)
            {
                return DRAW;
            }
            if (dp[mouse, cat, turns] < 0)
            {
                if (mouse == 0)
                {
                    dp[mouse, cat, turns] = MOUSE_WIN;
                }
                else if (cat == mouse)
                {
                    dp[mouse, cat, turns] = CAT_WIN;
                }
                else
                {
                    GetNextResult(mouse, cat, turns);
                }
            }
            return dp[mouse, cat, turns];
        }

        public void GetNextResult(int mouse, int cat, int turns)
        {
            int curMove = turns % 2 == 0 ? mouse : cat;
            int defaultResult = curMove == mouse ? CAT_WIN : MOUSE_WIN;
            int result = defaultResult;
            int[] nextNodes = graph[curMove];
            foreach (int next in nextNodes)
            {
                if (curMove == cat && next == 0)
                {
                    continue;
                }
                int nextMouse = curMove == mouse ? next : mouse;
                int nextCat = curMove == cat ? next : cat;
                int nextResult = GetResult(nextMouse, nextCat, turns + 1);
                if (nextResult != defaultResult)
                {
                    result = nextResult;
                    if (result != DRAW)
                    {
                        break;
                    }
                }
            }
            dp[mouse, cat, turns] = result;
        }
    }

}

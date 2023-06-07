using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1240
{
    public class Class1240
    {

        int ans;

        public int TilingRectangle(int n, int m)
        {
            ans = Math.Max(n, m);
            bool[][] rect = new bool[n][];
            for (int i = 0; i < n; i++)
            {
                rect[i] = new bool[m];
            }
            DFS(0, 0, rect, 0);
            return ans;
        }

        public void DFS(int x, int y, bool[][] rect, int cnt)
        {
            int n = rect.Length, m = rect[0].Length;
            if (cnt >= ans)
            {
                return;
            }
            if (x >= n)
            {
                ans = cnt;
                return;
            }
            /* 检测下一行 */
            if (y >= m)
            {
                DFS(x + 1, 0, rect, cnt);
                return;
            }
            /* 如当前已经被覆盖，则直接尝试下一个位置 */
            if (rect[x][y])
            {
                DFS(x, y + 1, rect, cnt);
                return;
            }

            for (int k = Math.Min(n - x, m - y); k >= 1 && IsAvailable(rect, x, y, k); k--)
            {
                /* 将长度为 k 的正方形区域标记覆盖 */
                FillUp(rect, x, y, k, true);
                /* 跳过 k 个位置开始检测 */
                DFS(x, y + k, rect, cnt + 1);
                FillUp(rect, x, y, k, false);
            }
        }

        public bool IsAvailable(bool[][] rect, int x, int y, int k)
        {
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    if (rect[x + i][y + j])
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        public void FillUp(bool[][] rect, int x, int y, int k, bool val)
        {
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    rect[x + i][y + j] = val;
                }
            }
        }


    }
}

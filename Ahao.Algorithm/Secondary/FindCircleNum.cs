using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 547. 省份数量
    /// </summary>
    public class FindCircleNum
    {
        #region 深度优先算法

        public int DfsMethod(int[][] isConnected)
        {
            int citys = isConnected.Length;
            bool[] visited = new bool[citys];
            int provinces = 0;  //计数器
            for (int i = 0; i < citys; i++)
            {
                if (!visited[i])
                {
                    //深度优先算法
                    dfs(i, citys, visited, isConnected);
                    provinces++;
                }
            }
            return provinces;
        }

        private void dfs(int i, int citys, bool[] visited, int[][] isConnected)
        {
            for (int j = 0; j < citys; j++)
            {
                if (isConnected[i][j] == 1 && !visited[j])
                {
                    visited[j] = true;
                    dfs(j, citys, visited, isConnected);
                }
            }
        }

        #endregion

        #region 广度优先算法



        #endregion
    }
}

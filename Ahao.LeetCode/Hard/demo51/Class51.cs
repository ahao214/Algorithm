using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo51
{
    /*
     51. N 皇后
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
     */
    public class Class51
    {
        /// <summary>
        /// N皇后问题经典回溯
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public IList<IList<string>> SolveNQueens(int n)
        {
            int[,] ans = new int[n, n];
            IList<IList<string>> printAns = new List<IList<string>>();
            BackTrack(printAns, ans, 0, n);
            return printAns;
        }

        /// <summary>
        /// 回溯且条件后置
        /// </summary>
        private void BackTrack(IList<IList<string>> printAns, int[,] ans, int i, int n)
        {
            if (i == n)
            {
                return;
            }

            //所有的可能在(0-N的位置上)分别填充1
            for (int j = 0; j < n; j++)
            {
                //判断能否填充
                if (NQueue(ans, i, j))
                {
                    ans[i, j] = 1;
                    BackTrack(printAns, ans, i + 1, n);
                }
                ans[i, j] = 0;
            }
            return;
        }

        /// <summary>
        /// N皇后判断规则
        /// </summary>
        private bool NQueue(int[,] ans, int i, int j)
        {
            //判断列元素
            for (int k = 0; k < i; k++)
            {
                if (ans[k, j] == 1) return false;
            }
            //判断左对角线元素
            for (int k = j, u = i; k >= 0 && u >= 0; k--, u--)
            {
                if (ans[u, k] == 1) return false;
            }
            //判断右对角线元素
            for (int k = j, u = i; k < ans.GetLength(0) && u >= 0; k++, u--)
            {
                if (ans[u, k] == 1) return false;
            }
            //判断行元素
            for (int k = 0; k < j; k++)
            {
                if (ans[i, k] == 1) return false;
            }
            return true;
        }

        /// <summary>
        /// 将结果转化为string形式
        /// </summary>
        private List<string> AnsToSting(int[,] ans, int n)
        {
            List<string> outStr = new List<string>();
            for (int i = 0; i < n; i++)
            {
                string str = "";
                for (int j = 0; j < n; j++)
                {
                    str += ans[i, j] == 1 ? "Q" : ".";
                }
                outStr.Add(str);
            }
            return outStr;
        }
    }

}

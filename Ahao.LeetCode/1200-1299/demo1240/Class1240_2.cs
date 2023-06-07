using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1240
{
    public class Class1240_2
    {

        private int res; // 答案。会在DFS过程中更新。
        public int TilingRectangle(int n, int m)
        {
            bool[][] tiled = new bool[n][];
            for (int i = 0; i < n; i++)
            {
                tiled[i] = new bool[m];
            }
            res = m * n;
            process(tiled, 0);
            return res;
        }

        // DFS：当前地上瓷砖状态为tiled，已经铺了count个瓷砖，继续铺下去把地面铺满
        private void process(bool[][] tiled, int count)
        {
            if (count >= res)
            { // 剪枝
                return;
            }
            int[] emptyPos = checkEmpty(tiled); // 地上没瓷砖的第一个位置
            if (emptyPos[0] == -1 && emptyPos[1] == -1)
            { // 已经铺完了所有地方，收集答案
                res = Math.Min(res, count);
                return;
            }
            // 从大到小，开始尝试铺瓷砖
            int maxLen = Math.Min(tiled.Length - emptyPos[0], tiled[0].Length - emptyPos[1]);
            for (int len = maxLen; len >= 1; len--)
            {
                // 尝试用len*len的瓷砖的左上角去对齐地上没瓷砖的这个位置
                if (setStatus(tiled, emptyPos[0], emptyPos[1], emptyPos[0] + len - 1, emptyPos[1] + len - 1, false))
                {
                    process(tiled, count + 1);
                    setStatus(tiled, emptyPos[0], emptyPos[1], emptyPos[0] + len - 1, emptyPos[1] + len - 1, true);
                }
            }
        }

        // 尝试反转 (row1, col1) 和 (row2, col2) 之间的铺瓷砖状态
        // 必须确保这个区域内初始都是hasTiled状态，否则不会反转
        private bool setStatus(bool[][] tiled, int row1, int col1, int row2, int col2, bool hasTiled)
        {
            for (int i = row1; i <= row2; i++)
            {
                for (int j = col1; j <= col2; j++)
                {
                    if (tiled[i][j] != hasTiled)
                    {
                        return false;
                    }
                }
            }
            for (int i = row1; i <= row2; i++)
            {
                for (int j = col1; j <= col2; j++)
                {
                    tiled[i][j] = !tiled[i][j];
                }
            }
            return true;
        }

        // 顺序遍历寻找第一个没铺瓷砖的位置（从上到下，从左到右）
        private int[] checkEmpty(bool[][] tiled)
        {
            int i = 0, j = 0;
            for (; i < tiled.Length; i++)
            {
                for (j = 0; j < tiled[0].Length; j++)
                {
                    if (!tiled[i][j])
                    {
                        return new int[] { i, j };
                    }
                }
            }
            return new int[] { -1, -1 };
        }




    }
}

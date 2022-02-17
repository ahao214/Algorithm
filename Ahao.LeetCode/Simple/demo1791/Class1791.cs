using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1791
{
    /*
1791. 找出星型图的中心节点
有一个无向的 星型 图，由 n 个编号从 1 到 n 的节点组成。星型图有一个 中心 节点，并且恰有 n - 1 条边将中心节点与其他每个节点连接起来。

给你一个二维整数数组 edges ，其中 edges[i] = [ui, vi] 表示在节点 ui 和 vi 之间存在一条边。请你找出并返回 edges 所表示星型图的中心节点。
*/
    public class Class1791
    {
        public int FindCenter(int[][] edges)
        {
            if (edges[0][0] == edges[1][0])
                return edges[0][0];
            else if (edges[0][1] == edges[1][0])
                return edges[0][1];
            else if (edges[0][0] == edges[1][1])
                return edges[0][0];
            else if (edges[0][1] == edges[1][1])
                return edges[0][1];
            else
                return -1;
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._5200_5299.demo5235
{
    /*
     5235. 找出输掉零场或一场比赛的玩家 显示英文描述 
题目难度Medium
给你一个整数数组 matches 其中 matches[i] = [winneri, loseri] 表示在一场比赛中 winneri 击败了 loseri 。

返回一个长度为 2 的列表 answer ：

answer[0] 是所有 没有 输掉任何比赛的玩家列表。
answer[1] 是所有恰好输掉 一场 比赛的玩家列表。
两个列表中的值都应该按 递增 顺序返回。

注意：

只考虑那些参与 至少一场 比赛的玩家。
生成的测试用例保证 不存在 两场比赛结果 相同 。
     */
    public class Class5235
    {
        public IList<IList<int>> FindWinners(int[][] matches)
        {
            //int[][] matches = new int[4][];

            //matches[0] = new int[] { 2, 3 };
            //matches[1] = new int[] { 1, 3 };
            //matches[2] = new int[] { 5, 4 };
            //matches[3] = new int[] { 6, 4 };

            Dictionary<int, int> winDic = new Dictionary<int, int>();
            Dictionary<int, int> loseDic = new Dictionary<int, int>();
            IList<int> win = new List<int>();
            IList<int> lose = new List<int>();

            for (int i = 0; i < matches.Length; i++)
            {
                if (!winDic.ContainsKey(matches[i][0]))
                {
                    winDic.Add(matches[i][0], 1);
                }
                else
                {
                    winDic[matches[i][0]]++;
                }

                if (!loseDic.ContainsKey(matches[i][1]))
                {
                    loseDic.Add(matches[i][1], 1);
                }
                else
                {
                    loseDic[matches[i][1]]++;
                }
            }

            foreach (KeyValuePair<int, int> item in loseDic)
            {
                if (item.Value == 1)
                    lose.Add(item.Key);
            }

            foreach (KeyValuePair<int, int> item in winDic)
            {
                if (!loseDic.ContainsKey(item.Key))
                    win.Add(item.Key);
            }

            IList<IList<int>> res = new List<IList<int>>();

            win = win.OrderBy(g => g).ToArray();
            res.Add(win.ToList());

            lose = lose.OrderBy(g => g).ToList();
            res.Add(lose.ToList());
            return res;
        }
    }
}

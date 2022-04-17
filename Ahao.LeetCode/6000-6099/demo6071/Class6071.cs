using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._6000_6099.demo6071
{
    /*
     *6071. 完成所有任务需要的最少轮数
给你一个下标从 0 开始的整数数组 tasks ，其中 tasks[i] 表示任务的难度级别。在每一轮中，你可以完成 2 个或者 3 个 相同难度级别 的任务。

返回完成所有任务需要的 最少 轮数，如果无法完成所有任务，返回 -1 。

 

示例 1：

输入：tasks = [2,2,3,3,2,4,4,4,4,4]
输出：4
解释：要想完成所有任务，一个可能的计划是：
- 第一轮，完成难度级别为 2 的 3 个任务。 
- 第二轮，完成难度级别为 3 的 2 个任务。 
- 第三轮，完成难度级别为 4 的 3 个任务。 
- 第四轮，完成难度级别为 4 的 2 个任务。 
可以证明，无法在少于 4 轮的情况下完成所有任务，所以答案为 4 。
示例 2：

输入：tasks = [2,3,3]
输出：-1
解释：难度级别为 2 的任务只有 1 个，但每一轮执行中，只能选择完成 2 个或者 3 个相同难度级别的任务。因此，无法完成所有任务，答案为 -1 。
 

提示：

1 <= tasks.length <= 105
1 <= tasks[i] <= 109
     */
    public class Class6071
    {
        public int MinimumRounds(int[] tasks)
        {
            int res = 0;
            Dictionary<int, int> dic = new Dictionary<int, int>();
            foreach (var item in tasks)
            {
                if (!dic.ContainsKey(item))
                {
                    dic.Add(item, 1);
                }
                else
                {
                    dic[item]++;
                }
            }

            foreach (KeyValuePair<int, int> t in dic)
            {
                if (t.Value == 1)
                {
                    res = -1;
                    break;
                }
                int cur = t.Value;
                if (cur == 1)
                    return -1;
                if (cur % 3 == 0)
                    res += cur / 3;
                else if (cur % 3 == 1)
                {
                    res += cur / 3 + 1;
                }
                else
                {
                    res += cur / 3 + 1;
                }
            }

            return res;
        }
    }
}

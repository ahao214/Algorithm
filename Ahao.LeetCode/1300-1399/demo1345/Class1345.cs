using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo1345
{
    /*
     1345. 跳跃游戏 IV
给你一个整数数组 arr ，你一开始在数组的第一个元素处（下标为 0）。

每一步，你可以从下标 i 跳到下标：

i + 1 满足：i + 1 < arr.length
i - 1 满足：i - 1 >= 0
j 满足：arr[i] == arr[j] 且 i != j
请你返回到达数组最后一个元素的下标处所需的 最少操作次数 。

注意：任何时候你都不能跳到数组外面。
     */
    public class Class1345
    {
        public int MinJumps(int[] arr)
        {
            Dictionary<int, IList<int>> idxSameValue = new Dictionary<int, IList<int>>();
            for (int i = 0; i < arr.Length; i++)
            {
                if (!idxSameValue.ContainsKey(arr[i]))
                {
                    idxSameValue.Add(arr[i], new List<int>());
                }
                idxSameValue[arr[i]].Add(i);
            }
            ISet<int> visitedIndex = new HashSet<int>();
            Queue<int[]> queue = new Queue<int[]>();
            queue.Enqueue(new int[] { 0, 0 });
            visitedIndex.Add(0);
            while (queue.Count > 0)
            {
                int[] idxStep = queue.Dequeue();
                int idx = idxStep[0], step = idxStep[1];
                if (idx == arr.Length - 1)
                {
                    return step;
                }
                int v = arr[idx];
                step++;
                if (idxSameValue.ContainsKey(v))
                {
                    foreach (int i in idxSameValue[v])
                    {
                        if (visitedIndex.Add(i))
                        {
                            queue.Enqueue(new int[] { i, step });
                        }
                    }
                    idxSameValue.Remove(v);
                }
                if (idx + 1 < arr.Length && visitedIndex.Add(idx + 1))
                {
                    queue.Enqueue(new int[] { idx + 1, step });
                }
                if (idx - 1 >= 0 && visitedIndex.Add(idx - 1))
                {
                    queue.Enqueue(new int[] { idx - 1, step });
                }
            }
            return 0;
        }
    }
}

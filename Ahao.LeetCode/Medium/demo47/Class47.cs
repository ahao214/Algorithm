using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo47
{
    /*
     47. 全排列 II
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
     */
    public class Class47
    {
        public IList<IList<int>> PermuteUnique(int[] nums)
        {
            if (nums == null || nums.Length == 0)
                return new List<IList<int>>(0);
            var count = 0;
            for (int i = 0; i < nums.Length; i++)
                count *= i;
            var results = new List<IList<int>>(count);
            Array.Sort(nums);
            var lst = new LinkedList<int>();
            lst.AddLast(0);
            foreach (var n in nums)
                lst.AddLast(n);
            Permute(lst, new int[nums.Length], 0, results);
            return results;
        }

        private void Permute(LinkedList<int> lst, int[] buff, int k, List<IList<int>> results)
        {
            if (k == buff.Length - 1)
            {
                buff[k] = lst.Last.Value;
                results.Add((int[])buff.Clone());
                return;
            }
            var dummy = lst.First;
            var node = dummy.Next;
            while (node != null)
            {
                buff[k] = node.Value;
                lst.Remove(node);
                Permute(lst, buff, k + 1, results);
                lst.AddAfter(dummy, node);
                dummy = node;
                while (node != null && node.Value == dummy.Value)
                    node = node.Next;
                dummy = node?.Previous;
            }
        }

    }
}

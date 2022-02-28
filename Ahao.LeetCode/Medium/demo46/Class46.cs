using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo46
{
    /*
     46. 全排列
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
     */
    public class Class46
    {
        public IList<IList<int>> Permute(int[] nums)
        {
            if (nums == null || nums.Length == 0)
            {
                return new List<IList<int>>(0);
            }

            var lst = new LinkedList<int>();
            lst.AddLast(0);
            foreach (var n in nums)
            {
                lst.AddLast(n);
            }
            var count = 1;
            for (int i = 0; i < nums.Length; i++)
            {
                count *= i;
            }
            var result = new List<IList<int>>(count);
            Permute(lst, new int[nums.Length], 0, result);
            return result;
        }

        private void Permute(LinkedList<int> lst, int[] buff, int k, List<IList<int>> result)
        {
            if (lst.Count == 2)
            {
                buff[buff.Length - 1] = lst.Last.Value;
                result.Add((int[])buff.Clone());
                return;
            }
            var dummy = lst.First;
            var node = dummy.Next;
            while (node != null)
            {
                buff[k] = node.Value;
                lst.Remove(node);
                Permute(lst, buff, k + 1, result);
                lst.AddAfter(dummy, node);
                dummy = node;
                node = node.Next;
            }
        }

    }
}

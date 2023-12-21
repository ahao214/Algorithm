using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2800_2899._2866
{
    public class Class2866
    {
        public long MaximumSumOfHeights(IList<int> maxHeights)
        {
            int n = maxHeights.Count;
            long res = 0;
            long[] prefix = new long[n];
            long[] suffix = new long[n];
            Stack<int> stack1 = new Stack<int>();
            Stack<int> stack2 = new Stack<int>();

            for (int i = 0; i < n; i++)
            {
                while (stack1.Count > 0 && maxHeights[i] < maxHeights[stack1.Peek()])
                {
                    stack1.Pop();
                }
                if (stack1.Count == 0)
                {
                    prefix[i] = (long)(i + 1) * maxHeights[i];
                }
                else
                {
                    prefix[i] = prefix[stack1.Peek()] + (long)(i - stack1.Peek()) * maxHeights[i];
                }
                stack1.Push(i);
            }
            for (int i = n - 1; i >= 0; i--)
            {
                while (stack2.Count > 0 && maxHeights[i] < maxHeights[stack2.Peek()])
                {
                    stack2.Pop();
                }
                if (stack2.Count == 0)
                {
                    suffix[i] = (long)(n - i) * maxHeights[i];
                }
                else
                {
                    suffix[i] = suffix[stack2.Peek()] + (long)(stack2.Peek() - i) * maxHeights[i];
                }
                stack2.Push(i);
                res = Math.Max(res, prefix[i] + suffix[i] - maxHeights[i]);
            }
            return res;
        }


        public long MaximumSumOfHeights2(IList<int> maxHeights)
        {
            int n = maxHeights.Count;
            long res = 0;
            for (int i = 0; i < n; i++)
            {
                long cur = maxHeights[i];
                int pre = maxHeights[i];
                for (int j = i + 1; j < n; j++)
                {
                    pre = Math.Min(pre, maxHeights[j]);
                    cur += pre;
                }
                pre = maxHeights[i];
                for (int j = i - 1; j >= 0; j--)
                {
                    pre = Math.Min(pre, maxHeights[j]);
                    cur += pre;
                }
                res = Math.Max(res, cur);
            }
            return res;

        }
    }
}

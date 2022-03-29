using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo739
{
    public class Class739
    {
        public int[] DailyTemperatures(int[] temperatures)
        {
            if (temperatures == null || temperatures.Length == 0)
            {
                return new int[0];
            }

            if (temperatures.Length == 1)
            {
                return new int[] { 0 };
            }

            int[] res = new int[temperatures.Length];
            Stack<int> stk = new Stack<int>();

            for (int i = 0; i < temperatures.Length; i++)
            {
                while (stk.Count > 0 && temperatures[i] > temperatures[stk.Peek()])
                {
                    int topIdx = stk.Pop();
                    res[topIdx] = i - topIdx;
                }
                stk.Push(i);
            }
            return res;
        }
    }
}

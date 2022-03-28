using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo1996
{
    public class Class1996
    {
        //排序
        public int NumberOfWeakCharacters(int[][] properties)
        {
            Array.Sort(properties, (p1, p2) => {
                return p1[0] == p2[0] ? (p1[1] - p2[1]) : (p2[0] - p1[0]);
            });

            int res = 0;
            int maxDef = 0;
            foreach (int[] p in properties)
            {
                if (p[1] < maxDef)
                {
                    res++;
                }
                else
                {
                    maxDef = p[1];
                }
            }
            return res;
        }

        //单调栈
        public int NumberOfWeakCharacters2(int[][] properties)
        {
            Array.Sort(properties, (p1, p2) => {
                return p1[0] == p2[0] ? (p2[1] - p1[1]) : (p1[0] - p2[0]);
            });
            int res = 0;
            Stack<int> stk = new Stack<int>();
            foreach (int[] p in properties)
            {
                while (stk.Count > 0 && stk.Peek() < p[1])
                {
                    stk.Pop();
                    res++;
                }
                stk.Push(p[1]);
            }
            return res;
        }
    }
}

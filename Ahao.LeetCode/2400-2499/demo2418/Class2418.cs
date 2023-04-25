using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2418
{
    public class Class2418
    {

        public string[] SortPeople(string[] names, int[] heights)
        {
            int n = names.Length;
            int[] indices = new int[n];
            for (int i = 0; i < n; i++)
            {
                indices[i] = i;
            }
            Array.Sort(indices, (a, b) => heights[b] - heights[a]);
            string[] res = new string[n];
            for (int i = 0; i < n; i++)
            {
                res[i] = names[indices[i]];
            }
            return res;
        }


    }
}

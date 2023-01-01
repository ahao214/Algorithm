using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._6200_6299.demo6279
{
    public class Class6279
    {
        public int DistinctPrimeFactors(int[] nums)
        {
            ISet<int> st = new HashSet<int>();
            foreach (var num in nums)
            {
                int tmp = num;
                for (int i = 2; i <= tmp; i++)
                {
                    if (tmp % i == 0)
                    {
                        st.Add(i);
                    }
                    while (tmp % i == 0)
                    {
                        tmp /= i;
                    }
                }
            }
            return st.Count;
        }
    }
}

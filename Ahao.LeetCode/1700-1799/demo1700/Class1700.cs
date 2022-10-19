using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1700
{
    public class Class1700
    {
        public int CountStudents(int[] students, int[] sandwiches)
        {
            int s1 = students.Sum();
            int s0 = students.Length - s1;
            for (int i = 0; i < sandwiches.Length; i++)
            {
                if (sandwiches[i] == 0 && s0 > 0)
                {
                    s0--;
                }
                else if (sandwiches[i] == 1 && s1 > 0)
                {
                    s1--;
                }
                else
                {
                    break;
                }
            }
            return s0 + s1;
        }
    }
}

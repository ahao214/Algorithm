using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2000_2099.demo2037
{
    public class Class2037
    {
        public int MinMovesToSeat(int[] seats, int[] students)
        {
            Array.Sort(seats);
            Array.Sort(students);
            int res = 0;
            for (int i = 0; i < seats.Length; i++)
            {
                res += Math.Abs(seats[i] - students[i]);
            }
            return res;
        }
    }
}

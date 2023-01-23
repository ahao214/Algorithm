using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2303
{
    public class Class2303
    {
        public double CalculateTax(int[][] brackets, int income)
        {
            double total = 0;
            int lowest = 0;
            foreach (int[] bracket in brackets)
            {
                int upperi = bracket[0];
                int percenti = bracket[1];
                int tax = (Math.Min(upperi, income) - lowest) * percenti;
                total += tax;
                if (income <= upperi)
                    break;
                lowest = upperi;
            }

            return (double)total / 100.0;
        }
    }
}

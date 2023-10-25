using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2500_2599.demo2525
{
    public class Class2525
    {
        public string CategorizeBox(int length, int width, int height, int mass)
        {
            long maxd = Math.Max(Math.Max(length, width), height);
            long vol = 1L * length * width * height;
            bool isBulky = maxd >= 10000 || vol >= 1000000000;
            bool isHeavy = mass >= 100;
            if (isBulky && isHeavy)
            {
                return "Both";
            }
            else if (isBulky)
            {
                return "Bulky";
            }
            else if (isHeavy)
            {
                return "Heavy";
            }
            else
            {
                return "Neither";
            }
        }


    }
}

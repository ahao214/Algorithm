using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo860
{
    internal class Class860
    {
        public bool LemonadeChange(int[] bills)
        {
            int five = 0, ten = 0;
            foreach (var item in bills)
            {
                if (item == 5)
                {
                    five++;
                }
                else if (item == 10)
                {
                    if (five == 0)
                    {
                        return false;
                    }
                    five--;
                    ten++;
                }
                else
                {
                    if (five > 0 && ten > 0)
                    {
                        five--;
                        ten--;
                    }
                    else if (five >= 3)
                    {
                        five -= 3;
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            return true;
        }
    }
}
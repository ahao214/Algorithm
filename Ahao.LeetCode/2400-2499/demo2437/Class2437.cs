using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2437
{
    public class Class2437
    {
        public int CountTime(string time)
        {
            //"0?:0?"
            char[] strs = time.ToCharArray();
            int hour = 1;
            int minute = 1;
            if (strs[0] == '?' && strs[1] == '?')
            {
                hour = 24;
            }
            else if (strs[0] == '?' && strs[1] !='?')
            {
                hour = strs[1] < '4' ? 3 : 2;
            }            
            else if (strs[0] != '?' && strs[1] == '?')
            {
                hour = strs[0] < '2' ? 10 : 4;
            }

            if (strs[3] == '?' && strs[4] == '?')
            {
                minute = 60;
            }
            else if (strs[3] == '?' && strs[4] != '?')
            {
                minute = 6;
            }
            else if (strs[3] != '?' && strs[4] == '?')
            {
                minute = 10;
            }


            return hour * minute;


        }
    }
}

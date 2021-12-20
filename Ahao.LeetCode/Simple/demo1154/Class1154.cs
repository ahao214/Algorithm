using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1154
{
    /// <summary>
    /// 1154. 一年中的第几天
    /// </summary>
    public class Class1154
    {
        public int DayOfYear(string date)
        {
            int year = int.Parse(date.Substring(0, 4));
            int month = int.Parse(date.Substring(5, 2));
            int day = int.Parse(date.Substring(8));

            int[] months = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            {
                ++months[1];
            }

            int res = 0;
            for (int i = 0; i < month - 1; i++)
            {
                res += months[i];
            }
            return res + day;
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 551. 学生出勤记录 I
    /// </summary>
    public class CheckRecord
    {
        public bool Method(string s)
        {
            bool result = true;
            int lates = 0, absents = 0;
            for (var i = 0; i < s.Length; i++)
            {
                if (s[i].ToString() == "A")
                {
                    absents++;
                    if (absents >= 2)
                    {
                        result = false;
                    }
                }
                if (s[i].ToString() == "L")
                {
                    lates++;
                    if (lates >= 3)
                    {
                        result = false;
                    }
                }
                else
                {
                    lates = 0;
                }
            }
            return result;
        }
    }
}

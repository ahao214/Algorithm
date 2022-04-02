using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo744
{
    public class Class744
    {
        public char NextGreatestLetter(char[] letters, char target)
        {
            char res = letters[0];
            for (int i = 0; i < letters.Length; i++)
            {
                if (letters[i] > target)
                {
                    res = letters[i];
                    break;
                }
            }

            return res;
        }
    }
}

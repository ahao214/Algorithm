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

        public char NextGreatestLetter2(char[] letters, char target)
        {
            int length = letters.Length;
            if (target >= letters[length - 1])
            {
                return letters[0];
            }
            int low = 0, high = length - 1;
            while (low < high)
            {
                int mid = (high - low) / 2 + low;
                if (letters[mid] > target)
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            return letters[low];
        }

    }
}

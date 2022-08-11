using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1400_1499.demo1417
{
    public class Class1417
    {
        public string Reformat(string s)
        {
            int sumDigit = 0;
            foreach (char c in s)
            {
                if (char.IsDigit(c))
                {
                    sumDigit++;
                }
            }
            int sumAlpha = s.Length - sumDigit;
            if (Math.Abs(sumDigit - sumAlpha) > 1)
            {
                return "";
            }
            bool flag = sumDigit > sumAlpha;
            char[] arr = s.ToCharArray();
            for (int i = 0, j = 1; i < s.Length; i += 2)
            {
                if (char.IsDigit(arr[i]) != flag)
                {
                    while (char.IsDigit(arr[j]) != flag)
                    {
                        j += 2;
                    }
                    Swap(arr, i, j);
                }
            }
            return new String(arr);
        }

        public void Swap(char[] arr, int i, int j)
        {
            char c = arr[i];
            arr[i] = arr[j];
            arr[j] = c;
        }

    }
}

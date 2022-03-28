using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo838
{
    public class Class838
    {
        public string PushDominoes(string dominoes)
        {
            char[] c = dominoes.ToCharArray();
            int n = c.Length, i = 0;
            char left = 'L';
            while (i < n)
            {
                int j = i;
                while (j < n && c[j] == '.')
                {
                    j++;
                }
                char right;
                if (j < n)
                {
                    right = c[j];
                }
                else
                {
                    right = 'R';
                }
                if (left == right)
                {
                    while (i < j)
                    {
                        c[i++] = right;
                    }
                }
                else if (left == 'R' && right == 'L')
                {
                    int tmp = j - 1;
                    while (i < tmp)
                    {
                        c[i++] = 'R';
                        c[tmp--] = 'L';
                    }
                }

                left = right;
                i = j + 1;
            }
            return new string(c);
        }
    }
}

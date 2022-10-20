using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo779
{
    public class Class779
    {
        public int KthGrammar(int n, int k)
        {
            if (n == 1)
            {
                return 0;
            }
            return (k & 1) ^ 1 ^ KthGrammar(n - 1, (k + 1) / 2);
        }



        public int KthGrammar2(int n, int k)
        {
            if (k == 1)
            {
                return 0;
            }
            if (k > (1 << (n - 2)))
            {
                return 1 ^ KthGrammar2(n - 1, k - (1 << (n - 2)));
            }
            return KthGrammar2(n - 1, k);
        }


        public int KthGrammar3(int n, int k)
        {
            k--;
            int res = 0;
            while (k > 0)
            {
                k &= k - 1;
                res ^= 1;
            }
            return res;
        }


    }
}

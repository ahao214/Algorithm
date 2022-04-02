using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Lintcode._0100_0199
{
    public class Class147
    {
        #region 147 · 水仙花数

        /*
         水仙花数的定义是，这个数等于他每一位数上的幂次之和 见维基百科的定义

        比如一个3位的十进制整数153就是一个水仙花数。因为 153 = 1^3 + 5^3 + 3^3。

        而一个4位的十进制数1634也是一个水仙花数，因为 1634 = 1^4 + 6^4 + 3^4 + 4^4。

        给出n，找到所有的n位十进制水仙花数。
         */

        #endregion

        public List<int> getNarcissisticNumbers(int n)
        {
            List<int> lst = new List<int>();
            int first = 1, second = 1;
            for (int i = 1; i < n; i++)
            {
                first *= 10;
                second *= 10;
            }
            second *= 10;
            if (first == 1)
            {
                first -= 1;
            }
            for (int i = first; i < second; i++)
            {
                int cnt = i;
                int val = 0;
                int c = 0;
                while (cnt > 0)
                {
                    int a = 1;
                    val = cnt % 10;
                    for (int j = 1; j <= n; j++)
                    {
                        a *= val;
                    }
                    c += a;
                    cnt /= 10;
                }
                if (c == i)
                {
                    lst.Add(c);
                }
            }
            return lst;
        }
    }
}

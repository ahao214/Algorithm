using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Lintcode._0001_0099
{    
    public class Class46
    {
        #region 46 · 主元素

        /*
        给定一个整型数组，找出主元素，它在数组中的出现次数大于数组元素个数的二分之一。
         */

        #endregion

        public int MajorityNumber(List<int> nums)
        {
            int res = 0, cnt = 0;
            foreach (var item in nums)
            {
                if (item == res)
                    cnt++;
                else
                    cnt--;

                if (cnt < 1)
                {
                    cnt = 1;
                    res = item;
                }
            }
            return res;
        }
    }
}

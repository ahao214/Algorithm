using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 374. 猜数字大小
    /// </summary>
    public class GuessNumber
    {
        public int Method(int n)
        {
            return BinSearch(1, n, n);
        }

        public int BinSearch(int left, int right, int n)
        {
            int mid = left + (right - left) / 2;
            //if (guess(mid) < 0)
            //{
            //    return BinSearch(left, mid, n);
            //}
            //else if (guess(mid) > 0)
            //{
            //    return BinSearch(mid + 1, right, n);
            //}
            //else
            //{
            //    return mid;
            //}
            return mid;
        }
    }



}

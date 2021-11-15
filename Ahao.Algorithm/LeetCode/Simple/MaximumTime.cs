using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 1736. 替换隐藏数字得到的最晚时间
    /// </summary>
    public class MaximumTime
    {
        public string Method(string time)
        {
            char[] arr = time.ToCharArray();
            if (arr[0] == '?')
            {
                if (arr[1] >= '4' && arr[1] <= '9')
                {
                    arr[0] = '1';
                }
                else
                {
                    arr[0] = '2';
                }
            }
            if (arr[1] == '?')
            {
                if (arr[0] == '2')
                {
                    arr[1] = '3';
                }
                else
                {
                    arr[1] = '9';
                }
            }
            if (arr[3] == '?')
            {
                arr[3] = '5';
            }
            if (arr[4] == '?')
            {
                arr[4] = '9';
            }
            return new string(arr);
        }

    }
}

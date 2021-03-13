using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 找出数组中出现次数超过了一半的那个数字
    /// </summary>
    public class TestMoreHalf
    {
        public static int MoreHalf(int[] arr)
        {
            //返回的结果数字
            int result = 0;
            //计数器
            int count = 1;
            //数组长度
            int length = arr.Length;
            if (length == 0)
            {
                //如果数组长度为0，返回-1，表示找不到
                return -1;
            }
            result = arr[0];
            for (int i = 1; i < length; i++)
            {
                if (count == 0)
                {
                    result = arr[i];
                    count = 1;
                    continue;
                }
                if (result == arr[i])
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
            return result;
        }

    }
}

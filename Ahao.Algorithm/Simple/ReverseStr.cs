using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 541. 反转字符串 II
    /// </summary>
    public class ReverseStr
    {
        public string Method(string s, int k)
        {
            int len = s.Length;
            char[] arr = s.ToCharArray();
            for (int i = 0; i < len; i += 2 * k)
            {
                Reverse(arr, i, Math.Min(i + k, len) - 1);
            }
            return new string(arr);
        }

        public void Reverse(char[] arr, int left, int right)
        {
            while (left < right)
            {
                char tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                left++;
                right--;
            }
        }
    }
}

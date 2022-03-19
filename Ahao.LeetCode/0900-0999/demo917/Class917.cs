using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo917
{
    /*
     917. 仅仅反转字母
给你一个字符串 s ，根据下述规则反转字符串：

所有非英文字母保留在原有位置。
所有英文字母（小写或大写）位置反转。
返回反转后的 s 。
     */
    public class Class917
    {
        public string ReverseOnlyLetters(string s)
        {
            char[] c = s.ToCharArray();
            int n = s.Length;
            int left = 0;
            int right = n - 1;
            while (true)
            {
                while (left < right && !char.IsLetter(s[left]))
                {
                    left++;
                }
                while (right > left && !char.IsLetter(s[right]))
                {
                    right--;
                }
                if (left >= right)
                    break;
                Swap(c, left++, right--);
            }

            return new string(c);
        }

        private void Swap(char[] arr, int i, int j)
        {
            char tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
}

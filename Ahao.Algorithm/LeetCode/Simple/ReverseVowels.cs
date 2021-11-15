using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 345. 反转字符串中的元音字母
    /// </summary>
    public class ReverseVowels
    {
        public string Method(string s)
        {
            HashSet<int> hset = new HashSet<int>();
            hset.Add('a');
            hset.Add('A');
            hset.Add('e');
            hset.Add('E');
            hset.Add('i');
            hset.Add('I');
            hset.Add('o');
            hset.Add('O');
            hset.Add('u');
            hset.Add('U');

            char[] st = s.ToCharArray();
            char exc = '0';
            int left = 0, right = s.Length - 1;

            while (left < right)
            {
                if (hset.Contains(s[left]))
                {
                    if (hset.Contains(s[right]))
                    {
                        exc = st[left];
                        st[left] = st[right];
                        st[right] = exc;
                        left++;
                        right--;
                    }
                    else
                    {
                        right--;
                    }
                }
                else
                {
                    left++;
                }
            }
            return new string(st);
        }
    }
}

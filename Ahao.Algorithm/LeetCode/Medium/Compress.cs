﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 443. 压缩字符串
    /// </summary>
    public class Compress
    {
        public int Method(char[] chars)
        {
            int n = chars.Length;
            int write = 0, left = 0;
            for (int read = 0; read < n; read++)
            {
                if (read == n - 1 || chars[read] != chars[read + 1])
                {
                    chars[write++] = chars[read];
                    int num = read - left + 1;
                    if (num > 1)
                    {
                        int anchor = write;
                        while (num > 0)
                        {
                            chars[write++] = (char)(num % 10 + '0');
                            num /= 10;
                        }
                        Reverse(chars, anchor, write - 1);
                    }
                    left = read + 1;
                }
            }
            return write;
        }


        public void Reverse(char[] chars, int left, int right)
        {
            while (left < right)
            {
                char temp = chars[left];
                chars[left] = chars[right];
                chars[right] = temp;
                left++;
                right--;
            }
        }
    }
}

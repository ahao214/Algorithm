using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0100_0199.demo151
{
    public class Class151
    {
        public string ReverseWords(string s)
        {
            //对整体逆序，在对每一个单词逆序
            if (s == null)
                return null;
            char[] chars = s.ToCharArray();
            //消除多余的空格
            int cur = 0, len = 0;
            bool space = true;
            for (int i = 0; i < chars.Length; i++)
            {
                if (chars[i] != ' ')
                {
                    chars[cur++] = chars[i];
                    space = false;
                }
                else if (space == false)
                {
                    //chars[i]是空格
                    chars[cur++] = ' ';
                    space = true;
                }
            }
            len = space ? (cur - 1) : cur;
            if (len <= 0)
                return "";
            //对s整体反转
            reverse(chars, 0, len);
            //前一个空格字符的位置
            int spaceIdx = -1;
            for (int i = 0; i <= len; i++)
            {
                if (chars[i] != ' ') continue;
                reverse(chars, spaceIdx + 1, i);
                spaceIdx = i;
            }
            reverse(chars, spaceIdx + 1, len); //反转最后一个单词
            return new string(chars, 0, len);
        }

        private void reverse(char[] chars, int left, int right)
        {
            right--;
            char tmp = chars[left];
            chars[left] = chars[right];
            chars[right] = tmp;
            left++;
            right--;
        }

    }
}

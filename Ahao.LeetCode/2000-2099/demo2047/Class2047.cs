using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo2047
{
    public class Class2047
    {
        public int CountValidWords(string sentence)
        {
            int n = sentence.Length;
            int l = 0, r = 0;
            int ret = 0;
            while (true)
            {
                while (l < n && sentence[l] == ' ')
                {
                    l++;
                }
                if (l >= n)
                {
                    break;
                }
                r = l + 1;
                while (r < n && sentence[r] != ' ')
                {
                    r++;
                }
                if (isValid(sentence.Substring(l, r - l)))
                { // 判断根据空格分解出来的 token 是否有效
                    ret++;
                }
                l = r + 1;
            }
            return ret;
        }

        public bool isValid(string word)
        {
            int n = word.Length;
            bool hasHyphens = false;
            for (int i = 0; i < n; i++)
            {
                if (char.IsDigit(word[i]))
                {
                    return false;
                }
                else if (word[i] == '-')
                {
                    if (hasHyphens == true || i == 0 || i == n - 1 || !char.IsLetter(word[i - 1]) || !char.IsLetter(word[i + 1]))
                    {
                        return false;
                    }
                    hasHyphens = true;
                }
                else if (word[i] == '!' || word[i] == '.' || word[i] == ',')
                {
                    if (i != n - 1)
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    }
}

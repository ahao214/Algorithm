using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 520. 检测大写字母
    /// 我们定义，在以下情况时，单词的大写用法是正确的：
    ///全部字母都是大写，比如 "USA" 。
    ///单词中所有字母都不是大写，比如 "leetcode" 。
    ///如果单词不只含有一个字母，只有首字母大写， 比如 "Google" 。
    ///给你一个字符串 word 。如果大写用法正确，返回 true ；否则，返回 false 。
    /// </summary>
    public class Class520
    {
        public bool DetectCapitalUse(string word)
        {
            //若第一个字母是小写，则需要额外判断第2个字母是否为小写
            if (word.Length >= 2 & char.IsLower(word[0]) && char.IsLower(word[1]))
            {
                return false;
            }

            //无论第一个字母是否大写，其他字母必须与第二个字母的大小写相同
            for (int i = 2; i < word.Length; i++)
            {
                if (char.IsLower(word[i]) ^ char.IsLower(word[1]))
                {
                    return false;
                }
            }
            return true;
        }
    }
}

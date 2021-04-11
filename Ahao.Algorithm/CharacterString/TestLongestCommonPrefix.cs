using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 找出字符串中最长公共前缀
    /// </summary>
    public class TestLongestCommonPrefix
    {
        public string LongestCommonPrefix(List<string> strs)
        {
            if (strs == null || strs.Count == 0)
            {
                return "";
            }
            //将集合中的index=0的字符赋值给res
            string res = strs[0];

            for (int i = 1; i < strs.Count; i++)
            {
                string cur = strs[i];
                string temp = res;
                res = "";
                //比较两个字符串中每个位置的字符，直到较短的字符结束
                for (int j = 0; j < Math.Min(temp.Length, cur.Length); j++)
                {
                    if (temp[j] == cur[j])
                        res += cur[j];
                    else
                        break;
                }
            }
            return res;
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 139.单词拆分
    /// </summary>
    public class WordBreak
    {
        public bool Method(string s, IList<string> wordDict)
        {
            //结果，表示前n个字符能否被字典分割
            var result = new bool[s.Length + 1];
            result[0] = true;
            for (int i = 0; i < s.Length; i++)
            {
                for (int j = 0; j <= i; j++)
                {
                    //前j个字符能被字典拆分，且从j到i的子字符串在字典中
                    if (result[j] && wordDict.Contains(s.Substring(j, i - j + 1)))
                    {
                        //则保存结果，前i个字符能被字典分割
                        result[i + 1] = true;
                        break;
                    }
                }
            }
            return result[s.Length];

        }
    }
}

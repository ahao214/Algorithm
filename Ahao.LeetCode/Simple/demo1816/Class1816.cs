using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1816
{
    /// <summary>
    /// 1816. 截断句子
    /// </summary>
    public class Class1816
    {
        public string TruncateSentence(string s, int k)
        {
            var str = s.Split(' ').Skip(0).Take(k).ToArray();
            return string.Join(' ', str);
        }



    }
}

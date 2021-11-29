using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo22
{
    /// <summary>
    /// 22. 括号生成
    /// </summary>
    public class Class22
    {
        public IList<string> GenerateParenthesis(int n)
        {
            var buff = new char[n * 2];
            var results = new List<string>();
            Gen(buff, 0, 0, n, 0, results);
            return results;
        }

        private void Gen(char[] buff, int i, int usedLeft, int remainsLeft, int usedRight, List<string> results)
        {
            if (i == buff.Length)
            {
                results.Add(new string(buff));
                return;
            }
            if (remainsLeft > 0)
            {
                buff[i] = '(';
                Gen(buff, i + 1, usedLeft + 1, remainsLeft - 1, usedRight, results);
            }
            if (usedLeft > usedRight)
            {
                buff[i] = ')';
                Gen(buff, i + 1, usedLeft, remainsLeft, usedRight + 1, results);
            }
        }

    }
}

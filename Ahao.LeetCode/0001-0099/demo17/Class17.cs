using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo17
{
    /// <summary>
    /// 17. 电话号码的字母组合
    /// </summary>
    public class Class17
    {
        private static readonly string[] T =
        {
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz",
         };

        public IList<string> LetterCombinations(string digits)
        {
            if (string.IsNullOrEmpty(digits))
            {
                return new List<string>(0);
            }

            var map = digits.Select(t => T[t - '0']).ToArray();
            var buff = map.Select(t => t[0]).ToArray();
            var s = map[0];
            var results = new List<string>(map.Aggregate(1, (cnt, t) => cnt * t.Length));
            while (true)
            {
                for (int i = 0; i < s.Length; i++)
                {
                    buff[0] = s[i];
                    results.Add(new string(buff));
                }
                var j = 1;
                while (j < buff.Length)
                {
                    buff[j]++;
                    if (buff[j] <= map[j].Last())
                    {
                        break;
                    }
                    else
                    {
                        buff[j] = map[j][0];
                        j++;
                    }
                }
                if (j == buff.Length)
                    break;
            }
            return results;
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1400_1499.demo1408
{
    public class Class1408
    {
        public IList<string> StringMatching(string[] words)
        {
            IList<string> ret = new List<string>();
            for (int i = 0; i < words.Length; i++)
            {
                for (int j = 0; j < words.Length; j++)
                {
                    if (i != j && words[j].Contains(words[i]))
                    {
                        ret.Add(words[i]);
                        break;
                    }
                }
            }
            return ret;
        }

    }
}

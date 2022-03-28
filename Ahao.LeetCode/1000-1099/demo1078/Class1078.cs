using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1078
{
    public class Class1078
    {
        public string[] FindOcurrences(string text, string first, string second)
        {
            string[] words = text.Split(" ");
            IList<string> lst = new List<string>();
            for (int i = 2; i < words.Length; i++)
            {
                if (words[i - 2] == first && words[i - 1] == second)
                {
                    lst.Add(words[i]);
                }
            }
            int count = lst.Count;
            string[] res = new string[count];
            for (int i = 0; i < count; i++)
            {
                res[i] = lst[i];
            }
            return res;
        }
    }
}

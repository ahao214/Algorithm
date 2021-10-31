using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple.LC500
{
    /// <summary>
    /// 500. 键盘行
    /// </summary>
    public class FindWords
    {
        public string[] Method(string[] words)
        {
            string[] rows = new string[] { "qwertyuiop", "asdfghjkl", "zxcvbnm" };
            List<string> result = new List<string>();
            for (int i = 0; i < words.Length; i++)
            {
                bool flag = false;
                int n = 0;
                char a = words[i].ToLower()[0];
                if (rows[0].Contains(a))
                {
                    n = 0;
                }
                else if (rows[1].Contains(a))
                {
                    n = 1;
                }
                else if (rows[2].Contains(a))
                {
                    n = 2;
                }
                for (int j = 1; j < words[i].Length; j++)
                {
                    if (!rows[n].Contains(words[i].ToLower()[j]))
                    {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    result.Add(words[i]);
                }
            }
            return result.ToArray();
        }
    }
}

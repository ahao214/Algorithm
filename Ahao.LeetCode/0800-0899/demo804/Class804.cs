using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo804
{
    public class Class804
    {

        public static string[] MORSE = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                                      "....", "..", ".---", "-.-", ".-..", "--", "-.",
                                      "---", ".--.", "--.-", ".-.", "...", "-", "..-",
                                      "...-", ".--", "-..-", "-.--", "--.."};

        public int UniqueMorseRepresentations(string[] words)
        {
            ISet<string> seen = new HashSet<string>();
            foreach (string word in words)
            {
                StringBuilder code = new StringBuilder();
                foreach (char c in word)
                {
                    code.Append(MORSE[c - 'a']);
                }
                seen.Add(code.ToString());
            }
            return seen.Count;
        }

    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2325
{
    public class Class2325
    {

        public string DecodeMessage(string key, string message)
        {
            char cur = 'a';
            IDictionary<char, char> rules = new Dictionary<char, char>();

            foreach (char c in key)
            {
                if (c != ' ' && !rules.ContainsKey(c))
                {
                    rules.Add(c, cur);
                    ++cur;
                }
            }

            StringBuilder sb = new StringBuilder();
            foreach (char c in message)
            {
                if (c != ' ')
                {
                    sb.Append(rules[c]);
                }
                else
                {
                    sb.Append(c);
                }
            }

            return sb.ToString();
        }


        public string DecodeMessage2(string key, string message)
        {
            string res = "";
            Dictionary<char, char> dic = new Dictionary<char, char>();

            int cnt = 0;
            for (int i = 0; i < key.Length && cnt < 26; i++)
            {
                if (!dic.ContainsKey(key[i]))
                {
                    if (key[i] == ' ') continue;
                    dic.Add(key[i], (char)('a' + cnt++));//字符映射
                }
            }

            for (int i = 0; i < message.Length; i++)
            {
                if (message[i] == ' ') res += " ";
                else res += dic[message[i]];//叠加字符       
            }
            return res;
        }


    }
}

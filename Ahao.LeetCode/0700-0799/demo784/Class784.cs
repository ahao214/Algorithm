using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo784
{
    public class Class784
    {
        //方法一：广度优先搜索
        public IList<string> LetterCasePermutation(string s)
        {
            IList<string> ans = new List<string>();
            Queue<StringBuilder> queue = new Queue<StringBuilder>();
            queue.Enqueue(new StringBuilder());
            while (queue.Count > 0)
            {
                StringBuilder curr = queue.Peek();
                if (curr.Length == s.Length)
                {
                    ans.Add(curr.ToString());
                    queue.Dequeue();
                }
                else
                {
                    int pos = curr.Length;
                    if (char.IsLetter(s[pos]))
                    {
                        StringBuilder next = new StringBuilder(curr.ToString());
                        next.Append((char)(s[pos] ^ 32));
                        queue.Enqueue(next);
                    }
                    curr.Append(s[pos]);
                }
            }
            return ans;
        }
    
        
    }
}

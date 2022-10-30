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

        //方法二：回溯
        public IList<string> LetterCasePermutation2(string s)
        {
            IList<string> ans = new List<string>();
            DFS(s.ToCharArray(), 0, ans);
            return ans;
        }

        public void DFS(char[] arr, int pos, IList<string> res)
        {
            while (pos < arr.Length && char.IsDigit(arr[pos]))
            {
                pos++;
            }
            if (pos == arr.Length)
            {
                res.Add(new string(arr));
                return;
            }
            arr[pos] = (char)(arr[pos] ^ 32);
            DFS(arr, pos + 1, res);
            arr[pos] = (char)(arr[pos] ^ 32);
            DFS(arr, pos + 1, res);
        }

        //方法三：二进制位图
        public IList<string> LetterCasePermutation3(string s)
        {
            int n = s.Length;
            int m = 0;
            for (int i = 0; i < n; i++)
            {
                if (char.IsLetter(s[i]))
                {
                    m++;
                }
            }
            IList<string> ans = new List<string>();
            for (int mask = 0; mask < (1 << m); mask++)
            {
                StringBuilder sb = new StringBuilder();
                for (int j = 0, k = 0; j < n; j++)
                {
                    if (char.IsLetter(s[j]) && (mask & (1 << k++)) != 0)
                    {
                        sb.Append(char.ToUpper(s[j]));
                    }
                    else
                    {
                        sb.Append(char.ToLower(s[j]));
                    }
                }
                ans.Add(sb.ToString());
            }
            return ans;
        }


    }
}

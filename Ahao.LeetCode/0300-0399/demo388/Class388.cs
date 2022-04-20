using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0300_0399.demo388
{
    public class Class388
    {
        public int LengthLongestPath(string input)
        {
            int n = input.Length;
            int pos = 0;
            int ans = 0;
            Stack<int> stack = new Stack<int>();

            while (pos < n)
            {
                /* 检测当前文件的深度 */
                int depth = 1;
                while (pos < n && input[pos] == '\t')
                {
                    pos++;
                    depth++;
                }
                /* 统计当前文件名的长度 */
                bool isFile = false;
                int len = 0;
                while (pos < n && input[pos] != '\n')
                {
                    if (input[pos] == '.')
                    {
                        isFile = true;
                    }
                    len++;
                    pos++;
                }
                /* 跳过当前的换行符 */
                pos++;

                while (stack.Count >= depth)
                {
                    stack.Pop();
                }
                if (stack.Count > 0)
                {
                    len += stack.Peek() + 1;
                }
                if (isFile)
                {
                    ans = Math.Max(ans, len);
                }
                else
                {
                    stack.Push(len);
                }
            }
            return ans;
        }
    }
}

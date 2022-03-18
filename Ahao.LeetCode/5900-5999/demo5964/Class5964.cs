using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo5964
{
    /// <summary>
    /// 5964. 执行所有后缀指令
    /// </summary>
    public class Class5964
    {
        public int[] ExecuteInstructions(int n, int[] startPos, string s)
        {
            List<int> ans = new List<int>();
            int size = s.Length;
            for (int i = 0; i < size; i++)
            {
                int x = startPos[0];
                int y = startPos[1];
                int w = 0;
                for (int j = i; j < size; j++)
                {
                    if (s[j] == 'L')
                    {
                        --y;
                    }
                    else
                    {
                        if (s[j] == 'R')
                        {
                            ++y;
                        }
                        else
                        {
                            if (s[j] == 'U')
                            {
                                --x;
                            }
                            else
                            {
                                ++x;
                            }
                        }
                    }
                    if (x < 0 || x >= n || y < 0 || y >= n)
                        break;
                    ++w;
                }
                ans.Add(w);
            }
            int[] res = new int[ans.Count];
            for (int i = 0; i < ans.Count; i++)
            {
                res[i] = ans[i];
            }
            return res;
        }
    }
}

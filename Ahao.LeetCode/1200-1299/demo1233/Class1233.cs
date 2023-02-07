using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1233
{
    public class Class1233
    {
        public IList<string> RemoveSubfolders(string[] folder)
        {
            Array.Sort(folder);
            IList<string> ans = new List<string>();
            ans.Add(folder[0]);
            for (int i = 1; i < folder.Length; ++i)
            {
                int pre = ans[ans.Count - 1].Length;
                if (!(pre < folder[i].Length && ans[ans.Count - 1].Equals(folder[i].Substring(0, pre)) && folder[i][pre] == '/'))
                {
                    ans.Add(folder[i]);
                }
            }
            return ans;
        }
    }
}

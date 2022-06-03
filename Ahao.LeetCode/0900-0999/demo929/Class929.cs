using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo929
{
    public class Class929
    {
        public int NumUniqueEmails(string[] emails)
        {
            ISet<string> emailSet = new HashSet<string>();
            foreach (string email in emails)
            {
                int i = email.IndexOf('@');
                string local = email.Substring(0, i).Split("+")[0]; // 去掉本地名第一个加号之后的部分
                local = local.Replace(".", ""); // 去掉本地名中所有的句点
                emailSet.Add(local + email.Substring(i));
            }
            return emailSet.Count;
        }

    }
}

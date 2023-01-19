using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2200_2299.deom2299
{
    public class Class2299
    {
        public bool StrongPasswordCheckerII(string password)
        {
            if (password.Length < 8)
            {
                return false;
            }

            ISet<char> specials = new HashSet<char>() { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+' };
            int n = password.Length;
            bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
            for (int i = 0; i < n; ++i)
            {
                if (i != n - 1 && password[i] == password[i + 1])
                {
                    return false;
                }

                char ch = password[i];
                if (char.IsLower(ch))
                {
                    hasLower = true;
                }
                else if (char.IsUpper(ch))
                {
                    hasUpper = true;
                }
                else if (char.IsDigit(ch))
                {
                    hasDigit = true;
                }
                else if (specials.Contains(ch))
                {
                    hasSpecial = true;
                }
            }

            return hasLower && hasUpper && hasDigit && hasSpecial;
        }

    }
}

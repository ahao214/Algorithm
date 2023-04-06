using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1017
{
    public class Class1017
    {

        public string BaseNeg2(int n)
        {
            if (n == 0)
            {
                return "0";
            }
            int[] bits = new int[32];
            for (int i = 0; i < 32 && n != 0; i++)
            {
                if ((n & 1) != 0)
                {
                    bits[i]++;
                    if ((i & 1) != 0)
                    {
                        bits[i + 1]++;
                    }
                }
                n >>= 1;
            }
            int carry = 0;
            for (int i = 0; i < 32; i++)
            {
                int val = carry + bits[i];
                bits[i] = val & 1;
                carry = (val - bits[i]) / (-2);
            }
            int pos = 31;
            StringBuilder res = new StringBuilder();
            while (pos >= 0 && bits[pos] == 0)
            {
                pos--;
            }
            while (pos >= 0)
            {
                res.Append(bits[pos]);
                pos--;
            }
            return res.ToString();
        }



        public string BaseNeg22(int n)
        {
            if (n == 0 || n == 1)
            {
                return n.ToString();
            }
            StringBuilder sb = new StringBuilder();
            while (n != 0)
            {
                int remainder = n & 1;
                sb.Append(remainder);
                n -= remainder;
                n /= -2;
            }
            StringBuilder res = new StringBuilder();
            for (int i = sb.Length - 1; i >= 0; i--)
            {
                res.Append(sb[i]);
            }
            return res.ToString();
        }



        public string BaseNeg23(int n)
        {
            int val = 0x55555555 ^ (0x55555555 - n);
            if (val == 0)
            {
                return "0";
            }
            StringBuilder sb = new StringBuilder();
            while (val != 0)
            {
                sb.Append(val & 1);
                val >>= 1;
            }
            StringBuilder res = new StringBuilder();
            for (int i = sb.Length - 1; i >= 0; i--)
            {
                res.Append(sb[i]);
            }
            return res.ToString();
        }


    }
}

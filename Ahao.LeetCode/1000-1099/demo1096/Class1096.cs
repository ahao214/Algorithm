using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1096
{
    public class Class1096
    {
        public IList<string> BraceExpansionII(string expression)
        {
            string temp = "";
            int count = 0;
            bool findleft = false;
            IList<string> result = new List<string>();
            result.Add("");
            for (int i = 0; i < expression.Length; i++)
            {
                temp = temp + expression[i];
                if (expression[i] == '{')
                {
                    count++;
                    if (!findleft)
                    {
                        temp = temp.Remove(temp.Length - 1, 1);
                        findleft = true;
                    }
                }
                if (expression[i] == '}')
                {
                    count--;
                    if (count == 0)
                        temp = temp.Remove(temp.Length - 1, 1);
                }
                if (count == 0)
                {
                    if (findleft)
                    {
                        if (temp != "")
                            result = mutiplyTwoList(result, UnionAll(temp));
                        findleft = false;
                        temp = "";
                    }
                    else if (i == expression.Length - 1 || expression[i + 1] == '{')
                    {
                        result = mutiplyTwoList(result, UnionAll(temp));
                        temp = "";
                    }
                }
            }
            return result;
        }

        public IList<string> mutiplyTwoList(IList<string> one, IList<string> two)
        {
            HashSet<string> result = new HashSet<string>();
            foreach (string i in one)
                foreach (string j in two)
                    if (!result.Contains(i + j))
                        result.Add(i + j);
            var x = result.ToArray();
            Array.Sort(x);
            return x;
        }


        public IList<string> UnionAll(string sonstr)
        {
            string temp = "";
            int count = 0;
            bool findleft = false;
            IList<string> w;
            HashSet<string> result = new HashSet<string>();
            for (int i = 0; i < sonstr.Length; i++)
            {
                temp = temp + sonstr[i];
                if (sonstr[i] == '{')
                {
                    count++;
                    if (!findleft)
                        findleft = true;
                }
                if (sonstr[i] == '}')
                    count--;

                if (sonstr[i] == ',' && count == 0)
                {
                    temp = temp.Remove(temp.Length - 1, 1);
                    if (findleft)
                    {
                        w = BraceExpansionII(temp);
                        foreach (string x in w)
                            if (!result.Contains(x))
                                result.Add(x);
                        findleft = false;
                    }
                    else
                        if (!result.Contains(temp))
                        result.Add(temp);
                    temp = "";
                }
                else if (i == sonstr.Length - 1)
                {
                    if (findleft)
                    {
                        w = BraceExpansionII(temp);
                        foreach (string x in w)
                            if (!result.Contains(x))
                                result.Add(x);
                        findleft = false;
                    }
                    else
                        if (!result.Contains(temp))
                        result.Add(temp);
                }
            }
            return result.ToArray();
        }



    }
}

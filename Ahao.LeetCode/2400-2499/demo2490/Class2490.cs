using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2490
{
    public class Class2490
    {

        public bool IsCircularSentence(string sentence)
        {
            string[] seq = sentence.Split(" ");
            if (seq.Length == 1)
            {
                return seq[0].First() == seq[0].Last();
            }
            else
            {
                if (seq[0].First() != seq[seq.Length - 1].Last())
                {
                    return false;
                }
                else
                {
                    for (int i = 0; i < seq.Length - 1; i++)
                    {
                        if (seq[i].Last() != seq[i + 1].First())
                        {
                            return false;
                        }
                    }
                }
            }

            return true;
        }



        public bool IsCircularSentence2(string sentence)
        {
            if (sentence[sentence.Length - 1] != sentence[0])
            {
                return false;
            }
            for (int i = 0; i < sentence.Length; i++)
            {
                if (sentence[i] == ' ' && sentence[i + 1] != sentence[i - 1])
                {
                    return false;
                }
            }
            return true;
        }


    }
}

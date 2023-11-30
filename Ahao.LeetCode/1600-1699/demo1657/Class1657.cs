using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1657
{
    public class Class1657
    {
        public bool CloseStrings(string word1, string word2)
        {
            if (word1.Length != word2.Length)
                return false;
            int[] count1 = new int[26], count2 = new int[26];
            foreach (char c in word1)
            {
                count1[c - 'a']++;
            }
            foreach (char c in word2)
            {
                count2[c - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                if (count1[i] > 0 && count2[i] == 0 || count1[i] == 0 && count2[i] > 0)
                {
                    return false;
                }
            }
            Array.Sort(count1);
            Array.Sort(count2);
            return Enumerable.SequenceEqual(count1, count2);
        }



        public bool CloseStrings2(string word1, string word2)
        {
            if (word1.Length != word2.Length)
                return false;
            Dictionary<char, int> dic1 = new Dictionary<char, int>();
            Dictionary<char, int> dic2 = new Dictionary<char, int>();
            foreach (var i in word1)
            {
                if (dic1.ContainsKey(i))
                {
                    dic1[i]++;
                }
                else
                {
                    dic1.Add(i, 1);
                }
            }
            foreach (var i in word2)
            {
                if (dic2.ContainsKey(i))
                {
                    dic2[i]++;
                }
                else
                {
                    dic2.Add(i, 1);
                }
            }
            List<int> list1 = new List<int>();
            List<int> list2 = new List<int>();

            foreach (var kvp in dic1)
            {
                if (!dic2.ContainsKey(kvp.Key))
                    return false;
            }
            foreach (var kvp in dic1)
            {
                list1.Add(kvp.Value);
            }

            foreach (var kvp in dic2)
            {
                list2.Add(kvp.Value);
            }

            list1.Sort();
            list2.Sort();

            for (int i = 0; i < list1.Count; i++)
            {
                if (list1[i] != list2[i])
                {
                    return false;
                }
            }
            return true;
        }
    }
}

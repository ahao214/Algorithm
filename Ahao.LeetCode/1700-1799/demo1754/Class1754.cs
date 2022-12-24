﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1754
{
    public class Class1754
    {
        public string LargestMerge(string word1, string word2)
        {
            StringBuilder merge = new StringBuilder();
            int i = 0, j = 0;
            while (i < word1.Length || j < word2.Length)
            {
                if (i < word1.Length && word1.Substring(i).CompareTo(word2.Substring(j)) > 0)
                {
                    merge.Append(word1[i]);
                    i++;
                }
                else
                {
                    merge.Append(word2[j]);
                    j++;
                }
            }
            return merge.ToString();
        }



        public string LargestMerge2(string word1, string word2)
        {
            int m = word1.Length, n = word2.Length;
            String str = word1 + "@" + word2 + "*";
            int[] suffixArray = BuildSuffixArray(str);
            int[] rank = new int[m + n + 2];
            for (int idx = 0; idx < m + n + 2; idx++)
            {
                rank[suffixArray[idx]] = idx;
            }

            StringBuilder merge = new StringBuilder();
            int i = 0, j = 0;
            while (i < m || j < n)
            {
                if (i < m && rank[i] > rank[m + 1 + j])
                {
                    merge.Append(word1[i]);
                    i++;
                }
                else
                {
                    merge.Append(word2[j]);
                    j++;
                }
            }
            return merge.ToString();
        }

        public int[] BuildSuffixArray(String text)
        {
            int[] order = CortCharacters(text);
            int[] classfiy = ComputeCharClasses(text, order);
            int len = 1;
            int n = text.Length;
            for (int i = 1; i < n; i <<= 1)
            {
                order = SortDoubled(text, i, order, classfiy);
                classfiy = UpdateClasses(order, classfiy, i);
            }
            return order;
        }

        public int[] CortCharacters(String text)
        {
            int n = text.Length;
            int[] count = new int[128];
            int[] order = new int[n];
            for (int i = 0; i < n; i++)
            {
                char c = text[i];
                count[c]++;
            }
            for (int i = 1; i < 128; i++)
            {
                count[i] += count[i - 1];
            }
            for (int i = n - 1; i >= 0; i--)
            {
                count[text[i]]--;
                order[count[text[i]]] = i;
            }
            return order;
        }

        public int[] ComputeCharClasses(String text, int[] order)
        {
            int n = text.Length;
            int[] res = new int[n];
            res[order[0]] = 0;
            for (int i = 1; i < n; i++)
            {
                if (text[order[i]] != text[order[i - 1]])
                {
                    res[order[i]] = res[order[i - 1]] + 1;
                }
                else
                {
                    res[order[i]] = res[order[i - 1]];
                }
            }
            return res;
        }

        public int[] SortDoubled(String text, int len, int[] order, int[] classfiy)
        {
            int n = text.Length;
            int[] count = new int[n];
            int[] newOrder = new int[n];
            for (int i = 0; i < n; i++)
            {
                count[classfiy[i]]++;
            }
            for (int i = 1; i < n; i++)
            {
                count[i] += count[i - 1];
            }
            for (int i = n - 1; i >= 0; i--)
            {
                int start = (order[i] - len + n) % n;
                int cl = classfiy[start];
                count[cl]--;
                newOrder[count[cl]] = start;
            }
            return newOrder;
        }

        public int[] UpdateClasses(int[] newOrder, int[] classfiy, int len)
        {
            int n = newOrder.Length;
            int[] newClassfiy = new int[n];
            newClassfiy[newOrder[0]] = 0;
            for (int i = 1; i < n; i++)
            {
                int curr = newOrder[i];
                int prev = newOrder[i - 1];
                int mid = curr + len;
                int midPrev = (prev + len) % n;
                if (classfiy[curr] != classfiy[prev] || classfiy[mid] != classfiy[midPrev])
                {
                    newClassfiy[curr] = newClassfiy[prev] + 1;
                }
                else
                {
                    newClassfiy[curr] = newClassfiy[prev];
                }
            }
            return newClassfiy;
        }


    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2000_2099.demo2024
{
    public class Class2024
    {
        public int MaxConsecutiveAnswers(string answerKey, int k)
        {
            return Math.Max(MaxConsecutiveChar(answerKey, k, 'T'), MaxConsecutiveChar(answerKey, k, 'F'));
        }

        public int MaxConsecutiveChar(string answerKey, int k, char ch)
        {
            int n = answerKey.Length;
            int ans = 0;
            for (int left = 0, right = 0, sum = 0; right < n; right++)
            {
                sum += answerKey[right] != ch ? 1 : 0;
                while (sum > k)
                {
                    sum -= answerKey[left++] != ch ? 1 : 0;
                }
                ans = Math.Max(ans, right - left + 1);
            }
            return ans;
        }

    }
}

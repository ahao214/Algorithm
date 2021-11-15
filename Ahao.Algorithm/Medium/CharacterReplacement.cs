using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 424. 替换后的最长重复字符
    /// </summary>
    public class CharacterReplacement
    {
        public int Method(string s, int k)
        {
            int result = 0;

            if (k >= s.Length)
            {
                result = s.Length;
            }

			if (s == null || s.Length == 0)
			{
				result = 0;
			}
			
			int left = 0, right = 0;
			int[] letters = new int[26]; // a mapping for char -> char count
			int max_letter = 0; // the index of the max amount char.			

			while (right < s.Length)
			{
				letters[s[right] - 'A']++;
				if (letters[s[right] - 'A'] > letters[max_letter])
					max_letter = s[right] - 'A';
				right++;

				if (right - left - letters[max_letter] > k)
				{
					letters[s[left] - 'A']--;
					left++;
				}
				result= Math.Max(result, right - left);
			}			

			return result;
        }
    }
}

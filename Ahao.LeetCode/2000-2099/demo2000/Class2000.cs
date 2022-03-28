using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo2000
{    
   public  class Class2000
    {
        public string ReversePrefix(string word, char ch)
        {
            int index = word.IndexOf(ch);
            if (index >= 0)
            {
                char []arr = word.ToCharArray();
                int i = 0, j = index;
                while (i < j)
                {
                    char tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                    i++;
                    j--;
                }
                word = new string(arr);
            }
            
            return word;
        }
    }
}

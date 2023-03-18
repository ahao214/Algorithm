﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1616
{
    public class Class1616
    {
        public bool CheckPalindromeFormation(string a, string b)
        {
            return checkConcatenation(a, b) || checkConcatenation(b, a);
        }

        public bool checkConcatenation(string a, string b)
        {
            int n = a.Length;
            int left = 0, right = n - 1;
            while (left < right && a[left] == b[right])
            {
                left++;
                right--;
            }
            if (left >= right)
            {
                return true;
            }
            return CheckSelfPalindrome(a, left, right) || CheckSelfPalindrome(b, left, right);
        }

        public bool CheckSelfPalindrome(string a, int left, int right)
        {
            while (left < right && a[left] == a[right])
            {
                left++;
                right--;
            }
            return left >= right;
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo306
{
    public class Class306
    {
        public bool IsAdditiveNumber(string num)
        {
            //直接排除
            if (num.Length < 3)
                return false; ;
            //第一个数肯定是不可以超过整个累加数的一半的
            //诸如 1991，991100，9981999
            for (int i = 0; i < num.Length / 2; i++)
            {
                string firstNumber = num.Substring(0, i + 1);
                //第一个数字也可能就是 0 ，但一旦出现 01 之类，后续必然不符要求
                if (firstNumber[0] == '0' && firstNumber.Length > 1)
                    return false; ;
                //第二个数显然也不可以超过一半
                //诸如 09999,199100
                for (int j = 0; j < num.Length / 2; j++)
                {
                    string secondNumber = num.Substring(i + 1, j + 1);
                    //第二个数字开头为零的话显然无论如何向后增长都改变不了，所以直接跳出当前循环
                    if (secondNumber[0] == '0' && secondNumber.Length > 1)
                        break; ;
                    //如果第一个数和第二个数是累加数第一个数第二个数（或干脆不存在），肯定符合后续所有要求
                    if (Verify(firstNumber, secondNumber, num.Substring(i + 1 + j + 1, num.Length - (i + 1 + j + 1))))
                        return true; ;
                }
            }
            return false;
        }

        private bool Verify(string previousNumber, string currentNumber, string other)
        {
            string sum = GetSum(previousNumber, currentNumber);
            if (other.Length < sum.Length)
                return false; ;
            int i;
            for (i = 0; i < sum.Length; i++)
            {
                if (sum[i] != other[i])
                    return false; ;
            }
            if (i == other.Length)
                return true; ;
            return Verify(currentNumber, other.Substring(0, i), other.Substring(i, other.Length - i));
        }

        private string GetSum(string n1, string n2)
        {
            StringBuilder sum = new StringBuilder();
            int carry = 0;
            for (int i = 1; i <= n1.Length || i <= n2.Length; i++)
            {
                int n = carry;
                n += i <= n1.Length ? n1[n1.Length - i] - 48 : 0;
                n += i <= n2.Length ? n2[n2.Length - i] - 48 : 0;
                carry = n / 10;
                n %= 10;
                sum.Insert(0, (char)(n + 48));
            }
            if (carry > 0)
                sum.Insert(0, '1'); ;
            return sum.ToString();
        }



        public bool IsAdditiveNumber1(string num)
        {
            if (num.Length < 3)
                return false; ;
            for (int i = 0; i < num.Length / 2; i++)
            {
                if (num[0] == '0' && i > 0)
                    return false; ;
                for (int j = 0; j < num.Length / 2; j++)
                {
                    if (num[i + 1] == '0' && j > 1)
                        break; ;
                    if (Verify1(0, i + 1, i + 2 + j, num))
                        return true; ;
                }
            }
            return false;
        }

        private bool Verify1(int firstIndex, int secondIndex, int rightEdge, string num)
        {
            string sum = GetSum1(firstIndex, secondIndex, rightEdge, num);
            if (num.Length - rightEdge < sum.Length)
                return false; ;
            int i;
            for (i = 0; i < sum.Length; i++)
            {
                if (sum[i] != num[rightEdge + i])
                    return false; ;
            }
            if (i == num.Length - rightEdge)
                return true; ;
            return Verify1(secondIndex, rightEdge, rightEdge + i, num);
        }

        private string GetSum1(int firstIndex, int secondIndex, int rightEdge, string num)
        {
            StringBuilder sum = new StringBuilder();
            int carry = 0;
            for (int i = 1; i <= secondIndex - firstIndex || i <= rightEdge - secondIndex; i++)
            {
                int n = carry;
                n += i <= secondIndex - firstIndex ? num[secondIndex - i] - 48 : 0;
                n += i <= rightEdge - secondIndex ? num[rightEdge - i] - 48 : 0;
                carry = n / 10;
                n %= 10;
                sum.Insert(0, (char)(n + 48));
            }
            if (carry > 0)
                sum.Insert(0, '1');
            return sum.ToString();
        }
    }
}

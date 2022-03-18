using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo537
{
    /*
     537. 复数乘法
复数 可以用字符串表示，遵循 "实部+虚部i" 的形式，并满足下述条件：

实部 是一个整数，取值范围是 [-100, 100]
虚部 也是一个整数，取值范围是 [-100, 100]
i2 == -1
给你两个字符串表示的复数 num1 和 num2 ，请你遵循复数表示形式，返回表示它们乘积的字符
     */
    public class Class537
    {
        public string ComplexNumberMultiply(string num1, string num2)
        {
            string[] com1 = num1.Split(new char[2] { '+', 'i' });
            string[] com2 = num2.Split(new char[2] { '+', 'i' });

            int real1 = int.Parse(com1[0]);
            int false1 = int.Parse(com1[1]);
            int real2 = int.Parse(com2[0]);
            int false2 = int.Parse(com2[1]);

            return string.Format("{0}+{1}i", real1 * real2 - false1 * false2, real1 * false2 + false1 * real2);
        }
    }
}

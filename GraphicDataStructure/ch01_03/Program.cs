using static System.Console;

namespace ch01_03;

internal class Program
{
    static void Main(string[] args)
    {
        int sum = 1;
        Console.Write("请从键盘输入n=");
        int n = int.Parse(ReadLine());
        // 用for循环计算 n!
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = i; j > 0; j--)
            {
                sum = sum * j;
            }
            WriteLine(i + "!=" + sum);
            sum = 1;
        }
        ReadLine();
    }
}

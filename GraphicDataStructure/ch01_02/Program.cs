using static System.Console;

namespace ch01_02;

internal class Program
{
    static void Main(string[] args)
    {
        int num;
        string str;

        WriteLine("使用递归计算斐波那契数列");
        Write("请输入一个整数：");
        str = ReadLine();
        num = int.Parse(str);
        if (num < 0)
            WriteLine("输入的数字必须大于0\n");
        else
            Write("Fibonacci(" + num + ")=" + Fibonacci(num) + "\n");
        ReadKey();

    }

    static int Fibonacci(int n)
    {
        if (n == 0) //第0项为0
            return 0;
        else if (n == 1)  //第1项为1
            return 1;
        else
            return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

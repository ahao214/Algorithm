// 使用for循环计算一个n!的阶乘程序


int sum = 1;
Console.Write("请从键盘输入n=");
int n = int.Parse(Console.ReadLine());
// 用for循环计算 n!
for (int i = 1; i < n + 1; i++)
{
    for (int j = i; j > 0; j--)
    {
        sum = sum * j;
    }
    Console.WriteLine(i + "!=" + sum);
    sum = 1;
}
Console.ReadLine();


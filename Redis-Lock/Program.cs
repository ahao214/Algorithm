using System;

namespace Redis_Lock
{
    class Program
    {
        static void Main(string[] args)
        {
            var builder = new ConfigurationBuilder().AddCommandLine(args);


            Console.WriteLine("Hello World!");
        }
    }
}

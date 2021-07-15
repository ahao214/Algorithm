using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace MongoDBServer
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                {
                    WriteLine("---json操作---");
                    JsonOperation.Show();
                }


            }
            catch (Exception ex)
            {
                WriteLine(ex.Message);
            }


            ReadLine();
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ServiceStack.Redis;
using static System.Console;

namespace Redis_Hash
{
    class Program
    {
        /// <summary>
        /// redis的hash操作
        /// </summary>
        /// <param name="args"></param>
        static void Main(string[] args)
        {
            using(IRedisClient client =new   RedisClient ("127.0.0.1",6379))
            {



            };


            Console.ReadLine();
        }
    }
}

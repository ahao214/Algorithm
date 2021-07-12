using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Policy;
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
            using (IRedisClient client = new RedisClient("127.0.0.1", 6379))
            {
                client.FlushDb();


                string hashId = "stu";
                //单个新增
                client.SetEntryInHash(hashId, "id", "101");
                //读取
                WriteLine(client.GetValueFromHash(hashId, "id"));
                client.SetEntryInHash(hashId, "name", "Jerry");
                WriteLine(client.GetValueFromHash(hashId, "name"));
                client.SetEntryInHash(hashId, "age", "12");
                WriteLine(client.GetValueFromHash(hashId, "age"));

                //批量操作
                Dictionary<string, string> stu = new Dictionary<string, string>();
                stu.Add("id", "100");
                stu.Add("name", "Jack");
                stu.Add("address", "shanghai");
                client.SetRangeInHash(hashId, stu);
                //批量读取
                var dic = client.GetAllEntriesFromHash(hashId);
                foreach (var item in dic)
                {
                    WriteLine(item.Key + ":" + item.Value);
                }


            };


            Console.ReadLine();
        }
    }
}

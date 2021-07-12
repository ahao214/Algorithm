using System;
using Newtonsoft.Json;
using ServiceStack.Redis;
using static System.Console;

namespace Redis_String
{
    class Program
    {
        static void Main(string[] args)
        {            
            using (IRedisClient client = new RedisClient("127.0.0.1", 6379))
            {
                //清空当前数据库
                client.FlushDb();


                #region 单个操作

                client.Set<string>("name", "ahao");

                //读取数据
                var valueOne = client.GetValue("name");
                WriteLine("第一个出读取数据:", valueOne);

                var valueTwo = client.Get<string>("name");
                WriteLine("第二次读取数据：",valueTwo);

                var valueThree = client.GetValue("name");
                WriteLine(JsonConvert.DeserializeObject<string>(valueThree));



                #endregion

                #region 批量操作


                #endregion
            };
            Console.ReadLine();

        }
    }
}

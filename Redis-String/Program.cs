using System;
using System.Collections.Generic;
using System.Threading.Tasks;
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

                //client.Set<string>("name", "ahao");

                ////读取数据
                //var valueOne = client.GetValue("name");
                //WriteLine("第一个出读取数据:", valueOne);

                //var valueTwo = client.Get<string>("name");
                //WriteLine("第二次读取数据：",valueTwo);

                //var valueThree = client.GetValue("name");
                //WriteLine(JsonConvert.DeserializeObject<string>(valueThree));

                #endregion

                #region 批量操作

                //var dicts = new Dictionary<string, string>();
                //dicts.Add("id", "101");
                //dicts.Add("name", "ahao");
                //dicts.Add("addresss", "shanghai");
                ////批量写入
                //client.SetAll(dicts);
                ////读取
                //var lst = client.GetAll<string>(new string[] { "id", "name", "address" });
                //foreach (var item in lst)
                //{
                //    WriteLine(item);
                //    WriteLine("key:" + item.Key);
                //    WriteLine("value:" + item.Value);
                //}

                #endregion

                #region 设置过期时间

                //client.Set<string>("name", "ahao", TimeSpan.FromSeconds(10));

                //client.Set<string>("address", "shanghai", TimeSpan.FromSeconds(1));
                //Task.Delay(1 * 1000).Wait();
                ////如果读不到key则返回一个""
                //WriteLine(client.Get<string>("address"));

                ////设置特定的过期时间

                ////指定明天的这个时候过期
                //client.Set<string>("age", "18", DateTime.Now.AddDays(1));

                #endregion








            };



            Console.ReadLine();

        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;
using ServiceStack.Redis;
using ServiceStack.Text;
using static System.Console;

namespace Redis_SetAndZset
{
    class Program
    {
        /// <summary>
        /// Redis中set和zset
        /// </summary>
        /// <param name="args"></param>
        static void Main(string[] args)
        {
            using (IRedisClient client = new RedisClient("127.0.0.1", 6379))
            {
                //清空当前数据库
                client.FlushDb();

                //set也是一个集合，自动去重的一个
                var libai = new User() { ID = "01", Name = "李白" };
                client.AddItemToSet("setId", JsonConvert.SerializeObject(libai));
                client.AddItemToSet("setId", JsonConvert.SerializeObject(libai));
                client.AddItemToSet("setId", JsonConvert.SerializeObject(libai));

                var dufu = new User() { ID = "02", Name = "杜甫" };
                client.AddItemToSet("setId", JsonConvert.SerializeObject(dufu));
                WriteLine(client.GetSetCount("setId"));


                ReadLine();
            };
        }
    }
}

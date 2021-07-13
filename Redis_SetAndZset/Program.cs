using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
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


                WriteLine("******************");
                //批量
                client.AddRangeToSet("setIds", new List<string>() { "01", "02", "03", "04", "05" });
                WriteLine(client.GetSetCount("setIds"));

                var sets = client.GetAllItemsFromSet("setIds");
                foreach (var item in sets)
                {
                    WriteLine(item);
                }

                WriteLine("******************");

                //随机获取set中的值
                for (int i = 0; i < 10; i++)
                {
                    WriteLine(client.GetRandomItemFromSet("setIds"));
                }

                WriteLine("******************");
                //随机删除，返回结果并删除
                for (int i = 0; i < 3; i++)
                {
                    WriteLine(client.PopItemFromSet("setIds"));
                }

                WriteLine("******************");

                client.AddRangeToSet("ids", new List<string>() { "01", "02", "03", "04", "05" });
                //根据值去删除
                client.RemoveItemFromSet("ids", "01");
                client.RemoveItemFromSet("ids", "02");
                var lst = client.GetAllItemsFromSet("ids");
                foreach (var item in lst)
                {
                    WriteLine(item);
                }



                WriteLine("******************");




                WriteLine("******************");


                ReadLine();
            };
        }
    }
}

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

                //从原来的集合，移除值到新的一个集合总
                client.AddRangeToSet("one", new List<string>() { "a", "b", "c", "d" });
                client.MoveBetweenSets("one", "two", "a");
                client.MoveBetweenSets("one", "two", "d");

                WriteLine("********交集**********");

                //交叉并补

                client.AddRangeToSet("a", new List<string>() { "1", "3", "5" });
                client.AddRangeToSet("b", new List<string>() { "2", "4", "5", "6" });
                //交集
                var jjlist = client.GetIntersectFromSets("a", "b");
                foreach (var item in jjlist)
                {
                    WriteLine(item);
                }

                WriteLine("********并集**********");
                //并集
                var bjlist = client.GetUnionFromSets("a", "b");
                foreach (var item in bjlist)
                {
                    WriteLine(item);
                }


                WriteLine("********差集**********");
                var cjlist = client.GetDifferencesFromSet("a", "b");
                foreach (var item in cjlist)
                {
                    WriteLine(item);
                }

                WriteLine("***zset***");

                //zset 自动去重，而且多一个权重，或者份数的字段，自动排序

                //当不给分数的时候，默认是最大值
                client.AddItemToSortedSet("zsetid", "a", 90);
                client.AddItemToSortedSet("zsetid", "b", 100);
                client.AddItemToSortedSet("zsetid", "c", 80);

                WriteLine("**************");
                //批量添加
                client.AddRangeToSortedSet("zsetidrange", new List<string>() { "a", "b" }, 100);


                WriteLine("**************");
                //正序查询
                var zsetlist = client.GetAllItemsFromSortedSet("zsetid");
                foreach (var item in zsetlist)
                {
                    WriteLine(item);
                }

                //倒序查询
                var zsetDesc = client.GetAllItemsFromSortedSetDesc("zsetid");
                foreach (var item in zsetDesc)
                {
                    WriteLine(item);
                }


                WriteLine("**************");

                //根据下标获取
                var dic = client.GetRangeFromSortedSet("zsetid", 0, 1);
                foreach (var item in dic)
                {
                    WriteLine(item);
                }

                WriteLine("**************");
                //返回份数
                var dicScore = client.GetRangeWithScoresFromSortedSet("zsetid", 0, 1);
                foreach (var item in dicScore)
                {
                    WriteLine(item.Key + ":" + item.Value);
                }

                WriteLine("**************");

                //把集合中的交集放入到一个新的集合中
                client.AddItemToSortedSet("x", "a", 1);
                client.AddItemToSortedSet("x", "b", 2);
                client.AddItemToSortedSet("x", "c", 3);
                client.AddItemToSortedSet("x", "d", 4);
           
                client.AddItemToSortedSet("y", "c", 3);
                client.AddItemToSortedSet("y", "d", 4);

                client.AddItemToSortedSet("z", "c", 3);
                client.AddItemToSortedSet("z", "e", 9);

                var newDic = client.StoreIntersectFromSortedSets("newSet", "x", "y", "z");
                WriteLine(newDic);



                ReadLine();
            };
        }
    }
}

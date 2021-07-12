using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;
using ServiceStack;
using ServiceStack.Redis;
using ServiceStack.Text;
using ServiceStack.Text.Common;
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

                #region 新增和读取

                //string hashId = "stu";
                ////单个新增
                //client.SetEntryInHash(hashId, "id", "101");
                ////读取
                //WriteLine(client.GetValueFromHash(hashId, "id"));
                //client.SetEntryInHash(hashId, "name", "Jerry");
                //WriteLine(client.GetValueFromHash(hashId, "name"));
                //client.SetEntryInHash(hashId, "age", "12");
                //WriteLine(client.GetValueFromHash(hashId, "age"));

                ////批量操作
                //Dictionary<string, string> stu = new Dictionary<string, string>();
                //stu.Add("id", "100");
                //stu.Add("name", "Jack");
                //stu.Add("address", "shanghai");
                //client.SetRangeInHash(hashId, stu);
                ////批量读取
                //var dic = client.GetAllEntriesFromHash(hashId);
                //foreach (var item in dic)
                //{
                //    WriteLine(item.Key + ":" + item.Value);
                //}

                #endregion

                #region 操作对象

                string hashId = "stu";
                //如果hash集合中已经存在了相同k/v的时候，则新增失败，返回false，否则可以新增成功
                //WriteLine(client.SetEntryInHashIfNotExists(hashId, "name", "jack"));
                //WriteLine(client.SetEntryInHashIfNotExists(hashId, "name", "jack666"));

                //client.StoreAsHash<UserInfo>(new UserInfo { ID = "001", Name = "ahao", Address = "SH" });
                //WriteLine(client.GetFromHash<UserInfo>("001").ID);
                //WriteLine(client.GetFromHash<UserInfo>("001").Name);
                //WriteLine(client.GetFromHash<UserInfo>("001").Address);

                #endregion

                #region hash的其他操作

                //Dictionary<string, string> dic = new Dictionary<string, string>();
                //dic.Add("id", "001");
                //dic.Add("name", "Jack");
                //client.SetRangeInHash(hashId, dic);

                ////读取hash中key的总数
                //WriteLine("Hash中key的数量：" + client.GetHashCount(hashId));

                ////读取hash中所有keys
                //var keys = client.GetHashKeys(hashId);
                //foreach (var item in keys)
                //{
                //    WriteLine("hash中key的值：" + item);
                //}

                ////读取hash中所有的values
                //var values = client.GetHashValues(hashId);
                //foreach (var item in values)
                //{
                //    WriteLine("hash中value的值：" + item);
                //}

                ////删除hash中的某个值
                //client.RemoveEntryFromHash(hashId, "id");
                //WriteLine(client.GetHashCount(hashId));

                ////判断hash中是否存在key的数据
                //WriteLine(client.HashContainsEntry(hashId, "id"));
                //WriteLine(client.HashContainsEntry(hashId, "name"));

                //给hash中的key的value加count
                //Dictionary<string, string> stu = new Dictionary<string, string>();
                //stu.Add("id", "002");
                //stu.Add("name", "ahao");
                //stu.Add("num", "1");
                //client.SetRangeInHash(hashId, stu);
                //client.IncrementValueInHash(hashId, "num", 10);
                //WriteLine(client.GetValuesFromHash(hashId, "num")[0]);

                #endregion

            };


            Console.ReadLine();
        }
    }
}

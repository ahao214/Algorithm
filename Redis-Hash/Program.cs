using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;
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

                client.StoreAsHash<UserInfo>(new UserInfo { ID = "001", Name = "ahao", Address = "SH" });
                WriteLine(client.GetFromHash<UserInfo>("001").ID);
                WriteLine(client.GetFromHash<UserInfo>("001").Name);
                WriteLine(client.GetFromHash<UserInfo>("001").Address);

                #endregion




            };


            Console.ReadLine();
        }
    }
}

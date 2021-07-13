using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;
using ServiceStack;
using ServiceStack.Redis;
using ServiceStack.Text;
using static System.Console;


namespace Redis_List
{
    class Program
    {
        /// <summary>
        /// redis的list操作
        /// </summary>
        /// <param name="args"></param>
        static void Main(string[] args)
        {
            using (IRedisClient client = new RedisClient("127.0.0.1", 6379))
            {
                client.FlushDb();

                #region 顺序添加

                //var caocao = new User() { ID = "01", Name = "曹操" };
                //client.AddItemToList("list", JsonConvert.SerializeObject(caocao));
                //var liubei = new User() { ID = "02", Name = "刘备" };
                //client.AddItemToList("list", JsonConvert.SerializeObject(liubei));

                #endregion

                #region 从左侧向list添加 追加

                //var guanyu = new User() { ID = "03", Name = "关羽" };
                //client.PushItemToList("list", JsonConvert.SerializeObject(guanyu));

                #endregion

                #region 从右侧向list添加 插队

                //var zhangfei = new User() { ID = "04", Name = "张飞" };
                //client.PrependItemToList("list", JsonConvert.SerializeObject(zhangfei));

                #endregion

                #region 设置过期时间

                //client.ExpireEntryAt("list", DateTime.Now.AddSeconds(1));
                //WriteLine(client.GetListCount("list"));
                //Task.Delay(2 * 1000).Wait();
                //WriteLine(client.GetListCount("list"));

                #endregion

                #region 批量添加

                //client.AddRangeToList("lists", new List<string>() { "1", "2", "3", "4" });
                ////按下标来查询
                //var values = client.GetRangeFromList("lists", 0, 2);
                //foreach(var item in values)
                //{
                //    WriteLine(item);
                //}

                #endregion

                #region list栈操作 后进先出

                var caocao = new User() { ID = "01", Name = "曹操" };
                client.AddItemToList("list", JsonConvert.SerializeObject(caocao));
                var liubei = new User() { ID = "02", Name = "刘备" };
                client.AddItemToList("list", JsonConvert.SerializeObject(liubei));
                var guanyu = new User() { ID = "03", Name = "关羽" };
                client.AddItemToList("list", JsonConvert.SerializeObject(guanyu));
                var zhangfei = new User() { ID = "04", Name = "张飞" };
                client.AddItemToList("list", JsonConvert.SerializeObject(zhangfei));

                //移除尾部，并返回结果
                //WriteLine(client.RemoveEndFromList("list"));
                //WriteLine(client.RemoveEndFromList("list"));
                //WriteLine(client.RemoveEndFromList("list"));

                //移除头部，并返回结果
                WriteLine(client.RemoveStartFromList("list"));
                WriteLine(client.RemoveStartFromList("list"));


                #endregion



                ReadLine();
            };
        }
    }
}

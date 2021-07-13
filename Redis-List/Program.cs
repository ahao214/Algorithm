﻿using System;
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

                var caocao = new User() { ID = "01", Name = "曹操" };
                client.AddItemToList("list", JsonConvert.SerializeObject(caocao));
                var liubei = new User() { ID = "02", Name = "刘备" };
                client.AddItemToList("list", JsonConvert.SerializeObject(liubei));

                #endregion

                #region 从左侧向list添加 追加

                var guanyu = new User() { ID = "03", Name = "关羽" };
                client.PushItemToList("list", JsonConvert.SerializeObject(guanyu));

                #endregion

                #region 从右侧向list添加 插队

                var zhangfei = new User() { ID = "04", Name = "张飞" };
                client.PrependItemToList("list", JsonConvert.SerializeObject(zhangfei));


                #endregion

                ReadLine();
            };
        }
    }
}

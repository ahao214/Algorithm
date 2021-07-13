using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using ServiceStack.Redis;
using ServiceStack.Text.Common;
using static System.Console;

namespace Redis_LockServer
{
    public class NormalSecondsKill
    {
        public static void Show()
        {
            using (var client = new RedisClient("127.0.0.1", 6379))
            {
                //获取库存数量
                var inventory = client.Get<int>("inventoryNum");
                if (inventory > 0)
                {
                    //库存减1
                    client.Set<int>("inventoryNum", inventory - 1);
                    //订单加1
                    var orderNum = client.Incr("orderNum");
                    WriteLine($"抢购成功xx线程id：{Thread.CurrentThread.ManagedThreadId.ToString("00")},库存:{inventory},订单数量：{orderNum}");
                }
                else
                {
                    WriteLine("抢购失败!");
                }
            };
        }

        public static void LockShow()
        {
            //加锁就是1 释放锁就是0
            lock("锁")
            {
                using (var client = new RedisClient("127.0.0.1", 6379))
                {
                    //获取库存数量
                    var inventory = client.Get<int>("inventoryNum");
                    if (inventory > 0)
                    {
                        //库存减1
                        client.Set<int>("inventoryNum", inventory - 1);
                        //订单加1
                        var orderNum = client.Incr("orderNum");
                        WriteLine($"抢购成功xx线程id：{Thread.CurrentThread.ManagedThreadId.ToString("00")},库存:{inventory},订单数量：{orderNum}");
                    }
                    else
                    {
                        WriteLine("抢购失败!");
                    }
                };
            }
        }
    }

}

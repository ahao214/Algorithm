using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using ServiceStack.Redis;
using ServiceStack.Text.Common;
using static System.Console;


namespace Redis_LockServer
{
    public class BlockingLock
    {
        //这个是阻塞的锁
        public static void Show(int i, string key, TimeSpan timeout)
        {
            using (var client = new RedisClient("127.0.0.1", 6379))
            {
                //获取锁
                using (var datalock = client.AcquireLock("DataLock:" + key, timeout))
                {
                    //库存数量
                    var inventory = client.Get<int>("inventoryNum");
                    if (inventory > 0)
                    {
                        client.Set<int>("inventoryNum", inventory - 1);
                        //订单数量
                        var orderNum = client.Incr("order Num");
                        WriteLine($"{i}抢购成功xx线程ID：{Thread.CurrentThread.ManagedThreadId.ToString("00")},库存数量:{inventory},订单数量：{orderNum}");
                    }
                    else
                    {
                        WriteLine($"{i}抢购失败");
                    }
                    Thread.Sleep(100);
                }

            };
        }
    }
}

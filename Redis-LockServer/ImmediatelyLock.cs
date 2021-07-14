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
    public class ImmediatelyLock
    {
        //非阻塞锁
        public static void Show(int i,string key,TimeSpan timeout)
        {
            using (var client = new RedisClient("127.0.0.1",6379))
            {
                bool isLock = client.Add<string>("Datalock:" + key, key, timeout);
                if (isLock)
                {
                    try
                    {
                        //库存数量
                        var inventory = client.Get<int>("inventoryNum");
                        if (inventory>0)
                        {
                            client.Set<int>("inventoryNum", inventory - 1);
                            //订单数量
                            var orderNum = client.Incr("orderNum");
                            WriteLine($"{i}抢购成功xx线程ID：{Thread.CurrentThread.ManagedThreadId.ToString("00")},库存：{inventory},订单数量:{orderNum}");
                        }
                        else
                        {
                            WriteLine($"{i}抢购失败：原因：没有库存");
                        }
                    }
                    catch
                    {
                        throw;
                    }
                    finally
                    {
                        client.Remove("Datalock:" + key);
                    }
                }
                else
                {
                    WriteLine($"{i}抢购失败：原因，没有拿到锁");
                }                
            };

        }
    }
}

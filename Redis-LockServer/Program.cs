using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using ServiceStack.Redis;
using System.Configuration;

namespace Redis_LockServer
{
    class Program
    {
        static void Main(string[] args)
        {
            var builder = new ConfigurationBuilder().AddCommandLine(args);
            var configuration = builder.Builder();
            int minute = int.Parse(configuration["minute"]);
            using (var client = new RedisClient("127.0.0.1", 6379))
            {
                //先把库存数量预支进去
                client.Set<int>("inventoryNum", 10);
                //订单
                client.Set<int>("orderNum", 0);
            };

            WriteLine($"在{minute}分0秒正式开启秒杀!");
            var flag = true;
            while (flag)
            {
                if (DateTime.Now.Minute == minute)
                {
                    flag = false;
                    Parallel.For(0, 30, (i) =>
                   {
                       int temp = i;
                       Task.Run(() =>
                       {
                           //正常情况下
                           NormalSecondsKill.Show();
                           //加锁的情况下
                           NormalSecondsKill.LockShow();
                           //阻塞锁
                           //BlockingLock.Show(i, "akey", TimeSpan.FromSeconds(100));
                           //非阻塞锁
                           //ImmediatelyLock.Show(i, "akey", TimeSpan.FromSeconds(100));
                       });
                   });
                }
            }



        }
    }
}

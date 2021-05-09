using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 辅助测试类
    /// </summary>
    class TestHelper
    {
        //读取名为filename的文件，并将它分词，分词后存入list中并返回使用
        public static List<string> ReadFile(string filename)
        {
            //使用FileStream类打开filename文件
            FileStream fs = new FileStream(filename, FileMode.Open);
            //使用StreamRead读取filename文件信息
            StreamReader sr = new StreamReader(fs);
            //将读取的单词存入动态数组words中
            List<string> words = new List<string>();

            //分词操作
            while (!sr.EndOfStream)
            {
                string contents = sr.ReadLine().Trim();
                //寻找contents第一个字母的位置
                int start = FirstCharacterIndex(contents, 0);
                for (int i = start + 1; i <= contents.Length;)
                {
                    if (i == contents.Length || !char.IsLetter(contents[i]))
                    {
                        string word = contents.Substring(start, i - start).ToLower();
                        words.Add(word);
                        start = FirstCharacterIndex(contents, i);
                        i = start + 1;
                    }
                    else
                    {
                        i++;
                    }
                }
            }
            //关闭流对象释放资源
            fs.Close();
            sr.Close();
            return words;
        }


        //寻找字符串s中，从start的位置开始的第一个字母字符的位置
        private static int FirstCharacterIndex(string s, int start)
        {
            for (int i = start; i < s.Length; i++)
            {
                if (Char.IsLetter(s[i]))
                    return i;
            }
            return s.Length;
        }
    }
}

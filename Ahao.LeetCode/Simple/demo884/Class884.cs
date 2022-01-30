using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo884
{
    /*
     884. 两句话中的不常见单词
    句子 是一串由空格分隔的单词。每个 单词 仅由小写字母组成。
    如果某个单词在其中一个句子中恰好出现一次，在另一个句子中却 没有出现 ，那么这个单词就是 不常见的 。
    给你两个 句子 s1 和 s2 ，返回所有 不常用单词 的列表。返回列表中单词可以按 任意顺序 组织。
     */
    public class Class884
    {
        public string[] UncommonFromSentences(string s1, string s2)
        {
            Dictionary<string, int> dic = new Dictionary<string, int>();
            string[] arrS1 = s1.Split(" ");
            string[] arrS2 = s2.Split(" ");
            foreach (var item in arrS1)
            {
                if (!dic.ContainsKey(item))
                {
                    dic.Add(item, 0);
                }
                ++dic[item];
            }
            foreach (var item in arrS2)
            {
                if (!dic.ContainsKey(item))
                    dic.Add(item, 0);
                ++dic[item];
            }
            IList<string> res = new List<string>();
            foreach (KeyValuePair<string, int> pair in dic)
            {
                if (pair.Value == 1)
                {
                    res.Add(pair.Key);
                }
            }
            return res.ToArray();
        }
    }
}

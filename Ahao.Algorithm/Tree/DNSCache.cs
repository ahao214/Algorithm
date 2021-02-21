using System;

namespace Ahao.Algorithm.Tree
{
    /// <summary>
    /// 如何实现反向DNS查找缓存
    /// </summary>
    class DNSCache
    {
        //IP地址最多有11个不同的字符
        private const int CHAR_COUN = 11;
        //IP地址最大的长度
        private TrieNode root = new TrieNode();

        //Trie树的结点
        public class TrieNode
        {
            public bool IsLeaf { get; set; }

            public string Url { get; set; }
            public TrieNode[] Child { get; set; }

            public TrieNode()
            {
                this.IsLeaf = false;
                this.Url = null;
                this.Child = new TrieNode[CHAR_COUN];
                for (int i = 0; i < CHAR_COUN; i++)
                {
                    Child[i] = null;
                }
            }
        }

        public int GetIndexFromChar(char c)
        {
            return (c == '.') ? 10 : (c - '0');
        }

        public char GetCharFromIndex(int i)
        {
            return (i == 10) ? '.' : (char)('0' + i);
        }


        //把一个IP地址和相应的URL添加到Trie树中，最后一个结点是URL
        public void insert(string ip, string url)
        {
            //IP地址的长度
            int len = ip.Length;
            TrieNode pCrawl = root;

            int level;
            for (level = 0; level < len; level++)
            {
                //根据当前遍历到的ip中的字符，找出子节点的索引
                int index = GetIndexFromChar(ip[level]);

                //如果子节点不存在，则创建一个
                if (pCrawl.Child[index] == null)
                {
                    pCrawl.Child[index] = new TrieNode();
                }

                //移动到子节点
                pCrawl = pCrawl.Child[index];
            }

            //在叶子节点中存储IP对应的URL
            pCrawl.IsLeaf = true;
            pCrawl.Url = url;
        }

        //通过IP地址找到对应的URL
        public String searchDNSCache(String ip)
        {
            TrieNode pCrawl = root;
            int len = ip.Length;

            int level;
            //遍历IP地址中所有的字符
            for (level = 0; level < len; level++)
            {
                int index = GetIndexFromChar(ip[level]);
                if(pCrawl .Child [index ]==null )
                {
                    return null;
                }
                pCrawl = pCrawl.Child[index];
            }

            //返回找到的URL
            if(pCrawl!=null && pCrawl.IsLeaf )
            {
                return pCrawl.Url;
            }

            return null;

        }
    }
}

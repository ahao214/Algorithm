﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1400_1499.demo1410
{
    public class Class1410
    {
        class EntityChar
        {
            public string Entity
            {
                get;
            }
            public char Character
            {
                get;
            }

            public EntityChar(string entity, char character)
            {
                Entity = entity;
                Character = character;
            }
        }

        IList<EntityChar> entityList = new List<EntityChar>();

        public string EntityParser(string text)
        {
            entityList.Add(new EntityChar("&quot;", '"'));
            entityList.Add(new EntityChar("&apos;", '\''));
            entityList.Add(new EntityChar("&amp;", '&'));
            entityList.Add(new EntityChar("&gt;", '>'));
            entityList.Add(new EntityChar("&lt;", '<'));
            entityList.Add(new EntityChar("&frasl;", '/'));
            StringBuilder res = new StringBuilder();
            int length = text.Length;
            int pos = 0;
            while (pos < length)
            {
                bool isEntity = false;
                if (text[pos] == '&')
                {
                    foreach (EntityChar entityChar in entityList)
                    {
                        string e = entityChar.Entity;
                        char c = entityChar.Character;
                        if (pos + e.Length <= text.Length && text.Substring(pos, e.Length).Equals(e))
                        {
                            res.Append(c);
                            pos += e.Length;
                            isEntity = true;
                            break;
                        }
                    }
                }
                if (!isEntity)
                {
                    res.Append(text[pos++]);
                    continue;
                }
            }
            return res.ToString();
        }


    }
}

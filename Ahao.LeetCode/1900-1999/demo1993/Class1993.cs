﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1900_1999.demo1993
{

    public class LockingTree
    {
        private int[] parent;
        private int[] lockNodeUser;
        private IList<int>[] children;

        public LockingTree(int[] parent)
        {
            int n = parent.Length;
            this.parent = parent;
            this.lockNodeUser = new int[n];
            Array.Fill(this.lockNodeUser, -1);
            this.children = new IList<int>[n];
            for (int i = 0; i < n; i++)
            {
                this.children[i] = new List<int>();
            }
            for (int i = 0; i < n; i++)
            {
                int p = parent[i];
                if (p != -1)
                {
                    children[p].Add(i);
                }
            }
        }

        public bool Lock(int num, int user)
        {
            if (lockNodeUser[num] == -1)
            {
                lockNodeUser[num] = user;
                return true;
            }
            return false;
        }

        public bool Unlock(int num, int user)
        {
            if (lockNodeUser[num] == user)
            {
                lockNodeUser[num] = -1;
                return true;
            }
            return false;
        }

        public bool Upgrade(int num, int user)
        {
            bool res = lockNodeUser[num] == -1 && !HasLockedAncestor(num) && CheckAndUnlockDescendant(num);
            if (res)
            {
                lockNodeUser[num] = user;
            }
            return res;
        }

        private bool HasLockedAncestor(int num)
        {
            num = parent[num];
            while (num != -1)
            {
                if (lockNodeUser[num] != -1)
                {
                    return true;
                }
                num = parent[num];
            }
            return false;
        }

        private bool CheckAndUnlockDescendant(int num)
        {
            bool res = lockNodeUser[num] != -1;
            lockNodeUser[num] = -1;
            foreach (int child in children[num])
            {
                res |= CheckAndUnlockDescendant(child);
            }
            return res;
        }

    }
}

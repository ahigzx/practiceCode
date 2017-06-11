class IdenticalTree {
    public:
        bool chkIdentical(TreeNode* A, TreeNode* B) {
            if(A == NULL)
                return false;
            string aSeq;
            string bSeq;
            treeToSeqence(A, aSeq);
            treeToSeqence(B, bSeq);
            if(kmpSearch(aSeq, bSeq) >= 0)
                return true;
            else
                return false;
        }

        void treeToSeqence(TreeNode* root, string& sequence)
        {
            if(root == NULL)
            {
                sequence += string("# ");
                return;
            }
            sequence += to_string(root->val) += string(" ");
            treeToSeqence(root->left, sequence);
            treeToSeqence(root->right, sequence);
        }

        vector<int> getNext(string p)
        {
            int len = p.size();
            vector<int> next(len + 1);
            int k = -1;
            int j = 0;
            next[0] = -1;
            while(j < len)
            {
                if(k == -1 || p[j] == p[k])
                {
                    ++j;
                    ++k;
                    next[j] = k;
                }
                else
                {
                    k = next[k];
                }
            }
            return next;
        }

        int kmpSearch(string s, string p)
        {
            vector<int> next = getNext(p);
            int sLen = s.size();
            int pLen = p.size();
            int sIndex = 0;
            int pIndex = 0;
            while(sIndex < sLen && pIndex < pLen)
            {
                if(pIndex == -1 || s[sIndex] == p[pIndex])
                {
                    ++sIndex;
                    ++pIndex;
                }
                else
                {
                    pIndex = next[pIndex];
                }
            }
            if(pIndex == pLen)
                return sIndex - pIndex;
            else
                return -1;
        }
};

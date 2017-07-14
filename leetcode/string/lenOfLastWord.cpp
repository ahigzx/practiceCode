class Solution {
    public:
        int lengthOfLastWord(const char *s) {
            if(s == NULL)
                return NULL;
            int tail  = strlen(s) - 1;
            int len = 0;
            while(tail >= 0 && s[tail] == ' ') --tail;
            while(tail >= 0 && s[tail] != ' ') 
            {
                ++len;
                --tail;
            }
            return len;

        }
};

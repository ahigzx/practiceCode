class Replacement {
    public:
        string replaceSpace(string iniString, int length) {
            if(length <= 0 || iniString.empty())
                return NULL;
            int count = 0;
            for(auto& x : iniString)
            {
                if(x == ' ')
                    ++count;
            }
            int newLen = length + 2 * count;
            int i = length - 1;
            int j = newLen - 1;
            iniString.resize(newLen);
            while(i >= 0 && j >= 0)
            {
                if(iniString[i] != ' ')
                {
                    iniString[j--] = iniString[i--];
                }
                else
                {
                    iniString[j-2] = '%';
                    iniString[j-1] = '2';
                    iniString[j] = '0';
                    j -= 3;
                    --i;
                }
            }
            return iniString;

        }
};

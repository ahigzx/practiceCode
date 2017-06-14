#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string ReverseSentence(string& sentence)
{
    if(sentence.size())
    {
        reverse(sentence.begin(), sentence.end());
        auto wordBegin = sentence.begin();
        auto wordEnd = sentence.begin();
        while(wordEnd != sentence.end() + 1)
        {
            while(*wordEnd != ' ' && wordEnd != sentence.end())
            {
                ++wordEnd;
            }
            reverse(wordBegin, wordEnd);
            ++wordEnd;
            wordBegin = wordEnd;
        }
    }
    return sentence;
}


int main(void)
{
    string sentence("i am students.");
    string str = ReverseSentence(sentence);
    cout << str << endl;
    
}

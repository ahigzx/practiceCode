#include <iostream>
#include <string.h>

using namespace std;

class CMystring{
{
    public:
        CMystring(char *pData = NULL);
        CMystring(const CMystring& str);
        ~CMystring();
        CMystring& operator =(const CMystring&);
    private:
        char * m_pData;
}


CMystring& CMystring::operator =(const CMystring& str)
{
    if(this==&str)
        return *this;

    delete []m_pData;
    m_pData = NULL;

    m_pData = new char[strlen(str.m_pData)+1];
    strcpy(m_pData, str.m_pData);
    return *this;
}

CMystring& CMystring::operator = (const CMystring& str) //考虑new分配异常安全
{
    if(this==&str)
        return *this;

    CMystring *ptemp = new char[strlen(str.m_pData + 1)];

    delete []m_pData;
    m_pData = NULL;
    m_pData = ptemp;

    strcpy(m_pData, str.m_pData);
}


CMystring& CMystring::operator = (const CMystring& str) //利用局部类对象自动调用析构函数对原str指向的字符串进行释放 这个方法初始化时需要在构造函数中用new分配字符串所需要的空间 RALL
{
    if(this!=&str)
    {
        CMystring strtemp(str);
        char *ptemp = strtemp.m_pData;
        strtemp.m_pData = m_pData;
        m_pData = ptemp;
    }

    return *this;
    
}




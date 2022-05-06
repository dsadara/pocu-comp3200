#include "MyString.h"
#include <String.h>

namespace assignment1
{
    MyString::MyString(const char* s)
        : mSize(strlen(s))
    {
        mString = new char[mSize + 1];  // 널 문자를 위해 + 1을 하였음 -> 이게 맞나 알아보기
        memcpy(mString, s, mSize);
    }

    MyString::MyString(const MyString& other)
        : mSize(other.mSize)
    {
        mString = new char[mSize + 1];
        memcpy(mString, other.mString, mSize);
    }

    MyString::~MyString()
    {   
        delete[] mString;   // 생성할 때 배열로 생성했으므로 배열표시[]를 넣어줌dd
    }

    unsigned int MyString::GetLength() const
    {
        return MyString::mSize;
    }

    const char* MyString::GetCString() const
    {
        return MyString::mString;
    }

    void MyString::Append(const char* s)
    {
        int sSize = strlen(s);
        char* result = new char[mSize + sSize + 1];
        memcpy(result, mString, mSize);
        delete[] mString;   // 이전 mString 메모리 해제 
        strncat(result, s, sSize);
        mString = result;
    }

    MyString MyString::operator+(const MyString& other) const
    {
        return MyString("temporary");
    }

    int MyString::IndexOf(const char* s)
    {
        return 0;
    }

    int MyString::LastIndexOf(const char* s)
    {
        return 0;
    }

    void MyString::Interleave(const char* s)
    {
    }

    bool MyString::RemoveAt(unsigned int i)
    {
        return false;
    }

    void MyString::PadLeft(unsigned int totalLength)
    {
    }

    void MyString::PadLeft(unsigned int totalLength, const char c)
    {
    }

    void MyString::PadRight(unsigned int totalLength)
    {
    }

    void MyString::PadRight(unsigned int totalLength, const char c)
    {
    }

    void MyString::Reverse()
    {
    }

    bool MyString::operator==(const MyString& rhs) const
    {
        return false;
    }

    MyString& MyString::operator=(const MyString& rhs)
    {
        return *this;
    }

    void MyString::ToLower()
    {
    }

    void MyString::ToUpper()
    {
    }
}
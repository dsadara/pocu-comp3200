#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
		: mSize(myStrlen(s))
	{
		mString = new char[mSize + 1];
		//memset(mString, 0, mSize + 1);
		//memcpy(mString, s, mSize + 1);
		myMemcpy(mString, s, mSize + 1);
	}

	MyString::MyString(const MyString& other)
		: mSize(other.mSize)
	{
		mString = new char[mSize + 1];
		//memset(mString, 0, mSize + 1);
		//memcpy(mString, other.mString, mSize + 1);
		myMemcpy(mString, other.mString, mSize + 1);
	}

	MyString::~MyString()
	{
		delete[] mString;   // 생성할 때 배열로 생성했으므로 배열표시[]를 넣어줌
	}

	unsigned int MyString::GetLength() const
	{
		return mSize;
	}

	const char* MyString::GetCString() const
	{
		return mString;
	}

	void MyString::Append(const char* s)
	{
		int sSize = myStrlen(s);
		char* result = new char[mSize + sSize + 1];
		//memcpy(result, mString, mSize + 1);
		myMemcpy(result, mString, mSize + 1);
		delete[] mString;   // 이전 mString 메모리 해제
		//strncat(result, s, sSize + 1);
		myStrncat(result, s, sSize + 1);
		mSize = mSize + sSize + 1;
		mString = result;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		//int size = mSize + other.GetLength() + 1;
		//char* result = new char[size];
		////memset(result, 0, size);
		////memcpy(result, mString, mSize + 1);
		//myMemcpy(result, mString, mSize + 1);
		//strncat(result, other.GetCString(), other.GetLength() + 1);
		//return MyString(result);
		MyString result(this->GetCString());
		result.Append(other.GetCString());
		return result;
	}

	int MyString::IndexOf(const char* s)
	{
		char const* ptr1 = mString; // char값을 변경시키지 못하게 하기 위해 const 설정
		char const* ptr2 = s;
		int index = -1;
		bool isFirstChar = false;
		
		for (int i = 0; i <= mSize; i++)	// iterate mString once
		{
			if (ptr1[i] == *ptr2)
			{
				// 첫번쨰 문자 플래그 온, 색인 저장 
				if (!isFirstChar)
				{
					isFirstChar = true;
					index = i;
				}
				ptr2++;
				// 비교 성공시(널문자에 도달했을시) 첫번쨰 문자 위치 반환
				if (*ptr2 == 0)
				{
					return index;
				}
			}
			else 
			{
				// 비교에 실패했을 때 플래그와 포인터 초기화
				if (isFirstChar)
				{
					isFirstChar = false;
					ptr2 = s;
					index = -1;
				}
			}

			
		}

		return index;
	}

	int MyString::LastIndexOf(const char* s)
	{
		char const* ptr1 = mString; // char값을 변경시키지 못하게 하기 위해 const 설정
		char const* ptr2 = s;
		int index = -1;
		int lastIndex = -1;
		bool isFirstChar = false;

		for (int i = 0; i <= mSize; i++)	// iterate mString once
		{
			if (ptr1[i] == *ptr2)
			{
				// 첫번쨰 문자 플래그 온, 색인 저장 
				if (!isFirstChar)
				{
					isFirstChar = true;
					index = i;
				}
				ptr2++;
				// 비교 성공시(널문자에 도달했을시) lastIndex에 첫번째 문자 인덱스 저장, 플래그와 포인터 초기화
				if (*ptr2 == 0)
				{
					lastIndex = index;
					isFirstChar = false;
					ptr2 = s;
				}
			}
			else
			{
				// 비교에 실패했을 때 플래그와 포인터 초기화
				if (isFirstChar)
				{
					isFirstChar = false;
					ptr2 = s;
					index = -1;
				}
			}


		}

		return lastIndex;
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
		// size 변수가 다르면 early return
		if (mSize != rhs.GetLength())
			return false;

		const char* ptrR = mString;
		const char* ptrL = rhs.GetCString();

		while (*ptrR != 0 && *ptrL != 0)	// 두 포인터중 하나 또는 둘이 null문자에 도달하면 반복문 탈출
		{
			if (*ptrR != *ptrL)
				return false;
			ptrR++;
			ptrL++;
		}

		// 포인터에 아직 문자열이 남아있으면 같지 않으므로 false 반환 (사실 이거 없어도 될듯한데)
		if (*ptrR != 0 || *ptrL != 0)
			return false;

		return true;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		int rSize = rhs.GetLength();
		char* tmp = new char[rSize + 1];
		myMemcpy(tmp, rhs.GetCString(), rSize + 1);
		delete[] mString;
		mString = tmp;
		mSize = rSize;
		return *this;
	}

	void MyString::ToLower()
	{
	}

	void MyString::ToUpper()
	{
	}

	int MyString::myStrlen(const char* s)
	{
		const char* ptr = s;
		int count = 0;
		while (*ptr != 0)
		{
			ptr++;
			count++;
		}

		return count;
	}

	void MyString::myMemcpy(char* dst, const char* src, int size)
	{
		for (int i = 0; i < size; i++)
		{
			*dst = *src;
			dst++;
			src++;
		}
	}

	void MyString::myStrncat(char* dst, const char* src, int size)
	{
		// find null character
		char* ptr = dst;
		while (*ptr != 0) 
		{
			ptr++;
		}
		// memcpy from null character
		myMemcpy(ptr, src, size);
	}

}
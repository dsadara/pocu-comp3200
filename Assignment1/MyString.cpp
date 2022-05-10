#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
		: mSize(myStrlen(s))
	{
		if (s == nullptr)
		{
			mString = new char[1];
			*mString = 0;
			return;
		}
		mString = new char[mSize + 1];
		//memset(mString, 0, mSize + 1);
		//memcpy(mString, s, mSize + 1);
		myMemcpy(mString, s, mSize + 1);
	}

	MyString::MyString(const MyString& other)
		: mSize(other.mSize)
	{
		if (other == nullptr)
		{
			mString = nullptr;
			return;
		}
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
		if (*s == 0)
		{
			return;
		}

		int sSize = myStrlen(s);
		char* result = new char[mSize + sSize + 1];
		//memcpy(result, mString, mSize + 1);
		myMemcpy(result, mString, mSize + 1);
		delete[] mString;   // 이전 mString 메모리 해제
		//strncat(result, s, sSize + 1);
		myStrncat(result, s, sSize + 1);
		mSize = mSize + sSize;
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
		if (mString == nullptr || s == nullptr)
		{
			return -1;
		}
		// if s is ""
		if (*s == 0)
		{
			return 0;
		}

		char const* ptr1 = mString; // char값을 변경시키지 못하게 하기 위해 const 설정
		char const* ptr2 = s;
		int index = -1;
		bool bFirstChar = false;
		
		for (size_t i = 0; i <= mSize; i++)	// iterate mString once
		{
			if (ptr1[i] == *ptr2)
			{
				// 첫번쨰 문자 플래그 온, 색인 저장 
				if (!bFirstChar)
				{
					bFirstChar = true;
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
				if (bFirstChar)
				{
					bFirstChar = false;
					ptr2 = s;
					index = -1;
					i--;
				}
			}

			
		}

		return index;
	}

	int MyString::LastIndexOf(const char* s)
	{
		if (mString == nullptr || s == nullptr)
		{
			return -1;
		}
		// if s is ""
		if (*s == 0)
		{
			return mSize;
		}

		char const* ptr1 = mString; // char값을 변경시키지 못하게 하기 위해 const 설정
		char const* ptr2 = s;
		int index = -1;
		int lastIndex = -1;
		bool bFirstChar = false;

		for (size_t i = 0; i <= mSize; i++)	// iterate mString once
		{
			if (ptr1[i] == *ptr2)
			{
				// 첫번쨰 문자 플래그 온, 색인 저장 
				if (!bFirstChar)
				{
					bFirstChar = true;
					index = i;
				}
				ptr2++;
				// 비교 성공시(널문자에 도달했을시) lastIndex에 첫번째 문자 인덱스 저장, 플래그와 포인터 초기화
				if (*ptr2 == 0)
				{
					lastIndex = index;
					bFirstChar = false;
					ptr2 = s;
				}
			}
			else
			{
				// 비교에 실패했을 때 플래그와 포인터 초기화
				if (bFirstChar)
				{
					bFirstChar = false;
					ptr2 = s;
					index = -1;
				}
			}


		}

		return lastIndex;
	}

	void MyString::Interleave(const char* s)
	{
		if (*s == 0)
		{
			return;
		}
		int sSize = myStrlen(s);
		int size = mSize + sSize + 1;
		char* result = new char[size];

		char const* ptr1 = mString;
		char const* ptr2 = s;
		char* ptrResult = result;
		bool bFirstString = true;


		while (*ptr1 != 0 && *ptr2 != 0)
		{
			if (bFirstString)
			{
				*ptrResult = *ptr1;
				ptr1++;
				ptrResult++;
				bFirstString = false;
			}
			else 
			{
				*ptrResult = *ptr2;
				ptr2++;
				ptrResult++;
				bFirstString = true;
			}
		}

		// 남은 스트링 집어넣기	
		while (*ptr1 != 0)
		{
			*ptrResult = *ptr1;
			ptr1++;
			ptrResult++;
		}
		while (*ptr2 != 0)
		{
			*ptrResult = *ptr2;
			ptr2++;
			ptrResult++;
		}
		*ptrResult = 0;

		delete[] mString;
		mString = result;
		mSize = size - 1;
	}

	bool MyString::RemoveAt(unsigned int i)
	{
		if (mSize <= i)
		{
			return false;
		}

		char* ptr = mString + i;
		char* lastPtr = ptr;
		ptr++;

		while (*ptr != 0)
		{
			*lastPtr = *ptr;
			lastPtr = ptr;
			ptr++;
		}
		*lastPtr = 0;
		mSize--;

		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		if (totalLength <= mSize)
		{
			return;
		}
		int numToPad = totalLength - mSize;

		char* result = new char[totalLength + 1];
		mSize = totalLength;
		char* resultPtr = result;
		for (int i = 0; i < numToPad; i++)
		{
			*resultPtr = ' ';
			resultPtr++;
		}
		
		char* ptrM = mString;
		while (*ptrM != 0)
		{
			*resultPtr = *ptrM;
			ptrM++;
			resultPtr++;
		}
		*resultPtr = 0;
		
		delete[] mString;
		mString = result;

	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		if (totalLength <= mSize)
		{
			return;
		}
		int numToPad = totalLength - mSize;

		char* result = new char[totalLength + 1];
		mSize = totalLength;
		char* resultPtr = result;
		for (int i = 0; i < numToPad; i++)
		{
			*resultPtr = c;
			resultPtr++;
		}

		char* ptrM = mString;
		while (*ptrM != 0)
		{
			*resultPtr = *ptrM;
			ptrM++;
			resultPtr++;
		}
		*resultPtr = 0;

		delete[] mString;
		mString = result;
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		if (totalLength <= mSize)
		{
			return;
		}
		int numToPad = totalLength - mSize;
		char* result = new char[totalLength + 1];
		mSize = totalLength;
		char* resultPtr = result;
		char* ptrM = mString;

		while (*ptrM != 0)
		{
			*resultPtr = *ptrM;
			ptrM++;
			resultPtr++;
		}

		for (int i = 0; i < numToPad; i++)
		{
			*resultPtr = ' ';
			resultPtr++;
		}
		*resultPtr = 0;

		delete[] mString;
		mString = result;

	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		if (totalLength <= mSize)
		{
			return;
		}
		int numToPad = totalLength - mSize;
		char* result = new char[totalLength + 1];
		mSize = totalLength;
		char* resultPtr = result;
		char* ptrM = mString;

		while (*ptrM != 0)
		{
			*resultPtr = *ptrM;
			ptrM++;
			resultPtr++;
		}

		for (int i = 0; i < numToPad; i++)
		{
			*resultPtr = c;
			resultPtr++;
		}
		*resultPtr = 0;

		delete[] mString;
		mString = result;
	}

	void MyString::Reverse()
	{
		char* ptr = mString;
		char tmp;

		for (size_t i = 0; i < mSize / 2; i++)
		{
			tmp = ptr[i];
			ptr[i] = ptr[mSize - 1 - i];
			ptr[mSize - 1 - i] = tmp;
		}
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
		char* ptr = mString;
		while (*ptr != 0)
		{
			if (65 <= *ptr && *ptr <= 90)
			{
				*ptr += 32;
			}
			ptr++;
		}

	}

	void MyString::ToUpper()
	{
		char* ptr = mString;
		while (*ptr != 0)
		{
			if (97 <= *ptr && *ptr <= 122)
			{
				*ptr -= 32;
			}
			ptr++;
		}
	}

	int MyString::myStrlen(const char* s)
	{
		if (s == nullptr) 
		{
			return 0;
		}
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
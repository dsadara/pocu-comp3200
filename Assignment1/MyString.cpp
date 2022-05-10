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
		delete[] mString;   // ������ �� �迭�� ���������Ƿ� �迭ǥ��[]�� �־���
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
		delete[] mString;   // ���� mString �޸� ����
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

		char const* ptr1 = mString; // char���� �����Ű�� ���ϰ� �ϱ� ���� const ����
		char const* ptr2 = s;
		int index = -1;
		bool bFirstChar = false;
		
		for (size_t i = 0; i <= mSize; i++)	// iterate mString once
		{
			if (ptr1[i] == *ptr2)
			{
				// ù���� ���� �÷��� ��, ���� ���� 
				if (!bFirstChar)
				{
					bFirstChar = true;
					index = i;
				}
				ptr2++;
				// �� ������(�ι��ڿ� ����������) ù���� ���� ��ġ ��ȯ
				if (*ptr2 == 0)
				{
					return index;
				}
			}
			else 
			{
				// �񱳿� �������� �� �÷��׿� ������ �ʱ�ȭ
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

		char const* ptr1 = mString; // char���� �����Ű�� ���ϰ� �ϱ� ���� const ����
		char const* ptr2 = s;
		int index = -1;
		int lastIndex = -1;
		bool bFirstChar = false;

		for (size_t i = 0; i <= mSize; i++)	// iterate mString once
		{
			if (ptr1[i] == *ptr2)
			{
				// ù���� ���� �÷��� ��, ���� ���� 
				if (!bFirstChar)
				{
					bFirstChar = true;
					index = i;
				}
				ptr2++;
				// �� ������(�ι��ڿ� ����������) lastIndex�� ù��° ���� �ε��� ����, �÷��׿� ������ �ʱ�ȭ
				if (*ptr2 == 0)
				{
					lastIndex = index;
					bFirstChar = false;
					ptr2 = s;
				}
			}
			else
			{
				// �񱳿� �������� �� �÷��׿� ������ �ʱ�ȭ
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

		// ���� ��Ʈ�� ����ֱ�	
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
		// size ������ �ٸ��� early return
		if (mSize != rhs.GetLength())
			return false;

		const char* ptrR = mString;
		const char* ptrL = rhs.GetCString();

		while (*ptrR != 0 && *ptrL != 0)	// �� �������� �ϳ� �Ǵ� ���� null���ڿ� �����ϸ� �ݺ��� Ż��
		{
			if (*ptrR != *ptrL)
				return false;
			ptrR++;
			ptrL++;
		}

		// �����Ϳ� ���� ���ڿ��� ���������� ���� �����Ƿ� false ��ȯ (��� �̰� ��� �ɵ��ѵ�)
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
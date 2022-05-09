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
		int sSize = myStrlen(s);
		char* result = new char[mSize + sSize + 1];
		//memcpy(result, mString, mSize + 1);
		myMemcpy(result, mString, mSize + 1);
		delete[] mString;   // ���� mString �޸� ����
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
		char const* ptr1 = mString; // char���� �����Ű�� ���ϰ� �ϱ� ���� const ����
		char const* ptr2 = s;
		int index = -1;
		bool isFirstChar = false;
		
		for (int i = 0; i <= mSize; i++)	// iterate mString once
		{
			if (ptr1[i] == *ptr2)
			{
				// ù���� ���� �÷��� ��, ���� ���� 
				if (!isFirstChar)
				{
					isFirstChar = true;
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
		char const* ptr1 = mString; // char���� �����Ű�� ���ϰ� �ϱ� ���� const ����
		char const* ptr2 = s;
		int index = -1;
		int lastIndex = -1;
		bool isFirstChar = false;

		for (int i = 0; i <= mSize; i++)	// iterate mString once
		{
			if (ptr1[i] == *ptr2)
			{
				// ù���� ���� �÷��� ��, ���� ���� 
				if (!isFirstChar)
				{
					isFirstChar = true;
					index = i;
				}
				ptr2++;
				// �� ������(�ι��ڿ� ����������) lastIndex�� ù��° ���� �ε��� ����, �÷��׿� ������ �ʱ�ȭ
				if (*ptr2 == 0)
				{
					lastIndex = index;
					isFirstChar = false;
					ptr2 = s;
				}
			}
			else
			{
				// �񱳿� �������� �� �÷��׿� ������ �ʱ�ȭ
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
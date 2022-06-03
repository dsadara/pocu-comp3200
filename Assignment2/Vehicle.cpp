#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxPassengersCount(maxPassengersCount)
		, mCurrIndexOfPerson(0)
	{
		mPeople = new const Person * [maxPassengersCount];
	}

	Vehicle::~Vehicle()
	{
		for (size_t i = 0; i < mCurrIndexOfPerson; i++)
		{
			delete mPeople[i];
		}
		delete[] mPeople;
	}

	Vehicle::Vehicle(const Vehicle& other)
		: mMaxPassengersCount(other.mMaxPassengersCount)
		, mCurrIndexOfPerson(0)
	{
		mPeople = new const Person * [other.mMaxPassengersCount];

		for (size_t i = 0; i < other.mCurrIndexOfPerson; i++)
		{
			AddPassenger(new Person(*other.mPeople[i]));		// ��������ڿ� �̷��� �Ű������� �־ �� �۵��ϳ�?
		}


		// �� �ڽ��� �����ϴ� ��쵵 ���� -> �̰Ŵ� ���� �����ڿ��� ����

	}

	void Vehicle::operator=(const Vehicle& rhs)
	{
		size_t tmpCurrIndexOfPerson = mCurrIndexOfPerson;
		size_t tmpMaxPassengersCount = mMaxPassengersCount;
		size_t tmpRhsCurrIndexOfPerson = rhs.mCurrIndexOfPerson;
		const Person** tmpPeople = new const Person * [tmpCurrIndexOfPerson];
		mMaxPassengersCount = rhs.mMaxPassengersCount;
		mCurrIndexOfPerson = 0;

		// �� �ڽ� ���� ����
		for (size_t i = 0; i < tmpCurrIndexOfPerson; i++)
		{
			tmpPeople[i] = mPeople[i];
		}

		// ����
		for (size_t i = 0; i < tmpRhsCurrIndexOfPerson; i++)
		{
			AddPassenger(new Person(*rhs.mPeople[i]));
		}


		// ���� �޸� ���� 
		for (size_t i = 0; i < tmpCurrIndexOfPerson; i++)
		{
			delete tmpPeople[i];
		}
		delete[] tmpPeople;

	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mCurrIndexOfPerson >= mMaxPassengersCount)
		{
			return false;
		}

		mPeople[mCurrIndexOfPerson++] = person;
		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i >= mCurrIndexOfPerson)
		{
			return false;
		}

		delete mPeople[i];

		for (size_t j = i; j < mCurrIndexOfPerson - 1; j++)
		{
			mPeople[j] = mPeople[j + 1];
		}
		mCurrIndexOfPerson--;
		return true;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mCurrIndexOfPerson;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i >= mCurrIndexOfPerson)
		{
			return nullptr;
		}
		return mPeople[i];
	}

	unsigned int Vehicle::GetPassengersWeightSum() const
	{
		unsigned int passengerCount = GetPassengersCount();
		unsigned int weightSum = 0;

		for (unsigned int i = 0; i < passengerCount; i++)
		{
			weightSum += GetPassenger(i)->GetWeight();
		}

		return weightSum;
	}
}
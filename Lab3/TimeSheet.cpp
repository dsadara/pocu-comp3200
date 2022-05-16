#include "TimeSheet.h"

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		: mMaxEntries(maxEntries)
	{
		mName = name;
		mWorkTimes = new int[mMaxEntries];
		for (size_t i = 0; i < mMaxEntries; i++)
		{
			mWorkTimes[i] = 0;
		}
		mWorkTimesIndex = 0;

	}

	TimeSheet::TimeSheet(TimeSheet& other)
		: mMaxEntries(other.mMaxEntries)
		, mWorkTimesIndex(other.mWorkTimesIndex)
	{
		mName = other.mName;
		mWorkTimes = new int[mMaxEntries];
		for (size_t i = 0; i < mWorkTimesIndex; i++)
		{
			mWorkTimes[i] = other.mWorkTimes[i];
		}
	}

	void TimeSheet::operator=(const TimeSheet& rhs)
	{
		mName = rhs.mName;
		mMaxEntries = rhs.mMaxEntries;
		int* tmp = rhs.mWorkTimes;  // 자기 자신을 대입하는 경우 원래 배열 포인터를 잃지 않기 위해 저장
		mWorkTimes = new int[mMaxEntries];
		mWorkTimesIndex = rhs.mWorkTimesIndex;
		for (size_t i = 0; i < mWorkTimesIndex; i++)
		{
			mWorkTimes[i] = tmp[i];
		}
		//delete tmp;
	}

	TimeSheet::~TimeSheet()
	{
		delete mWorkTimes;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours < 1 || 10 < timeInHours)
		{
			return;
		}
		if (mWorkTimesIndex > mMaxEntries - 1)
		{
			return;
		}
		mWorkTimes[mWorkTimesIndex++] = timeInHours;
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index >= mMaxEntries)
		{
			return -1;
		}
		int time = mWorkTimes[index];
		if (time == 0)
		{
			return -1;
		}

		return time;
	}

	int TimeSheet::GetTotalTime() const
	{
		int sum = 0;
		for (size_t i = 0; i < mWorkTimesIndex; i++)
		{
			sum += mWorkTimes[i];
		}

		return sum;
	}

	float TimeSheet::GetAverageTime() const
	{
		int totalTime = GetTotalTime();


		return static_cast<float>(totalTime) / mWorkTimesIndex;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		int sum = 0;
		int squaredSum = 0;
		for (size_t i = 0; i < mWorkTimesIndex; i++)
		{
			squaredSum += mWorkTimes[i] * mWorkTimes[i];
			sum += mWorkTimes[i];
		}
		float average = static_cast<float>(sum) / mWorkTimesIndex;
		float squaredAverage = static_cast<float>(squaredSum) / mWorkTimesIndex;


		return sqrtf(squaredAverage - average * average);
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}
}
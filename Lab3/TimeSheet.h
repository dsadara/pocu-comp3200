#pragma once
#include <string>
#include <math.h>

namespace lab3
{
	class TimeSheet
	{
	public:
		TimeSheet(const char* name, unsigned int maxEntries);
		TimeSheet(TimeSheet& other);
		void operator=(const TimeSheet& rhs);
		~TimeSheet();
		void AddTime(int timeInHours);
		int GetTimeEntry(unsigned int index) const;
		int GetTotalTime() const;
		float GetAverageTime() const;
		float GetStandardDeviation() const;
		const std::string& GetName() const;

	private:
		unsigned int mMaxEntries;
		int* mWorkTimes;
		unsigned int mWorkTimesIndex;
		std::string mName;
		// 필요에 따라 private 변수와 메서드를 추가하세요.
	};
}
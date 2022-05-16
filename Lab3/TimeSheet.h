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
		// �ʿ信 ���� private ������ �޼��带 �߰��ϼ���.
	};
}
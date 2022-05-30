#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
		, mTrailer(nullptr)
		, isTrailerConnected(false)
	{
	}

	Sedan::~Sedan()
	{
		if (isTrailerConnected)
		{
			delete mTrailer;
		}
	}

	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int x = mTrailer->GetWeight() + GetPassengersWeightSum();

		if (x <= 80)
		{
			return 480;
		}
		else if (x <= 160)
		{
			return 458;
		}
		else if (x <= 260)
		{
			return 400;
		}
		else if (x <= 350)
		{
			return 380;
		}
		else
		{
			return 300;
		}
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (isTrailerConnected || trailer == nullptr)
		{
			return false;
		}

		mTrailer = trailer;
		isTrailerConnected = true;
		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (!isTrailerConnected)
		{
			return false;
		}

		delete mTrailer;
		isTrailerConnected = false;

		return true;
	}
}
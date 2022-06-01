#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
		, mTrailer(nullptr)
		, mIsTrailerConnected(false)
	{
	}

	Sedan::~Sedan()
	{
		if (mIsTrailerConnected)
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
		if (mIsTrailerConnected || trailer == nullptr)
		{
			return false;
		}

		mTrailer = trailer;
		mIsTrailerConnected = true;
		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (!mIsTrailerConnected)
		{
			return false;
		}

		delete mTrailer;
		mIsTrailerConnected = false;

		return true;
	}

	const char* Sedan::GetVehicleType() const
	{
		return "Sedan";
	}
}
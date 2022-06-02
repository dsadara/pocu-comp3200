#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
		, mTrailer(nullptr)
		, misTrailerConnected(false)
	{
	}

	Sedan::~Sedan()
	{
		if (misTrailerConnected)
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
		if (misTrailerConnected || trailer == nullptr)
		{
			return false;
		}

		mTrailer = trailer;
		misTrailerConnected = true;
		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (!misTrailerConnected)
		{
			return false;
		}

		delete mTrailer;
		misTrailerConnected = false;

		return true;
	}

	const char* Sedan::GetVehicleType() const
	{
		return "Sedan";
	}
}
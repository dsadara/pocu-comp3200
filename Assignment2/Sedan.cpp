#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
		, mTrailer(nullptr)
		, mbTrailerConnected(false)
	{
	}

	Sedan::~Sedan()
	{
		if (mbTrailerConnected)
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
		unsigned int x;
		if (mbTrailerConnected)
		{
			x = mTrailer->GetWeight() + GetPassengersWeightSum();
		}
		else
		{
			x = GetPassengersWeightSum();
		}
		

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
		if (mbTrailerConnected || trailer == nullptr)
		{
			return false;
		}

		mTrailer = trailer;
		mbTrailerConnected = true;
		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (!mbTrailerConnected)
		{
			return false;
		}

		delete mTrailer;
		mbTrailerConnected = false;

		return true;
	}

	char Sedan::GetVehicleType() const
	{
		return 'S';
	}

	bool Sedan::IsTrailerConnected() const
	{
		if (mbTrailerConnected)
		{
			return true;
		}
		return false;
	}

	void Sedan::operator=(const Sedan& rhs)
	{
		if (this == &rhs)
		{
			return;
		}
		Vehicle::operator=(rhs);
		if (rhs.IsTrailerConnected())
		{
			delete mTrailer;
			mTrailer = new Trailer(rhs.mTrailer->GetWeight());
		}
		else
		{
			delete mTrailer;
		}
	}
}
#pragma once
#include "Vehicle.h"
#include "IDrivable.h"
#include "Trailer.h"

namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable
	{
	public:
		Sedan();
		~Sedan();
		unsigned int GetMaxSpeed() const;
		unsigned int GetDriveSpeed() const;
		const char* GetVehicleType() const = 0;
		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();
	private:
		const Trailer* mTrailer;
		bool isTrailerConnected;
	};
}
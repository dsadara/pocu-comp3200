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
		Sedan(const Sedan& other);
		//Sedan(const Sedan& other);
		void operator=(const Sedan& rhs);
		unsigned int GetMaxSpeed() const;
		unsigned int GetDriveSpeed() const;
		bool IsTrailerConnected() const;
		char GetVehicleType() const;
		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();
	private:
		const Trailer* mTrailer;
		bool mbTrailerConnected;
	};
}
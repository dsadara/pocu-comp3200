#pragma once
#include "Vehicle.h"

namespace assignment2
{
	class Trailer : public Vehicle	// trailerµµ vehicle »ó¼Ó?
	{
	public:
		Trailer(unsigned int weight);
		~Trailer();
		unsigned int GetMaxSpeed() const;
		unsigned int GetWeight() const;
	private:
		unsigned int mWeight;
	};
}
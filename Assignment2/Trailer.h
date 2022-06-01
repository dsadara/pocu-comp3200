#pragma once
#include "Vehicle.h"

namespace assignment2
{
	class Trailer : public Vehicle	// trailer�� vehicle ���?
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
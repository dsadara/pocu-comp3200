#pragma once

#include "Lawn.h"
#include "IFenceable.h"
#include "eGrassType.h"
#include "eFenceType.h"
#include <cmath>

namespace lab5
{
	class EquilateralTriangleLawn : public Lawn, public IFenceable
	{
	public:
		EquilateralTriangleLawn(unsigned int side);
		virtual ~EquilateralTriangleLawn();
		unsigned int GetArea() const;
		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
		unsigned int GetPerimeter() const;
	private:
		unsigned int mSide;
	};

}

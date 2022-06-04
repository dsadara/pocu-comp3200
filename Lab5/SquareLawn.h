#pragma once

#include "RectangleLawn.h"
#include "IFenceable.h"
#include "eGrassType.h"
#include "eFenceType.h"

namespace lab5
{
	class SquareLawn : public RectangleLawn
	{
	public:
		SquareLawn(unsigned int width);
		unsigned int GetArea() const;
		virtual ~SquareLawn();
		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
		unsigned int GetPerimeter() const;
	};
}

#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::GetInstance()
	{
		static DeusExMachina* deus = new DeusExMachina();
		deus->currVehiclesIndex = 0;
		return deus;
	}

	void DeusExMachina::Travel() const
	{
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (currVehiclesIndex >= 10)
		{
			return false;
		}
		Vehicles[currVehiclesIndex++] = vehicle;
		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i >= currVehiclesIndex)
		{
			return false;
		}

		delete Vehicles[i];
		for (int j = i; j < currVehiclesIndex - 1; j++)
		{
			Vehicles[j] = Vehicles[j + 1];
		}

		currVehiclesIndex--;

		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		return NULL;
	}
}
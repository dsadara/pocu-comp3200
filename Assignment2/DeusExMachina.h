#pragma once
#include "Vehicle.h"

namespace assignment2
{
	class DeusExMachina
	{
	public:
		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;
	private:
		Vehicle* Vehicles[10];
		int currVehiclesIndex;
		DeusExMachina() = default;
		// ���翬���� ���Կ����� ����
		DeusExMachina(const DeusExMachina&) = delete;
		DeusExMachina(DeusExMachina&&) = delete;
		DeusExMachina& operator=(const DeusExMachina&) = delete;
		DeusExMachina& operator=(DeusExMachina&&) = delete;
	};
}
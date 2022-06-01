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
		Vehicle* mVehicles[10];
		unsigned int mCurrVehiclesIndex;
		int mRemainRestTimes[10];
		int mTravelDistance[10];
		//DeusExMachina() = default;
		DeusExMachina();
		// 복사연산자 대입연산자 삭제
		DeusExMachina(const DeusExMachina&) = delete;
		DeusExMachina(DeusExMachina&&) = delete;
		DeusExMachina& operator=(const DeusExMachina&) = delete;
		DeusExMachina& operator=(DeusExMachina&&) = delete;
	};
}
#include <cassert>
#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "Trailer.h"
#include "UBoat.h"
#include "DeusExMachina.h"
#include "Person.h"

using namespace assignment2;

void SpecTestcase();

int main()
{
	Person p("Bob", 85);	// "Bob"은 어떻게 될까? 상수 문자열이니까 신경 안써도 되는건가? 
	p.GetName(); // "Bob"
	p.GetWeight(); // 85

	// Vehicle::AddPassenger() 메서드 구현하기

	Person* p1 = new Person("Bob", 85);
	Person* p2 = new Person("James", 75);
	Person* p3 = new Person("Tina", 50);

	Airplane* a = new Airplane(2);
	assert(a->AddPassenger(p1)); // true
	assert(a->AddPassenger(p2)); // true
	assert(!a->AddPassenger(p3)); // false

	assert(a->GetPassenger(0)->GetWeight() == 85);
	assert(a->GetPassenger(1)->GetWeight() == 75);

	delete a; // 이 코드는 p와 p2도 소멸시킵니다. p3는 소멸되지 않습니다.

	// Vehicle::RemovePassenger() 메서드 구현하기

	Person* p4 = new Person("Bob", 85);
	Person* p5 = new Person("James", 75);
	Person* p6 = new Person("Tina", 50);

	Airplane b(5);
	b.AddPassenger(p4);
	b.AddPassenger(p5);
	b.AddPassenger(p6);

	assert(b.RemovePassenger(1)); // true. 더불어, Airplane 'a'에서 p2가 제거됨 
	assert(!b.RemovePassenger(4)); // false
	assert(!b.RemovePassenger(2)); // false

	assert(b.GetPassenger(0)->GetWeight() == 85);
	assert(b.GetPassenger(1)->GetWeight() == 50);

	// Vehicle::GetPassenger() 메서드 구현하기

	Person* p7 = new Person("Bob", 85);
	Person* p8 = new Person("James", 75);
	Person* p9 = new Person("Tina", 50);

	Airplane c(5);
	c.AddPassenger(p7);
	c.AddPassenger(p8);
	c.AddPassenger(p9);

	assert(c.GetPassenger(1) == p8); // p2를 가리키는 포인터 반환
	assert(c.GetPassenger(4) == nullptr); // NULL 반환

	// Vehicle::GetPassengersCount() 메서드 구현하기

	Person* p10 = new Person("Bob", 85);
	Person* p11 = new Person("James", 75);
	Person* p12 = new Person("Tina", 50);

	Airplane d(5);
	d.AddPassenger(p10);
	d.AddPassenger(p11);

	assert(d.GetPassengersCount() == 2); // 2 반환

	d.AddPassenger(p12);

	assert(d.GetPassengersCount() == 3); // 3 반환

	// Vehicle::GetMaxPassengersCount() 메서드 구현하기

	Person* p13 = new Person("Bob", 85);
	Person* p14 = new Person("James", 75);
	Person* p15 = new Person("Tina", 50);

	Airplane e(10);
	e.AddPassenger(p13);
	e.AddPassenger(p14);

	assert(e.GetMaxPassengersCount() == 10); // 10 반환

	e.AddPassenger(p15);

	assert(e.GetMaxPassengersCount() == 10); // 10 반환

	// Vehicle::GetMaxSpeed() 메서드 구현하기

	Person* p16 = new Person("Bob", 85);
	Person* p17 = new Person("James", 75);
	Person* p18 = new Person("Tina", 52);

	Airplane f(5);
	f.AddPassenger(p16);
	f.AddPassenger(p17);
	f.AddPassenger(p18);

	assert(f.GetMaxSpeed() == 648); // 비행 속도가 도로 주행 속도보다 빠르기 때문에 648을 반환(섹션 2.4 참고)

	// Trailer::GetWeight() 메서드 구현하기

	Trailer t(40);
	assert(t.GetWeight() == 40); // 40을 반환

	// Airplane::operator+() 메서드 구현하기

	Person* p20 = new Person("Bob", 85);
	Person* p21 = new Person("James", 75);
	Person* p22 = new Person("Tina", 52);

	Person* p23 = new Person("Peter", 78);
	Person* p24 = new Person("Jane", 48);
	Person* p25 = new Person("Steve", 88);

	Airplane pl(5);
	pl.AddPassenger(p20);
	pl.AddPassenger(p21);
	pl.AddPassenger(p22);

	Boat bt(5);
	bt.AddPassenger(p23);
	bt.AddPassenger(p24);
	bt.AddPassenger(p25);

	Boatplane bp = pl + bt; // Airplane + Boat

	assert(bp.GetPassengersCount() == 6); // 6을 반환
	assert(bp.GetMaxPassengersCount() == 10); // 10을 반환

	assert(pl.GetPassengersCount() == 0); // 0을 반환
	assert(bt.GetPassengersCount() == 0); // 0을 반환

	// Boat::operator+() 메서드 구현하기

	Person* p30 = new Person("Bob", 85);
	Person* p31 = new Person("James", 75);
	Person* p32 = new Person("Tina", 52);

	Person* p33 = new Person("Peter", 78);
	Person* p34 = new Person("Jane", 48);
	Person* p35 = new Person("Steve", 88);

	Airplane pl2(5);
	pl2.AddPassenger(p30);
	pl2.AddPassenger(p31);
	pl2.AddPassenger(p32);

	Boat bt2(5);
	bt2.AddPassenger(p33);
	bt2.AddPassenger(p34);
	bt2.AddPassenger(p35);

	Boatplane bp2 = bt2 + pl2; // Boat + Airplane인 것에 유의
	assert(bp2.GetPassengersCount() == 6); // 6 반환
	assert(bp2.GetMaxPassengersCount() == 10); // 10 반환

	assert(pl2.GetPassengersCount() == 0); // 0 반환
	assert(bt2.GetPassengersCount() == 0); // 0 반환

	SpecTestcase();

	DeusExMachina* deusExMachina1 = DeusExMachina::GetInstance();
	DeusExMachina* deusExMachina2 = DeusExMachina::GetInstance();

	bool bSame = deusExMachina1 == deusExMachina2; // true
	assert(bSame);

	return 0;
}

void SpecTestcase()
{
	Person* p = new Person("Bob", 85);

	assert(p->GetName() == std::string("Bob"));
	assert(p->GetWeight() == 85);

	Person* p2 = new Person("James", 75);
	Person* p3 = new Person("Tina", 52);

	Person* p4 = new Person("Peter", 78);
	Person* p5 = new Person("Jane", 48);
	Person* p6 = new Person("Steve", 88);

	Airplane a(5);
	a.AddPassenger(p);
	a.AddPassenger(p2);
	a.AddPassenger(p3);

	assert(a.GetMaxPassengersCount() == 5);
	assert(a.GetPassengersCount() == 3);
	assert(a.GetPassenger(1) == p2);
	assert(a.GetFlySpeed() == 648);
	assert(a.GetDriveSpeed() == 59);
	assert(a.GetMaxSpeed() == 648);

	Boat b(5);
	b.AddPassenger(p4);
	b.AddPassenger(p5);
	b.AddPassenger(p6);

	Boatplane bp = a + b;

	assert(bp.GetPassengersCount() == 6);
	assert(bp.GetMaxPassengersCount() == 10);

	assert(a.GetPassengersCount() == 0);
	assert(b.GetPassengersCount() == 0);

	DeusExMachina* deusExMachina1 = DeusExMachina::GetInstance();
	DeusExMachina* deusExMachina2 = DeusExMachina::GetInstance();

	bool bSame = deusExMachina1 == deusExMachina2;
	assert(bSame);

	Airplane* airplane = new Airplane(5);
	Boat* boat = new Boat(5);
	Boatplane* boatplane = new Boatplane(5);
	Motorcycle* motorcycle = new Motorcycle();
	Sedan* sedan = new Sedan();
	Sedan* sedan2 = new Sedan();
	UBoat* uboat = new UBoat();

	bool bAdded = sedan2->AddTrailer(new Trailer(50));
	assert(bAdded);

	bAdded = sedan2->AddTrailer(new Trailer(60));
	assert(!bAdded);

	bAdded = deusExMachina1->AddVehicle(airplane);
	assert(bAdded);

	deusExMachina1->AddVehicle(boat);
	deusExMachina1->AddVehicle(boatplane);
	deusExMachina1->AddVehicle(motorcycle);
	deusExMachina1->AddVehicle(sedan);
	deusExMachina1->AddVehicle(sedan2);
	deusExMachina1->AddVehicle(uboat);
	deusExMachina1->AddVehicle(new Airplane(5));
	deusExMachina1->AddVehicle(new Airplane(5));
	deusExMachina1->AddVehicle(new Airplane(5));

	bAdded = deusExMachina1->AddVehicle(new Airplane(5));

	assert(!bAdded);

	deusExMachina1->RemoveVehicle(9);
	deusExMachina1->RemoveVehicle(8);
	bool bRemoved = deusExMachina1->RemoveVehicle(7);
	assert(bRemoved);

	bRemoved = deusExMachina1->RemoveVehicle(9);
	assert(!bRemoved);

	//deusExMachina1->Travel(); // 모든 운송 수단이 이동
	//deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan, UBoat가 이동
	//deusExMachina1->Travel(); // Motorcycle, 두 Sedan이 이동
	//deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	//deusExMachina1->Travel(); // UBoat만 빼고 전부 이동
	//deusExMachina1->Travel(); // 어떤 운송 수단도 움직이지 않음
	//deusExMachina1->Travel(); // Boat, Motorcycle, 트레일러 안 달린 Sedan, UBoat가 이동
	//deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan, UBoat가 이동
	//deusExMachina1->Travel(); // Airplane, Boatplane, Motorcycle, 두 Sedan이 이동
	//deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	//deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	//deusExMachina1->Travel(); // 트레일러 달린 Sedan만 이동

	//assert(deusExMachina1->GetFurthestTravelled() == boat);

}
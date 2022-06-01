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
	Person p("Bob", 85);	// "Bob"�� ��� �ɱ�? ��� ���ڿ��̴ϱ� �Ű� �Ƚᵵ �Ǵ°ǰ�? 
	p.GetName(); // "Bob"
	p.GetWeight(); // 85

	// Vehicle::AddPassenger() �޼��� �����ϱ�

	Person* p1 = new Person("Bob", 85);
	Person* p2 = new Person("James", 75);
	Person* p3 = new Person("Tina", 50);

	Airplane* a = new Airplane(2);
	assert(a->AddPassenger(p1)); // true
	assert(a->AddPassenger(p2)); // true
	assert(!a->AddPassenger(p3)); // false

	assert(a->GetPassenger(0)->GetWeight() == 85);
	assert(a->GetPassenger(1)->GetWeight() == 75);

	delete a; // �� �ڵ�� p�� p2�� �Ҹ��ŵ�ϴ�. p3�� �Ҹ���� �ʽ��ϴ�.

	// Vehicle::RemovePassenger() �޼��� �����ϱ�

	Person* p4 = new Person("Bob", 85);
	Person* p5 = new Person("James", 75);
	Person* p6 = new Person("Tina", 50);

	Airplane b(5);
	b.AddPassenger(p4);
	b.AddPassenger(p5);
	b.AddPassenger(p6);

	assert(b.RemovePassenger(1)); // true. ���Ҿ�, Airplane 'a'���� p2�� ���ŵ� 
	assert(!b.RemovePassenger(4)); // false
	assert(!b.RemovePassenger(2)); // false

	assert(b.GetPassenger(0)->GetWeight() == 85);
	assert(b.GetPassenger(1)->GetWeight() == 50);

	// Vehicle::GetPassenger() �޼��� �����ϱ�

	Person* p7 = new Person("Bob", 85);
	Person* p8 = new Person("James", 75);
	Person* p9 = new Person("Tina", 50);

	Airplane c(5);
	c.AddPassenger(p7);
	c.AddPassenger(p8);
	c.AddPassenger(p9);

	assert(c.GetPassenger(1) == p8); // p2�� ����Ű�� ������ ��ȯ
	assert(c.GetPassenger(4) == nullptr); // NULL ��ȯ

	// Vehicle::GetPassengersCount() �޼��� �����ϱ�

	Person* p10 = new Person("Bob", 85);
	Person* p11 = new Person("James", 75);
	Person* p12 = new Person("Tina", 50);

	Airplane d(5);
	d.AddPassenger(p10);
	d.AddPassenger(p11);

	assert(d.GetPassengersCount() == 2); // 2 ��ȯ

	d.AddPassenger(p12);

	assert(d.GetPassengersCount() == 3); // 3 ��ȯ

	// Vehicle::GetMaxPassengersCount() �޼��� �����ϱ�

	Person* p13 = new Person("Bob", 85);
	Person* p14 = new Person("James", 75);
	Person* p15 = new Person("Tina", 50);

	Airplane e(10);
	e.AddPassenger(p13);
	e.AddPassenger(p14);

	assert(e.GetMaxPassengersCount() == 10); // 10 ��ȯ

	e.AddPassenger(p15);

	assert(e.GetMaxPassengersCount() == 10); // 10 ��ȯ

	// Vehicle::GetMaxSpeed() �޼��� �����ϱ�

	Person* p16 = new Person("Bob", 85);
	Person* p17 = new Person("James", 75);
	Person* p18 = new Person("Tina", 52);

	Airplane f(5);
	f.AddPassenger(p16);
	f.AddPassenger(p17);
	f.AddPassenger(p18);

	assert(f.GetMaxSpeed() == 648); // ���� �ӵ��� ���� ���� �ӵ����� ������ ������ 648�� ��ȯ(���� 2.4 ����)

	// Trailer::GetWeight() �޼��� �����ϱ�

	Trailer t(40);
	assert(t.GetWeight() == 40); // 40�� ��ȯ

	// Airplane::operator+() �޼��� �����ϱ�

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

	assert(bp.GetPassengersCount() == 6); // 6�� ��ȯ
	assert(bp.GetMaxPassengersCount() == 10); // 10�� ��ȯ

	assert(pl.GetPassengersCount() == 0); // 0�� ��ȯ
	assert(bt.GetPassengersCount() == 0); // 0�� ��ȯ

	// Boat::operator+() �޼��� �����ϱ�

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

	Boatplane bp2 = bt2 + pl2; // Boat + Airplane�� �Ϳ� ����
	assert(bp2.GetPassengersCount() == 6); // 6 ��ȯ
	assert(bp2.GetMaxPassengersCount() == 10); // 10 ��ȯ

	assert(pl2.GetPassengersCount() == 0); // 0 ��ȯ
	assert(bt2.GetPassengersCount() == 0); // 0 ��ȯ

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

	//deusExMachina1->Travel(); // ��� ��� ������ �̵�
	//deusExMachina1->Travel(); // Boat, Motorcycle, �� Sedan, UBoat�� �̵�
	//deusExMachina1->Travel(); // Motorcycle, �� Sedan�� �̵�
	//deusExMachina1->Travel(); // Boat, Motorcycle, �� Sedan�� �̵�
	//deusExMachina1->Travel(); // UBoat�� ���� ���� �̵�
	//deusExMachina1->Travel(); // � ��� ���ܵ� �������� ����
	//deusExMachina1->Travel(); // Boat, Motorcycle, Ʈ���Ϸ� �� �޸� Sedan, UBoat�� �̵�
	//deusExMachina1->Travel(); // Boat, Motorcycle, �� Sedan, UBoat�� �̵�
	//deusExMachina1->Travel(); // Airplane, Boatplane, Motorcycle, �� Sedan�� �̵�
	//deusExMachina1->Travel(); // Boat, Motorcycle, �� Sedan�� �̵�
	//deusExMachina1->Travel(); // Boat, Motorcycle, �� Sedan�� �̵�
	//deusExMachina1->Travel(); // Ʈ���Ϸ� �޸� Sedan�� �̵�

	//assert(deusExMachina1->GetFurthestTravelled() == boat);

}
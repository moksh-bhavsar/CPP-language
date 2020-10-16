//Based on ch14p3.cpp of the reference book

#include <iostream>
#include <string>

using namespace std;

class Person
{
  public:
    
    Person();

    Person(const Person&);
    Person& operator=(const Person& rhs);
    Person(string);
    Person(const char* aName);

    string getName() const;

    friend istream& operator>> (istream& is, Person& p );
    friend ostream& operator<< (ostream& os, const Person& p);

  private:
    string name;
};


class Vehicle
{
  public:
    Vehicle();
    Vehicle(string mfgr, int noCyl, const Person& owner); // manufacture, no of cylinder, owner

    Vehicle(const Vehicle& rhs);
    Vehicle& operator=(const Vehicle& rhs);

    string getMfgrName();
    int getNumberCyl();
    Person getOwner();

  private:
    string mfgrName;
    int numberCyl;
    Person vehicleOwner;  // NOTE: using other class objects
};


class Truck : public Vehicle
{
  public:
    Truck();

    Truck (double maxLoad, int maxTow,
           string mfgr,    int noCyl,
                           const Person& owner);

    Truck(const Truck& rhs);
    Truck& operator=(const Truck& rhs);

    double getLoadCapacity();
    int getTowingCapacity();
      
  private:
    double loadCapacity; // tons
    int towingCapacity;  // pounds
};

//------------------------ Person Implementation

Person::Person() : name("")
{
}

Person::Person(string aName) : name(aName)
{
}

Person::Person(const char* aName) : name(aName)
{
}

Person::Person(const Person & theName): name(theName.name)
{  
}

Person & Person::operator=(const Person& rhs) // it is not necessary, as there is no dynamic memory allocation!
{
  this->name = rhs.name; //string assignment is well behaved
  return *this;
}

string Person::getName() const
{
  return name;
}

istream& operator>>(istream& is, Person& p )
{
  is >> p.name;
  return is;
}

ostream& operator<< (ostream& os, const Person& p)
{
  os << p.name;
  return os;
}

//---------------------------------  Vehicle implementation
Vehicle::Vehicle(): mfgrName(""), numberCyl(0)
{
	this->vehicleOwner = Person();
}
Vehicle::Vehicle(string mfgr, int noCyl, const Person& owner): mfgrName(mfgr), numberCyl(noCyl), vehicleOwner(owner)
{
}

Vehicle::Vehicle(const Vehicle& rhs){
	
	this->mfgrName = rhs.mfgrName;
	this->numberCyl = rhs.numberCyl;
	this->vehicleOwner = rhs.vehicleOwner;
}

Vehicle& Vehicle::operator=(const Vehicle& rhs){
	this->mfgrName = rhs.mfgrName;
	this->numberCyl = rhs.numberCyl;
	this->vehicleOwner = rhs.vehicleOwner;
	return *this;
}

string Vehicle::getMfgrName() {return mfgrName; }
int Vehicle::getNumberCyl() { return numberCyl; }
Person Vehicle::getOwner() { return vehicleOwner; }



//---------------------------------- Truck Implementation
Truck::Truck(): loadCapacity(0), towingCapacity(0), Vehicle(){
}

Truck::Truck (double maxLoad, int maxTow, string mfgr, int noCyl, const Person& owner): loadCapacity(maxLoad), towingCapacity(maxTow), Vehicle(mfgr, noCyl, owner)
{
}

Truck::Truck(const Truck& rhs){
	this->loadCapacity = rhs.loadCapacity;
	this->towingCapacity = rhs.towingCapacity;
}
Truck& Truck::operator=(const Truck& rhs){
	
	this->loadCapacity = rhs.loadCapacity;
	this->towingCapacity = rhs.towingCapacity;
	return *this;
}

double Truck::getLoadCapacity(){
	return loadCapacity;
}

int Truck::getTowingCapacity(){
	return towingCapacity;
}



// --------------------------------- Test program (don't change it)

int main()
{
  Vehicle v1("Ford", 4, "James Carter") ;
  Vehicle v2;
  Vehicle v3(v1);
  
  v2 = v1;

  cout << "\nCar v1 (constructed) Data:\n";
  cout << v1.getMfgrName() << endl;
  cout << v1.getNumberCyl() << endl;
  cout << v1.getOwner() << endl;

  cout << "\nCar v2 (assigned) Data:\n";
  cout << v2.getMfgrName() << endl;
  cout << v2.getNumberCyl() << endl;
  cout << v2.getOwner() << endl;

  cout << "\nCar v3 (copy constructed) Data:\n";
  cout << v3.getMfgrName() << endl;
  cout << v3.getNumberCyl() << endl;
  cout << v3.getOwner() << endl;

  Truck  t1(80.0, 20000, "BMW", 8, "John Driver");  // 80 tons gross vehicle weight, 20,000 lbs tow capacity

  Truck  t3(t1), t2;
  t2 = t1;

  cout << "\nTruck T1 (constructed) data:\n";

  cout << t1.getMfgrName() << endl;
  cout << t1.getNumberCyl() << endl;
  cout << t1.getOwner() << endl;
  cout << t1.getLoadCapacity() << endl;
  cout << t1.getTowingCapacity() << endl;
           

  cout << "\nTruck T2 (assigned) data:\n";

  cout << t2.getMfgrName() << endl;
  cout << t2.getNumberCyl() << endl;
  cout << t2.getOwner() << endl;
  cout << t2.getLoadCapacity() << endl;
  cout << t2.getTowingCapacity() << endl;


  cout << "\nTruck T3 (copy constructed) data:\n";

  cout << t3.getMfgrName() << endl;
  cout << t3.getNumberCyl() << endl;
  cout << t3.getOwner() << endl;
  cout << t3.getLoadCapacity() << endl;
  cout << t3.getTowingCapacity() << endl;


  return 0;
} 
// end testing application

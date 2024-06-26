#include <iostream>
#include "animal.h"
#include "IOInterface.h"
#include "cow.h"
#include "wagyu.h"
#include "employee.h"
#include "farm.h"
#include <vector>
#include <map>
#include <string>
#include <list>
#include <set>
#include "singleton.h"
#include <ctime>
#include <cstdlib>
#include "bids.h"

using namespace std;

template<class T = Animal>
class Info {
public:
    // Description of the animal function
    template<class T> // General template
    void displayInfo(const T &obj) {
        cout<<"\n Animals are great! \n";
    }
    template<> // Specialization for Cow
    void displayInfo(const Cow &obj) {
        cout << "\n Animal description(Normal Cow): ";
        cout << "\n Cow, in common parlance, a domestic bovine, regardless of sex and age, \n usually of the species Bos taurus. In precise usage, the name is given\n to mature females of several large mammals, including cattle (bovines), moose, \n elephants, sea lions, and whales.";
        cout << "\n Price per kg: 10$\n";
    }
    template<> // Specialization for Wagyu
    void displayInfo(const Wagyu& obj) {
        cout << "\n Animal description(Wagyu Cow): ";
        cout << "\n Wagyu is a Japanese beef cattle breed � derived from native\n Asian cattle. 'Wagyu' refers to all Japanese beef cattle, where 'Wa' means \n Japanese and 'gyu' means cow. Wagyu were originally draft animals\n used in agriculture, and were selected for their physical endurance.\n This selection favored animals with more intra - muscular fat\n cells - 'marbling' - which provided a readily available energy source.\n Wagyu are naturally horned and can be either black or red in color.";
        cout << "\n Price per kg: 100$\n";
    }

    // Price of the animal function
    template<class T> // General template
    void displayPrice(const T &obj) {
        cout<< "\n Animals are priceless! \n";
    }
    template<> // Specialization for Cow
    void displayPrice(const Cow &obj) {
		cout << "\n Price for a normal cow: 10$/kg";
		cout << "\n Price for this cow: " << obj.getPrice() << "$ \n";
	}
    template<> // Specialization for Wagyu
	void displayPrice(const Wagyu &obj) {
		cout << "\n Price for a wagyu cow: 100$/kg";
		cout << "\n Price for this cow: " << obj.getPrice() << "$ \n";
	}
};


int main()
{

    set<Animal> s;
    map<string, int> foodstack;
    foodstack["Wheat"] = 100;
    foodstack["Water"] = 1000;
    Cow c1(10, 500, "Ileana", "Black", "Meat", 0);
    Animal *c=dynamic_cast<Cow*>(&c1);
    vector<Animal*> animals;
    animals.push_back(c);
    Animal *a=new Wagyu(10,500,"John","Red","Both",0, "Australian", "A5", 85);
    animals.push_back(a);
    vector<Employee> employees;
    list<string> t, t1;
    t.push_back("Clean the cows");
    t1.push_back("Feed the cows");
    Employee e1(t, "Agapie Philip", 5000);
    Employee e3(t1, "Andrei Tokacs", 7500);
    Employee e2;
    employees.push_back(e2);
    employees.push_back(e1);
    Farm f1("Eu", s, foodstack, animals, employees);
        Singleton* menu = Singleton::getInstance();
    Farm f2;
    menu->addFarm(f1);
    menu->addFarm(f2);

    menu->run();


    return 0;
}


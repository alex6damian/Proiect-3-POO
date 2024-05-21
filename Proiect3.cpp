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
        cout << "\n Wagyu is a Japanese beef cattle breed – derived from native\n Asian cattle. 'Wagyu' refers to all Japanese beef cattle, where 'Wa' means \n Japanese and 'gyu' means cow. Wagyu were originally draft animals\n used in agriculture, and were selected for their physical endurance.\n This selection favored animals with more intra - muscular fat\n cells - 'marbling' - which provided a readily available energy source.\n Wagyu are naturally horned and can be either black or red in color.";
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
    //Info<> animalInfo;
    //Cow c1(10, 500, "Ileana", "Black", "Meat", 0);
    //Wagyu w(10,500,"John","Red","Both",0, "Australian", "A5", 85);
    //Info<Wagyu> wagyuInfo;
    ////animalInfo.displayInfo(w);
    ////animalInfo.displayInfo(c1);
    //animalInfo.displayPrice(w);
    //animalInfo.displayPrice(c1);

    //Employee e1;
    //cin >> e1;
    //cout << e1;




 /*   set<Animal> s;
    map<string, int> foodstack;
    foodstack["Wheat"] = 100;
    Cow c1(10, 500, "Ileana", "Black", "Meat", 0);
    Animal *c=dynamic_cast<Cow*>(&c1);
    vector<Animal*> animals;
    animals.push_back(c);
    vector<Employee> employees;

    Farm f1("Eu", s, foodstack, animals, employees);
    cout << f1;
    f1.sellAnimal(0);
    cout << f1;*/
    /*Singleton * s1 = Singleton::getInstance();
    Singleton * s2 = Singleton::getInstance();
    cout<<s1<<endl;
    cout<<s2<<endl;*/

    Singleton *menu=Singleton::getInstance();
    Wagyu f=menu->create<Wagyu>();
    Farm f1=menu->create<Farm>();
    menu->print(f);
    menu->print(f1);
    //Wagyu w=menu->create<Wagyu>();
    //cout << w;
    return 0;
}
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include "NumberWithUnits.hpp"
using namespace std;
using namespace ariel;


int main(){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits km{1, "km"};
    cout << km << endl;
    cout << (+km) << endl;
    NumberWithUnits m{100, "m"};
    cout << "m + km = " << m+km << endl;
    cout << "km + m = " << km+m << endl;
    cout << "4*km = " << (4*km) << endl;  

    NumberWithUnits kg{100, "kg"};
    NumberWithUnits g{100, "g"};
    NumberWithUnits cm{100, "cm"};
    cout << "kg + g = " << kg + g << endl; 

    NumberWithUnits hour{100, "hour"};
    NumberWithUnits min1{40, "min"};
    NumberWithUnits min2{30, "min"};

    cout << " min1 > min2 = " << (min1 > min2) << endl; //true
    cout << " min1 <= min2 = " << (min1 <= min2) << endl;  // false
    cout << "g == 100[g] = " << (g == NumberWithUnits{100, "g"}) << endl;  // true

     istringstream input{"700 [ kg ]"};
     input >> m;
     cout << "m = " << m << endl;   
      //Error, not the same type

    try{
       cout << "cm + kg = " << cm + kg << endl; 
    }
    catch (const exception& ex){
        cout << ex.what() << endl;
    }
    try{
        cout << "hour-g = " << hour-g << endl; 
    }
    catch (const exception& ex){
        cout << ex.what() << endl;
    }




    return 0;
}
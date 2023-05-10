#include <iostream>
#include <string>

#include "classes.h"
#include "menu.h"
#include "booking.h"
#include "misc.h"
#include "users.h"

using namespace std;

int main () {
    
    cout << "\033[93m";
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "\033[0m";                      

// cout << "__  _                           " << endl;
// cout << "\\ `/ |                          " << endl;
// cout << " \\__`!                          " << endl;
// cout << " / ,' `-.__________________     " << endl;
// cout << "'-'\\_____                Ll`-.  " << endl;
// cout << "   <____()-=O=O=O=O=O=[]====--) " << endl;
// cout << "     `.___ ,-----,_______...-'  " << endl;
// cout << "          /    .'               " << endl;
// cout << "         /   .'                 " << endl;
// cout << "        /  .'                   " << endl;
// cout << "        `-'                     " << endl;
// cout << "        `-'                     " << endl;
// cout << "                            " << endl;
cout << "                            ___                       " << endl;
cout << "                            \\\\ \\                       " << endl;
cout << "                             \\\\ `\\                       " << endl;
cout << "         ___                  \\\\  \\                       " << endl;
cout << "        |    \\                \\   `\\                       " << endl;
cout << "        |_____\\                \\    \\                       " << endl;
cout << "        |______\\                \\    `\\                       " << endl;
cout << "        |       \\                \\     \\                       " << endl;
cout << "        |      __\\__---------------------------------._.          " << endl;
cout << "      __|---~~~__o_o_o_o_o_o_o_o_o_o_o_o_o_o_o_o_o_o_[][\\__          " << endl;
cout << "     |___                         /~      )                \\__          " << endl;
cout << "         ~~~---..._______________/      ,/_________________/          " << endl;
cout << "                                /      /                       " << endl;
cout << "                               /     ,/                       " << endl;
cout << "                              /     /                       " << endl;
cout << "                             /    ,/                       " << endl;
cout << "                            /    /                       " << endl;
cout << "                           //  ,/                       " << endl;
cout << "                          //  /                       " << endl;
cout << "                         // ,/                       " << endl;
cout << "                        //_/                       " << endl;

    //Bissmillahhirahmanirrahim
    //
    //Alhamdulillahirobbilalamin
    //
    //Allahumma sholli 'ala Muhammad wa 'ala ali Muhammad
    //kama sholaita 'ala Ibrahim wa 'ala ali Ibrahim
    //innaka hamidun majid
    //
    //Allahumma barik 'ala Muhammad wa 'ala ali Muhammad
    //Kama barakta 'ala Ibrahim wa 'ala ali Ibrahim
    //innaka hamidun majid
    //
    //rabbi zidni ilma
    //rabbi zidni ilma
    //rabbi zidni ilma
    //
    //Allahumma inni asaluka ilman nafi'a
    //wa rizqon thoyyibon wa 'amalan mutaqobbalan
    //
    //Ya Allah, mera Project assan 
    //kar dena, Ameen

    cout << "\033[93m";
    cout << " ╔══════════════════════════════════╗" << endl;
    cout << " ║              Welcome!            ║" << endl;
    cout << " ╚══════════════════════════════════╝" << endl;
    cout << "\033[0m";
    
    // User Database
    Passanger* passangers = NULL;
    Admin* admins = NULL;
    // Airport Database
    Airport* airports = NULL;
    // Plane Database
    Plane* planes = NULL;
    // Flight Database
    Flight* flights = NULL;


    Admin admin1("Bajwa","bajw","admi","Admin");
    Admin admin2("Khan", "khan", "man", "Manager");
    
    Passanger passanger1("Ali", "alishareef", "pass", 37406982347534, 123456,"Uganda");
    Passanger passanger2("Ahmed", "ahmedali", "passenger123#", 37406994247878, 178649, "Pakistan");
    Passanger passanger3("Umer", "umerali", "passenger123#", 37406994247234, 178049, "US");
    Passanger passanger4("Bilal", "bilalali", "pass", 37406923455878, 688949, "Pakistan");
    
    Airport airport1("Behinzir", "Rawalpindi");
	Airport airport2("Jinnah", "Karachi");
	Airport airport3("Iqbal", "Lahore");

    Airport airport4("Churchill", "London");
	Airport airport5("JF kenedy", "New York");

	Plane plane1("Boeing 111", 111);
	Plane plane2("Boeing 222", 222);
	Plane plane3("Boeing 333", 333);
	Plane plane4("Boeing 444", 444);
	Plane plane5("Boeing 555", 555);
	Plane plane6("Boeing 666", 666);
    

    passangers = addPassanger(passanger1, passangers);
    passangers = addPassanger(passanger2, passangers);
    passangers = addPassanger(passanger3, passangers);
    passangers = addPassanger(passanger4, passangers);

    cout << "Passangers and Admins added!" << endl;
    
    admins = addAdmin(admin1, admins);
    admins = addAdmin(admin2, admins);

	airport1.addPlane(plane1);
	airport1.addPlane(plane2);
	airport1.addPlane(plane3);
	airport2.addPlane(plane4);
	airport2.addPlane(plane5);
	airport3.addPlane(plane6);

	Flight flight1(111, 'L', &airport3, &airport2, &plane1, Date(10, 5, 2023));
	Flight flight2(222, 'L', &airport1, &airport2, &plane2, Date(10, 5, 2023));
	Flight flight3(333, 'L', &airport2, &airport3, &plane3, Date(11, 5, 2023));
	Flight flight4(444, 'L', &airport1, &airport3, &plane4, Date(12, 5, 2023));

	Flight flight5(555, 'I', &airport1, &airport5, &plane5, Date(9, 5, 2023));
	Flight flight6(666, 'I', &airport3, &airport4, &plane6, Date(12, 5, 2023));
	Flight flight7(777, 'I', &airport2, &airport5, &plane6, Date(14, 5, 2023));
    
    airports = addAirport(&airport1, airports);
    airports = addAirport(&airport2, airports);
    airports = addAirport(&airport3, airports);
    airports = addAirport(&airport4, airports);
    airports = addAirport(&airport5, airports);

    cout << "Airports added!" << endl;

    planes = addPlane(&plane1, planes);
    planes = addPlane(&plane2, planes);
    planes = addPlane(&plane3, planes);
    planes = addPlane(&plane4, planes);
    planes = addPlane(&plane5, planes);
    planes = addPlane(&plane6, planes);

    cout << "Planes added!" << endl;

    flights = addFlight(&flight1, flights);
    flights = addFlight(&flight2, flights);
    flights = addFlight(&flight3, flights);
    flights = addFlight(&flight4, flights);
    flights = addFlight(&flight5, flights);
    flights = addFlight(&flight6, flights);
    flights = addFlight(&flight7, flights);

    cout << "Flights added!" << endl;


	mainMenu(passangers, admins, flights, airports, planes);
    
}
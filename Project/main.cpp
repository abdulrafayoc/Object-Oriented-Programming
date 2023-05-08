#include <iostream>
#include <string>

#include "classes.h"
#include "menu.h"
// #include "module2.h"
// #include "module3.h"
// #include "menu.h"
// #include "misc.h"
// #include "users.h"

using namespace std;


Airport* addAirport(Airport* air, Airport* airports) {
        int size = airports->num;
    
        Airport* temp = new Airport[size + 1];
    
        for (int i = 0; i < size; i++) {
            temp[i] = airports[i];
        }
    
        temp[size] = *air;
        airports->num++;
        return temp;
}

Plane* addPlane(Plane* plane, Plane* planes) {
    int size = planes->num;

    Plane* temp = new Plane[size + 1];

    for (int i = 0; i < size; i++) {
        temp[i] = planes[i];
    }

    temp[size] = *plane;
    planes->num++;
    return temp;
}

Flight* addFlight(Flight* flight, Flight* flights) {
    int size = flights->num;

    Flight* temp = new Flight[size + 1];

    for (int i = 0; i < size; i++) {
        temp[i] = flights[i];
    }

    temp[size] = *flight;
    flights->num++;
    return temp;
}

int main () {
    
    cout << "\033[93m";
    cout << " ███╗   ██╗  █████╗  ███████╗ ███████╗ " << endl;
    cout << " ████╗  ██║ ██╔══██╗ ██╔════╝ ██╔════╝ " << endl;
    cout << " ██╔██╗ ██║ ███████║ █████╗   ███████╗ " << endl;
    cout << " ██║╚██╗██║ ██╔══██║ ██╔══╝   ╚════██║ " << endl;
    cout << " ██║ ╚████║ ██║  ██║ ██║      ███████║ " << endl;
    cout << " ╚═╝  ╚═══╝ ╚═╝  ╚═╝ ╚═╝      ╚══════╝ " << endl;
    cout << "\033[0m";                      

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
    Passanger* passangers = new Passanger[1];
    Admin* admins = NULL;
    // Airport Database
    Airport* airports = NULL;
    // Plane Database
    Plane* planes = NULL;
    // Flight Database
    Flight* flights = NULL;


    // Admin admin1("Bajwa","Bajwa Khan","admin123#","Admin");
    // addAdmin(&admin1, admins);
	
    // Admin admin2("Khan", "Khan Bajwa", "manager123#", "Manager");
    // addAdmin(&admin2, admins);
    
    Passanger passanger1("Ali", "Ali Shareef", "passenger123#", 37406982347534, 123456,"Uganda");
    passangers = addPassanger(passanger1, passangers);
    cout << "Pass1" << endl;
    Passanger passanger2("Ahmed", "Ahmed Ali", "passenger123#", 37406994247878, 178649, "Pakistan");
    passangers = addPassanger(passanger2, passangers);
	cout << "Pass2" << endl;
    
    Passanger passanger3("Umer", "Umer Ali", "passenger123#", 37406994247234, 178049, "US");
    passangers = addPassanger(passanger3, passangers);

    Passanger passanger4("Bilal", "Bilal Ali", "passenger123#", 37406923455878, 688949, "Pakistan");
    passangers = addPassanger(passanger4, passangers);
    
        cout << "****" << passangers->num;
    for (int i = 0; i < passangers->num; i++)
    {
        
        passangers[i].display();
    }
    
    cout << " ALl user added! " << endl;
    
    
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

	airport1.addPlane(plane1);
	airport1.addPlane(plane2);
	airport1.addPlane(plane3);
	airport2.addPlane(plane4);
	airport2.addPlane(plane5);
	airport3.addPlane(plane6);

	Flight flight1(111, 'L', &airport3, &airport2, &plane1);
	Flight flight2(222, 'L', &airport1, &airport2, &plane2);
	Flight flight3(333, 'L', &airport2, &airport3, &plane3);
	Flight flight4(444, 'L', &airport1, &airport3, &plane4);

	Flight flight5(555, 'I', &airport1, &airport5, &plane5);
	Flight flight6(666, 'I', &airport3, &airport4, &plane6);
	Flight flight7(777, 'I', &airport2, &airport5, &plane6);
    


    cout << "Passangers and Admins added!" << endl;
    airports = addAirport(&airport1, airports);
    airports = addAirport(&airport2, airports);
    airports = addAirport(&airport3, airports);
    airports = addAirport(&airport4, airports);
    airports = addAirport(&airport5, airports);

    planes = addPlane(&plane1, planes);
    planes = addPlane(&plane2, planes);
    planes = addPlane(&plane3, planes);
    planes = addPlane(&plane4, planes);
    planes = addPlane(&plane5, planes);
    planes = addPlane(&plane6, planes);

    flights = addFlight(&flight1, flights);
    flights = addFlight(&flight2, flights);
    flights = addFlight(&flight3, flights);
    flights = addFlight(&flight4, flights);
    flights = addFlight(&flight5, flights);
    flights = addFlight(&flight6, flights);
    flights = addFlight(&flight7, flights);


    mainMenu(passangers, admins, flights);
    
}



	// admin1.display();
	// cout << endl;
	// admin2.display();
	// cout << endl;
    
    // passanger1.display();
    // cout << endl;
    // passanger2.display();
    // cout << endl;
    
	// airport1.display();
	// cout << endl;
	// airport2.display();
	// cout << endl;
	// airport3.display();
	// cout << endl;

	// flight1.display();
	// cout << endl;
	// flight2.display();
	// cout << endl;
	// flight3.display();
	// cout << endl;
	// flight4.display();
	// cout << endl;
	// flight5.display();
	// cout << endl;
	// flight6.display();
	// cout << endl;

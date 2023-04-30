#include <iostream>
#include <string>

#include "module1.h"
#include "module2.h"
#include "module3.h"
#include "menu.h"
#include "misc.h"
#include "users.h"

using namespace std;


//////////////////DATA BASE//////////

// User Database
Passanger* passangers = NULL;
Admin* admins = NULL;
// Airport Database
Airport* airports = NULL;
// Plane Database
Plane* planes = NULL;
// Flight Database
Flight* flights = NULL;

////////////////////////////////////////////////



int main() {
    string password = getPassword();
    cout << endl << "Your password is: " << password << endl;
    return 0;
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
    //Ya Allah, mera Project assan 
    //kar dena, Ameen

    cout << "\033[93m";
    cout << " ╔══════════════════════════════════╗" << endl;
    cout << " ║              Welcome!            ║" << endl;
    cout << " ╚══════════════════════════════════╝" << endl;
    cout << "\033[0m";
    
    mainMenu();
    
    
    
}
#include <iostream>

using namespace std;

class 




















/*-------------------------Main----------------------------------*/
#include <iostream>
using namespace std;
int main()
{
  Dragon dragon("Dragon red"   , 2, 10, 3, 20         );
  Ichneumon  ichneumon ("ichneumon evil", 2, 10, 1, 10, 1,  42 );

  dragon.display();
  cout << "is preparing for fight with :" << endl;
  ichneumon.display();

  cout << endl;
  cout << "1st Fight :" << endl;
  cout << "    the creature-s are not within range, so can not Attacke."
       << endl;
  Fight(dragon, ichneumon);

  cout << "After the Fight :" << endl;
  dragon.display();
  ichneumon.display();

  cout << endl;
  cout << "Dragon has flown close to ichneumon :" << endl;
  dragon.Fly(ichneumon.position() - 1);
  dragon.display();

  cout << endl;
  cout << "ichneumon moves :" << endl;
  ichneumon.Move(1);
  ichneumon.display();

  cout << endl;
  cout << "2nd Fight :" << endl;
  cout << ""
  <<"+ ichneumon inflicts a 3-point attack on dragon\n"
     " [ level (2) * force (1) + poison (1) = 3 ] ;\n"
  "+ Dragon inflicts a 6-point attack on ichneumon\n"
      "[ level (2) * force (3) = 6 ] ;\n"
  "+ during his attack, dragon loses two additional points\n"
    "      [ corresponding to the distance between dragon and ichneumon : 43 - 41 = 2 ]." << endl;
  Fight(dragon, ichneumon);

  cout << "After the Fight :" << endl;
  dragon.display();
  ichneumon.display();

  cout << endl;
  cout << "Dragon moves by one step " << endl;
  dragon.Move(1);
  dragon.display();

  cout << endl;
  cout << "3rd Fight :" << endl;
  cout << "  + ichneumon inflicts a 3-point attack on dragon \n "
  "    [ level (2) * force (1) + poison (1) = 3 ] ; \n "
  "+ Dragon inflicts a 6-point attack on ichneumon \n "
    "      [ level (2) * force (3) = 6 ] ; \n"
  "+ during his attack, dragon lost 1 additional life point.\n"
       "[ corresponding to the distance between dragon and ichneumon : 43 - 42 = 1 ] ;\n"
  "+ ichneumon is defeated and the dragon rises to level 3" << endl;
  Fight(dragon, ichneumon);

  cout << "After the Fight :" << endl;
  dragon.display();
  ichneumon.display();

  cout << endl;
  cout << "4th Fight :" << endl;
  cout << "    when one creatures is defeated, nothing happpens" << endl;
  Fight(dragon, ichneumon);

  cout << "After the Fight :" << endl;
  dragon.display();
  ichneumon.display();

  return 0;
}
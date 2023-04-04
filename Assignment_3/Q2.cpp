#include <iostream>

using namespace std;

class Creature {
    string name;
    int level;
    int life;
    int force;
    int position;
public:
    Creature(string name, int level, int life, int force, int position = 0) {
        this->name = name;
        this->level = level;
        this->life = life;
        this->force = force;
        this->position = position;
    }
    string getName() {
        return name;
    }
    int getLevel() {
        return level;
    }
    void setLevel(int level) {
        this->level = level;
    }
    int getLife() {
        return life;
    }
    int getForce() {
        return force;
    }
    int getPosition() {
        return position;
    }
    void setPosition(int position) {
        this->position = position;
    }
    bool alive() {
        return life > 0 ? true : false;
    }
    int attackPoints() {
        if (alive())
            return level * force;
        else
            return 0;
    }
    void Move(int steps) {
        if (alive())
            position += steps;
    }
    void GoodBye() {
        cout << "English:" << this->name << " is no more!";
    }
    void Weak(int points) {
        if (alive()) {
            life -= points;
            if (life <= 0) {
                life = 0;
                GoodBye();
            }
        }
    }
    void display() {
        cout << name << ", level: " << level << ", health_status: " << life << ", force: " << force << ", Attacking Points: " << attackPoints() << ", position: " << position;
    }
};

class Dragon : public Creature {
public:
    int flame;
    Dragon(string name, int level, int life, int force, int flame, int position = 0) : Creature(name, level, life, force, position) {
        this->flame = flame;
    }
    void Fly(int position) {
        if (alive())
            setPosition(position);
    }
    void BlowFlame(Creature& creature) {
        if (alive() && creature.alive() && (distance(creature) <= flame)) {
            creature.Weak(attackPoints());
        }
        Weak(distance(creature));
        if (alive() && !creature.alive()){
            setLevel(getLevel() + 1);
        }
    }
    int distance(Creature& creature) {
        return abs(getPosition() - creature.getPosition());
    }
    void display() {
        Creature::display();
        cout << ", flame: " << flame << endl;
    }
};

class Ichneumon : public Creature {
public:
    int poison;
    int neck;
    Ichneumon(string name, int level, int life, int force, int poison, int neck, int position = 0) : Creature(name, level, life, force, position) {
        this->poison = poison;
        this->neck = neck;
    }
    void InjectPoison(Creature& creature) {
        if (alive() && creature.alive() && (distance(creature) <= neck)) {
            creature.Weak(attackPoints() + poison);
        }
        Weak(distance(creature));
        if (alive() && !creature.alive()){
            setLevel(getLevel() + 1);
        }
    }
    int distance(Creature& creature) {
        return abs(getPosition() - creature.getPosition());
    }
    void display() {
        Creature::display();
        cout << ", poison: " << poison << ", neck: " << neck << endl;
    }
};


void Fight(Dragon& dragon, Ichneumon& ichneumon) {
    if (dragon.alive() && ichneumon.alive()) {
        if (dragon.distance(ichneumon) <= dragon.flame) {
            dragon.BlowFlame(ichneumon);
        }
        if (ichneumon.distance(dragon) <= ichneumon.neck) {
            ichneumon.InjectPoison(dragon);
        }
    }
}

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
  dragon.Fly(ichneumon.getPosition() - 1);
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
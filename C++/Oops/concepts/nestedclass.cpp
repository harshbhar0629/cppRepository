#include<bits/stdc++.h>
using namespace std;

class Gun{
public:
    int ammo;
    int damage;
};
class player{
private: 

    int age; 
    int score;
    int health;

    Gun gun; //nested class

public:

    void setHealth(int health){
        this->health = health;
    }

    void setScore(int score){
        this->score = score;
    }

    void setAge(int age){
        this->age = age;
    }

    void setGun(Gun gun){
        this->gun = gun;
    }


    Gun getGun(){
        return gun;
    }

    int getAge(){
        return age;
    }

    int getScore(){
        return score;
    }

    int getHealth(){
        return health;
    }

    // int getDamage(){
    //     return damage;
    // }

    // int getAmmo(){
    //     return ammo;
    // }
};


int main(){

    Gun akm;
    player name1;
    player name2;

    akm.ammo = 220;
    akm.damage = 68;
    
    name1.setGun(akm);
    name1.setAge(14);
    name1.setHealth(70);
    name1.setScore(45);
    // name1.getGun();

    Gun awm;
    awm.ammo = 25;
    awm.damage = 90;

    name2.setGun(awm);
    name2.setAge(17);
    name2.setHealth(78);
    name2.setScore(67);
    // name2.getGun();
    
    cout<<"\nproperties for player 1:";
    cout<<"\nAge-> "<<name1.getAge();
    cout<<"\nHealth-> "<<name1.getHealth();
    cout<<"\nscore-> "<<name1.getScore();
    // cout<<"\nAmmo-> "<<name1.ammo;
    // cout<<"\nDAMAGE-> "<<name1.damage;

    cout<<"\nproperties for player 2: ";
    cout<<"\nAge-> "<<name2.getAge();
    cout<<"\nHealth-> "<<name2.getHealth();
    cout<<"\nscore-> "<<name2.getScore();
    // cout<<"\nAmmo-> "<<name2.ammo;
    // cout<<"\nDAMAGE-> "<<name2.damage;

    Gun g1 = name1.getGun(); 

    cout<<"\ngun player : ";
    cout<<"\nammo-> "<<g1.ammo;
    cout<<"\ndamage-> "<<g1.damage;

    return 0;   
}
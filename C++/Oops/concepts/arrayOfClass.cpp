#include<bits/stdc++.h>
using namespace std;

class cricketer{
private:

    string name;
    int age;
    int testMatch;
    float avgRuns;

public:

    void setAge(int age){
        this->age = age;
    }

    void setName(string name){
        this->name = name;
    }

    void setTestMatch(int match){
        testMatch = match;
    }

    void setAvgRuns(float runs){
        avgRuns = runs;
    }


    string getName(){
        return name;
    }

    int getAge(){
        return age;
    }

    int getTestMatch(){
        return testMatch;
    }

    float getAvgRun(){
        return avgRuns;
    }

};

int main(){

    cricketer name1;

    name1.setName("Virat kohli");
    name1.setAge(34);
    name1.setAvgRuns(53.14);
    name1.setTestMatch(41);

    cricketer name2;

    name2.setName("Rohit");
    name2.setAge(35);
    name2.setAvgRuns(43.14);
    name2.setTestMatch(44);

    cricketer name3;

    name3.setName("Dhawan");
    name3.setAge(33);
    name3.setAvgRuns(44.14);
    name3.setTestMatch(34);

    cricketer name4;

    name4.setName("Hardik");
    name4.setAge(29);
    name4.setAvgRuns(36.44);
    name4.setTestMatch(32);

    cricketer name5;

    name5.setName("Rishabh");
    name5.setAge(32);
    name5.setAvgRuns(47.09);
    name5.setTestMatch(48);


    cout<<"\nPlayer 1 Data:";
    cout<<"\nName ->"<<name1.getName();
    cout<<"\nAge ->"<<name1.getAge();
    cout<<"\nTest match ->"<<name1.getTestMatch();
    cout<<"\nAverage run ->"<<name1.getAvgRun()<<endl;

    cout<<"\nPlayer 2 Data:";
    cout<<"\nName ->"<<name2.getName();
    cout<<"\nAge ->"<<name2.getAge();
    cout<<"\nTest match ->"<<name2.getTestMatch();
    cout<<"\nAverage run ->"<<name2.getAvgRun()<<endl;

    cout<<"\nPlayer 3 Data:";
    cout<<"\nName ->"<<name3.getName();
    cout<<"\nAge ->"<<name3.getAge();
    cout<<"\nTest match ->"<<name3.getTestMatch();
    cout<<"\nAverage run ->"<<name3.getAvgRun()<<endl;

    cout<<"\nPlayer 4 Data:";
    cout<<"\nName ->"<<name4.getName();
    cout<<"\nAge ->"<<name4.getAge();
    cout<<"\nTest match ->"<<name4.getTestMatch();
    cout<<"\nAverage run ->"<<name4.getAvgRun()<<endl;

    cout<<"\nPlayer 5 Data:";
    cout<<"\nName ->"<<name5.getName();
    cout<<"\nAge ->"<<name5.getAge();
    cout<<"\nTest match ->"<<name5.getTestMatch();
    cout<<"\nAverage run ->"<<name5.getAvgRun()<<endl;

    // use of array object 
    cricketer player[5]={name1,name2,name3,name4,name5};

    for(int i=0;i<5;i++){

        cout<<"\nPlayer "<<i+1<<" Data:";
        cout<<"\nName ->"<<player[i].getName();
        cout<<"\nAge ->"<<player[i].getAge();
        cout<<"\nTest match ->"<<player[i].getTestMatch();
        cout<<"\nAverage run ->"<<player[i].getAvgRun()<<endl;
    
    }

    return 0;
}
#include<iostream>
#include<string>
using namespace std;
class Pet
{
public:
 string health_status;
 int hunger_level;
 int happiness_level;
 string speacialSkills;
 void display()
 {
   cout<<"\nHealth Status: "<<health_status<<endl;
   cout<<"Hunger Level: "<<hunger_level<<endl;
   cout<<"Happiness Level: "<<happiness_level<<endl;
   cout<<"Special Skills: "<<speacialSkills<<endl;
 }
 void updateHappiness( bool user_Interaction, int amount)
 {
   happiness_level+=amount;
   if(user_Interaction)
   {
     happiness_level+=1;
     cout<<"Updated Happiness Level: "<<happiness_level<<endl;
   }
   if(happiness_level>10)
   {
     happiness_level=10;
   }
   else if (happiness_level<0)
   {
     happiness_level=0;
   }
 }
 void updateHealth(int newHealth)
 {
   health_status=newHealth;
   cout<<"\nUpdated Health Status: "<<health_status<<endl;
 }
 void updateHunger(int amount)
 {
   hunger_level+=amount;
   if(hunger_level>10)
   {
     hunger_level=10;
   }
   else if(hunger_level<0)
   {
     hunger_level=0;
   }
   if(hunger_level+amount<hunger_level)
   {
     updateHappiness(0, -1);
   }
 }
 void feed()
 {
   updateHunger(-1);
 }
};
class adopter
{
public:
  string adopter_name;
  string adopterNo;
  Pet* adopter;
  void displayDetails()
  {
    cout<<"Adopted pet details by"<<adopter_name<<" are: "<<endl;
    adopter->display();
  }
  void returnPet()
  {
    cout<<"Adopter is retrning the pet"<<endl;
    delete adopter;
    adopter=nullptr;
  }
};
int main()
{
  Pet* cat=new Pet();
  // Assuming all as normal
  cat->health_status="Healthy";
  cat->hunger_level=5;
  cat->happiness_level=5;
  cat->speacialSkills="Jumping,rolling";
  cat->display();
  adopter a1;
  a1.adopter_name= "Sultan";
  a1.adopterNo="671353701";
  cout<<"Pet Details: "<<endl;
  a1.displayDetails();
  cat->feed();
  cout<<"Updated Pet Details: "<<endl;
  a1.displayDetails();
  a1.returnPet();
  return 0;
}

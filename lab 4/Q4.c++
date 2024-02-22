#include<iostream>
#include<string>
using namespace std;
class office
{
private:
    string location;
    int seatingCapacity;
    string furniture[3];
public:
    office() : location(""), seatingCapacity(0), furniture{"","",""} {}
    office(string Location, int SeatingCapacity, string Furniture[3]) : location(Location), seatingCapacity(SeatingCapacity)
    {
        for(int i=0;i<3;i++)
        {
            furniture[i]=Furniture[i];
        }
    }
    void showDetails()
    {
        cout<<"Location: "<<location<<endl;
        cout<<"Seating Capacity: "<<seatingCapacity<<endl;
        for(int i=0;i<3;i++)
        {
        cout<<"Furniture "<<i+1<<": "<<furniture[i]<<endl;
        }
        cout<<endl;
    }
};
int main()
{
    office f1;
    string location;
    string Furniture[3];
    int SeatingCapacity;
    cout<<"Enter location:\n ";
    getline(cin,location);
    cout<<"Enter furniture items:\n";
    for(int i=0;i<3;i++)
    {
        getline(cin,Furniture[i]);
    }
    cout<<"Enetr Seating Capacity\n";
    cin>>SeatingCapacity;
    cin.ignore();
    office f2(location,SeatingCapacity);
    office f3(location,SeatingCapacity,Furniture);
    cout<<"OFFICE 1 Details\n";
    f1.showDetails();
    cout<<"OFFICE 2 Details\n";
    f2.showDetails();
    cout<<"OFFICE 3 Details\n";
    f3.showDetails();
    return 0;
}

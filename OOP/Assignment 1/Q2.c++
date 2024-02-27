#include<iostream>
#include<stdbool.h>
using namespace std;
class Table
{
private:
  const int capacity;
  int occupiedSeats;
  bool clean;
public:
  Table() : capacity(4), occupiedSeats(0), clean(true){}
  Table(int capacity) : capacity((capacity==8)? 8:4), occupiedSeats(0), clean(true) {}

  int getCapacity() const
  {
    return capacity;
  }
  bool isClean() const
  {
    return clean;
  }
  bool Contain(int size) const
  {
    return size<=capacity;    
  }
  void use()
  {
    clean=false;
    cout<<"Table with capacity "<<capacity<<" is under use"<<endl;
  }
  void lunch()
  {
    cout<<"Table with capacity "<<capacity<<" is having lunch "<<endl;
  }
  void leave()
  {
    cout<<"One table is being emptied"<<endl;
  }
  void CleanTable()
  {
    clean=true;
    cout<<"Table with capacity "<<capacity<<" is clean"<<endl;
  }
  void OccupySeats(int num)
  {
    occupiedSeats+=num;
  }
  void EmptySeats(int num)
  {
    occupiedSeats-=num;
  }
  bool fullTable()
  {
    return occupiedSeats==capacity;
  }
  static void occupytable(Table t[], int size)
  {
    for(int i=0;i<size;i++)
    {
      if(t[i].isClean() && t[i].Contain(size))
      {
        t[i].use();
        t[i].OccupySeats(size);
        cout<<"Group of "<<size<<" is seated at table "<<i+1<<endl;
      }
    }
    cout<<"No table is available"<<endl;
  }
  static void EmptyTable(Table t[], int index)
  {
    t[index].EmptySeats(t[index].getCapacity());
    t[index].CleanTable();
    cout<<"Table "<<index+1<<" is being emptied"<<endl;
  }
};
int main()
{
  Table seat[5]={ Table(8), Table(8), Table(4),Table(4),Table(4)};
  Table::occupytable(seat, 4);
  Table::occupytable(seat, 6);
  seat[0].use();
  seat[0].lunch();
  seat[0].leave();
  seat[0].CleanTable(); 
  Table::EmptyTable(seat, 1);
  return 0;
}

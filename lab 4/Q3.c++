#include<iostream>
#include<string>
using namespace std;
class weekdays
{
private:
    string days[7];
    int currentDay;
public:
    weekdays()
    {
        days[0]="Sunday";
        days[1]="Monday";
        days[2]="Tuesday";
        days[3]="Wednesday";
        days[4]="Thursday";
        days[5]="Friday";
        days[6]="Saturday";
        currentDay=0;
    }
    weekdays(int CurrentDay)
    {
        days[0]="Sunday";
        days[1]="Monday";
        days[2]="Tuesday";
        days[3]="Wednesday";
        days[4]="Thursday";
        days[5]="Friday";
        days[6]="Saturday";
        currentDay=CurrentDay%7;
    }
    string getCurrentDay()
    {
        return days[currentDay];
    }
    string getNextDay()
    {
        return days[(currentDay+1)%7];
    }
    string getPreviousDay()
    {
        return days[(currentDay+6)%7];
    }
    string getNthDayFromDay(int n)
    {
        return days[(currentDay+n)%7];
    }
};
int main()
{
    weekdays day;
    cout<<"Current Day: "<<day.getCurrentDay()<<endl;
    cout<<"Next Day From Current Day: "<<day.getNextDay()<<endl;
    cout<<"Previous Day From Current Day: "<<day.getPreviousDay()<<endl;
    int n;
    cout<<"Enter a number to find the nth day from current day\n";
    cin>>n;
    cout<<"Nth Day From Current Day: "<<day.getNthDayFromDay(n)<<endl;
    return 0;
}

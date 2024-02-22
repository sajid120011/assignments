23k-0077
Sajid ali
  
#include<iostream>
#include<string>
using namespace std;
class book
{
private:
    string name;
    string auhtor;
    string isdn;
    int total_page_count;
    int pages_read;
public:
    book() : name(""), auhtor(""), isdn(""), total_page_count(0), pages_read(0) {}
    book(string name, string auhtor, string isdn, int total_page_count, int pages_read)
    : name(name), auhtor(auhtor), isdn(isdn), total_page_count(total_page_count), pages_read(pages_read) {}
    void updatePagesRead(int pages)
    {
        pages_read+=pages;
        if(pages_read==total_page_count)
        {
            cout <<"You have completed the book!\n" << std::endl;
        }
        else
        {
            cout<<"You have "<<total_page_count-pages_read<<" pages left to read\n";
        }
    }
};
int main()
{
    string name, auhtor, isdn;
    int total_page_count, pages_read;
    cout<<"Enter book  name\n";
    cin>>name;
    cout<<"Enter author's name\n";
    cin>>auhtor;
    cout<<"Enter isdn number of book\n";
    cin>>isdn;
    cout<<"Enter total number of pages of book\n";
    cin>>total_page_count;
    cin.ignore();
    book Book(name, auhtor, isdn, total_page_count, 0);
    do{
        cout<<"Enter the number of pages you read\n";
        cin>>pages_read;
        if(pages_read>0)
        {
            Book.updatePagesRead(pages_read);
        }
    }
    while(pages_read!=0);
    return 0;
}

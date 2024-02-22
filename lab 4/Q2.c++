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
    book() : name(""), auhtor(""), isdn(""), total_page_count(1000), pages_read(0) {}
    void setName(string name)
    {
        this->name=name;
    }
    void setAuthor(string auhtor)
    {
        this->auhtor=auhtor;
    }
    void setISDN(string isdn)
    {
        this->isdn=isdn;
    }
    void setTotalPageCount(int total_page_count)
    {
        this->total_page_count=total_page_count;
    }
    void setPagesRead(int pages_read)
    {
        this->pages_read=pages_read;
    }
    void showBookInfo()
    {
        cout<<"Book Name: "<<name<<endl;
        cout<<"Auhtor Name: "<<auhtor<<endl;
        cout<<"ISDN Number: "<<isdn<<endl;
        cout<<"Total Pages Of Book: "<<total_page_count<<endl;
        cout<<"Pages Read: "<<pages_read<<endl;
    }
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
    book Book;
    string name, auhtor, isdn;
    int total_page_count, pages_read;
    cout<<"Enter book  name\n";
    getline(cin,name);
    Book.setName(name);
    cout<<"Enter author's name\n";
    getline(cin,auhtor);
    Book.setAuthor(auhtor);
    cout<<"Enter isdn number of book\n";
    getline(cin,isdn);
    Book.setISDN(isdn);
    cout<<"Enter total number of pages of book\n";
    cin>>total_page_count;
    cout<<"BOOK INFORMATION\n";
    Book.showBookInfo();
    Book.setTotalPageCount(total_page_count);
    cin.ignore();
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

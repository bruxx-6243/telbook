// Телефон книга для хранения номеров

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class PhoneSave{

    public:
        string name;
        string number;
        PhoneSave(const PhoneSave &v):
            name(v.name),
            number(v.number){}
        PhoneSave(){}

        const PhoneSave &operator = (const PhoneSave &v){
            name = v.name;
            number = v.number;
            return v;
        }

};

int main(){
    fstream f("registration.txt");
    vector <PhoneSave> telBook;

    while(true){
        PhoneSave t;
        f >> t.name;
        if (f.eof()) 
        break;
        f>> t.number;
        if (f.eof())
        break;

        telBook.push_back(t);
    }

    while(true){
       cout <<"Enter name (or Stop) : ";
       string name;
       cin>>name;
       if (name == "Stop") break;
       for (int i = 0; i < telBook.size(); i++){
           if(telBook[i].name == name){
               cout<< name << " " << telBook[i].number << endl;
           }
       } 
    }

}
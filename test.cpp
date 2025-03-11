#include <iostream>
using namespace std ;

class car {
    private : 
    string brand;
    string model;
    int year;

    public:
    car(string b , string m , int y){
        brand = b ;
        model = m;
        year = y ;

    }
    void display (){
        cout<<"brand"<<brand<<",model"<<model<<",year"<<year<<endl;

    }
};

int main(){
    car mycar("toyota" , "corolla" , 2022);

    mycar.display();
    return 0 ;
    
}

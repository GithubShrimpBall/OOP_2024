#include <iostream>
using namespace std;

class Circle{
    int radius;
    public: 
        Circle(){radius=1;}
        Circle(int r){radius=r;}
        void setRadius(int r){radius=r;}
        int getRadius(){return radius;}
        double getArea(){return 3.14*radius*radius;}
};

class Sample{
    Circle* p;
    int capacity;
    int size;

    public:
        Sample(int n){capacity=n; p=new Circle[n];}
        void read();
        void write();
        Circle big();
        int getSize(){return size;}
        ~Sample(){delete[] p;}
};

void Sample::read(){
    int r;
    cout << "입력하려는 원의 갯수는? ";
    cin >> size;
    cout << size << "개의 원의 반지름을 입력하시오 ";
    for(int i=0; i<size; i++){
        cin >> r;
        p[i].setRadius(r);
    }
}

void Sample::write(){

    for(int i=0; i<size; i++){
        cout << p[i].getRadius() << ' ';
    }
    cout << endl;
}

Circle Sample::big(){
    Circle big;
    big = p[0];
    for(int i=0; i<size; i++){
        if(big.getRadius() < p[i].getRadius()) big=p[i]; 
    }
    return big;
}

int main(){
    Sample s(10);
    s.read();
    cout << "각 원 객체의 반지름 " << s.getSize() << "개를 출력합니다.";
    s.write();
    Circle big=s.big();
    cout << "가장 큰 원의 넓이: " << big.getArea() << "\t 가장 큰원의 반지름 :" << big.getRadius() << endl;
}
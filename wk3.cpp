#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//cstdlib and ctime are used for random number generation


class EvenRandom{
    public:
            EvenRandom();
            int next();
            int nextInRange(int low, int high);
};

EvenRandom::EvenRandom(){
    srand(time(NULL));
}

int EvenRandom::next(){
    int num;
    num=rand();
    if(num%2==0)
        return num;
    else
        return next();
}

int EvenRandom::nextInRange(int low, int high){
    //이게 low까지 있어서 단순히 %연산으로 접근하면 안되긴 하겠네
    int num;
    num = rand();
    num = num%high;
    
    if(num>=low & num%2==0)
        return num;
    else
        return nextInRange(low, high);
}



int main(){
    EvenRandom r; //여기서 랜덤 시드를 만든다.
    cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 짝수 정수 10 개--" << endl;
    for(int i=0; i<10; i++){
        int n = r.next();
        cout << n << ' ';
    }
    cout << endl << endl << "-- 2에서 "<< "10까지의 랜덤 짝수 정수 10개 --" << endl;
    for(int i=0; i<10; i++){
        int n = r.nextInRange(2, 10);
        cout << n << ' ';
    }
    cout <<  endl;
}
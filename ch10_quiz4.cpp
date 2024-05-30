#include <iostream>
#include <vector>
using namespace std;
class CPoint{
    private:
        int x, y;
    public:
        CPoint(int a=0, int b=0):x(a), y(b){ }
        void Print() {cout << "(" << x << "," << y <<")" << endl; }
};

int main(void){
    unsigned i;
    vector<CPoint> CAry(3);
    for(i=0; i<3; i++){
        CAry.at(i)=CPoint(i+1, i+1); // at멤버 함수에 대해서 어떤 역할인지 봐야하고
        //위 코드는 CAry[i]랑 동일하다!! 시험에 출제하기 좋은 요소로 보여짐.
    }
    for(i=0; i<5; i++){
        CAry.push_back(CPoint(i*2 + 1, i*3 +1));
    }
    for(i=0; i<CAry.size(); i++)
                CAry[i].Print();



}

#include <iostream>
using namespace std;


int main(){
    char text[10000];
    int i, j;
    int count[26] = {};//알파벳 개수를 저장할 배열
    int len=0;

    cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다." << endl;
    cout << "텍스트의 끝은 ; 입니다. 10000개까지 가능합니다." << endl;
    cin.getline(text, 10000, ';');
    
    for(i=0; text[i]!='\0'; i++){
        if(isalpha(text[i])){
            text[i] = tolower(text[i]);
            count[text[i] - 'a']++;
            len++;
        }
    }
    //isalpha() 함수를 사용하여 알파벳인지 확인하고, tolower() 함수를 사용하여 소문자로 변환한다.
    /*
    for (i = 0; text[i]!=';'; i++){
        if (isalpha(text[i])){//즉 true이면...
            text[i] = tolower(text[i]); //소문자로 변환
            count[text[i] - 'a']++; //알파벳 수 저장
            len++;
        }
    }
    */
    cout << "총 알파벳 수 " << len << endl;

    for(i=0; i<26; i++){
        cout << (char)('a' + i) << " (" << count[i] << ") : ";
        for(j=0; j<count[i]; j++){
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}


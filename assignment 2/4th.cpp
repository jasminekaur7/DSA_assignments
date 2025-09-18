#include<iostream>
#include<string>
using namespace std;

void Concat(string str1, string str2){
    //Write a program to concatenate one string to another string.
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        i++;
    }
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
    cout << "Concatenated string: " << str1 << endl;
}

void Rev(string str){
    // Write a program to reverse a string.
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
    cout << "Reversed string: " << str << endl; 
}

bool isVowel(char ch) {
    ch = tolower(ch); // handle uppercase also
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void DelVowel(string str){
    // Write a program to delete all the vowels from the string. 
    string result = "";
    for (int i = 0; i < str.length(); i++) {
        if (!isVowel(str[i])) {   // if not a vowel, keep it
            result += str[i];
        }
    }
    cout << "String without vowels: " << result << endl;
}

void Alph(string str){
    // Write a program to sort the strings in alphabetical order.
    for(int j  = 0 ; j < str.length() - 1 ; j++){
        for ( int i = 0 ; str[i+1] != '\0' ; i++ ){
            if( int(tolower(str[i]) > int(tolower(str[i+1])) )){
                char temp = str[i];
                str[i] = str[i+1];
                str[i+1] = temp;
            }
        }
    }
    cout << "String in Alphabetical order : " << str << endl;
}

void Case(char ch){
    //lowercase = uppercase + 32.
    if( ch > 'A' && ch < 'Z' ){
        ch = ch + 32;
        cout << ch;
    }
    else {
        cout << "already in lowercase" << endl;
    }
}

int main() {
    string str1, str2;

    char ch = 'F';

    cout << "Enter first string: ";
    getline(cin, str1);

    cout << "Enter second string: ";
    getline(cin, str2);

    Concat(str1,str2);
    Rev(str1);
    DelVowel(str1);
    Alph(str1);
    Case(ch);
    return 0;
}

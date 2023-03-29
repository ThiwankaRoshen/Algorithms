#include<iostream>
#include<cmath>
using namespace std;
int Karatsuba(int number1,int number2,int base){
    /*This function gives the multiple of two integer numbers for any base.
    Here we first return simple multiplication if the inputs are single numbers.
    if they aren't, we want get the maximum index of those numbers.then we get the high digits and lower bits
    through floor division and modulus operation.then we recursively call the function for 3 times and finally we return 
    the final answer  */
    if(number1<10 || number2<10){
        return number1*number2;
    }
    string num1_str = to_string(number1);//convert numbers to string to get length 
    string num2_str = to_string(number2);

    int n=max(num1_str.length(),num2_str.length());//maximum index
    int Max_index =ceil(pow(base,n/2));//convert from double to int
    int x_high=(number1/Max_index);
    int x_low=(number1%(Max_index));
    int y_high=number2/Max_index;
    int y_low=number2%Max_index;

    int a = Karatsuba(x_high,y_high,base);
    int d = Karatsuba(x_low,y_low,base);
    int e = Karatsuba(x_high+x_low,y_high+y_low,base)-d-a;
    
    return a*pow(base,n)+e*pow(base,n/2)+d;
    
}
int main(){
    cout<<Karatsuba(120,20,10);
}

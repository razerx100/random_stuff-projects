#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Equation{
    string equation, equation_raw;
    int power(int base, int pow){
        if(pow == 0){
            return 1;
        }
        return base * power(base, pow - 1);
    }

    int add(int x, int y){ return x + y; }

    int sub(int x, int y){ return x - y; }

    int multi(int x, int y){ return x * y; }

    int find(){
        int location = -1;
        for(int i = 0; i < equation.size(); i++){
            if(equation[i] == '^'){
                location = i;
                break;
            }
            else if(equation[i] == '*'){
                location = i;
                break;
            }
            else if(equation[i] == '+'){
                location = i;
                break;
            }
            else if(equation[i] == '-'){
                location = i;
                break;
            }
        }
        return location;
    }

    bool isDigitStr(){
        for(char i : equation){
            if(!isdigit(i)){
                return false;
            }
        }
        return true;
    }

    void string_op(){
        string current = "";
        while(!isDigitStr()){
            int location = find();

            if(equation[location] == '^'){
                current = to_string(power((equation[location - 1] - 48), (equation[location + 1] - 48)));
            }
            else if(equation[location] == '*'){
                current = to_string(multi((equation[location - 1] - 48), (equation[location + 1] - 48)));
            }
            else if(equation[location] == '+'){
                current = to_string(add((equation[location - 1] - 48), (equation[location + 1] - 48)));
            }
            else if(equation[location] == '-'){
                current = to_string(sub((equation[location - 1] - 48), (equation[location + 1] - 48)));
            }
            string pre = "", nexT = "";
            if(location - 2 != 0){
                pre = equation.substr(0, location - 1);
            }
            if(location + 2 != equation.size()){
                nexT = equation.substr(location + 2, equation.size() - (location + 2));
            }
            equation = pre + current + nexT;
        }
    }

public:
    void initilize(){
        cout << "Equation is : ";
        cin >> equation_raw;
    }
    void result(){
        int value_of_x;
        cout << "Write the variable : ";
        cin >> value_of_x;
        equation = equation_raw;
        char value = 48 + value_of_x;
        replace(equation.begin(), equation.end(), 'x', value);
        string_op();
        cout << "Answer is " << equation;
    }
};

int main(){
    Equation eq;
    eq.initilize();
    int times = 1;                //Call result as many times as you want
    while(times--){
        eq.result();
    }
    return 0;
}
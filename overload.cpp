#include<iostream>

class Int{
    int64_t num;
    public:
    Int();
    Int(int64_t take);
    Int operator + (Int &nu);
    Int operator - (Int &nu);
    friend std::ostream& operator<<(std::ostream &print, Int &n);
    friend std::istream& operator>>(std::istream &input, Int &n);
    operator int64_t() const{
        return num;
    }
};

Int :: Int(){
    num = 0;
}

Int :: Int(int64_t take){
    num = take;
}

Int Int::operator+(Int &nu){
    Int var;
    var = num + nu.num;
    return var;
}

Int Int::operator-(Int &nu){
    Int var;
    var = num - nu.num;
    return var;
}

std::istream& operator>>(std::istream &input, Int &n){
    input >> n.num;
    return input;
}

std::ostream& operator<<(std::ostream &print, Int &n){
    print << n.num;
    return print;
}

int main(){
    Int x, y;
    std::cin >> x >> y;
    Int z = x + y;
    std::cout << z << " and minus " << x - y;
    int64_t num = x;
    std::cout << "\nWorks " << num;
    return 0;
}
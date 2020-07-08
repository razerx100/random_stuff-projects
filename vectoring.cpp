#include<iostream>
#include<vector>

template<class T>
class Dynamite : public std::vector<T>{
    public:
    Dynamite<T>(){}
    Dynamite<T>(int num) : std::vector<T>(num){}
    Dynamite<T>(int num, int value) : std::vector<T>(num, value){}
    void say_my_name();
    template<class R>
    friend std::ostream &operator<<(std::ostream &ptr, Dynamite<R> data);
};

template<class T>
void Dynamite<T> :: say_my_name(){
    std::cout << "\nSaikat\n";
}

template<class T>
std::ostream &operator<<(std::ostream &ptr, Dynamite<T> data){
    for(T i : data){
        ptr << i << " ";
    }
    return ptr;
}

int main(){
    Dynamite<int> x;
    for(int i = 1; i < 7; i++){
        x.emplace_back(i);
    }
    std::cout << x;
    return 0;
}
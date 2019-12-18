#include <iostream>
#include "funct.cpp"
#include <vector>

// void wrong_var(std::string answ, int *a, int *b, bool *new_answ, bool *exit_time, std::vector<std::string> variants){
//         while(std::find(variants.begin(), variants.end(), answ) == variants.end() && !exit_time && !new_answ){ //while our answer isn't in array of variants

//             std::cout << "\nUps wrong operation\nTry again: \n"; //Simple message
//             std::cout << "(Possible var: ";
//             for(std::string i: variants) std::cout << "|" << i << "|";
//             std::cout << "|new||exit|)";

//             std::cin >> answ;//Waiting for new answer
//             exit_time = std::find(var_for_exit.begin(), var_for_exit.end(), answ) != var_for_exit.end();

//             if(answ == "new"){
//                 func_for_new(&a, &b, &new_answ);
//             }
//         }
// }

void func_for_new(int *a, int *b, bool *new_answ){
    std::cout << "Waiting for new numbers\na= ";
    int fuck_this;
    std::cin >> fuck_this;
    *a = fuck_this;
    std::cout << "b= ";
    std::cin >> fuck_this;
    *b = fuck_this;
    *new_answ = true;
}

void logic(int a, int b, std::string answ){
    if(answ == "add") std::cout << "\nAnswer is: " << function::add(a, b) << std::endl;
    else if(answ == "sub") std::cout << "\nAnswer is: " << function::sub(a, b) << std::endl;
    else if(answ == "mult") std::cout << "\nAnswer is: " << function::mult(a, b) << std::endl;
    else if(answ == "div") std::cout << "\nAnswer is: " << function::div(a, b) << std::endl;
    else std::cout << "\nSomething went wrong" << std::endl;

}
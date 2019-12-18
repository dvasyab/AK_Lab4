#include <iostream> //input & output
#include <algorithm> //std::find - searshing answer in array 
#include <vector>
#include "speaking.cpp"

int main(int argc, char **argv) {
    char *end;//Zatichka dlya perevirku vvodu
    int a, b; //Our two numbers which we are working with

    //It's all about input
    if(argc == 1){
        std::cout << "I need some arguments, first:= ";
        std::cin >> a;
        std::cout << "Ok, now second:= ";
        std::cin >> b;
    }
    else if(argc == 2){
        a = strtol(argv[1], &end, 10); //First argument of command line
        std::cout << "Too few arguments given, i need more\nSecond one:= ";
        std::cin >> b;
    }
    else if(argc == 3){ //if arguments was given through command line
    a = strtol(argv[1], &end, 10); //First argument of command line
    b = strtol(argv[2], &end, 10); //Second argument of command line
    }


    std::vector<std::string> variants = {"add", "sub", "mult", "div"}; //array with possible answers
    std::vector<std::string> var_for_exit = {"quit", "exit", "q"}; //array with possible answers for exit
    std::string answ;
    
    bool first_exec = false, exit_time = false, new_answ = false; //Logic of speaking

    std::cout << "Hi, what you whant me to do with "<< a << " and " << b << " ?\n";

    while(!exit_time){ //while our answer is not out
        
        if (!first_exec) {
            std::cin >> answ; //input answer if first executed
            if(std::find(var_for_exit.begin(), var_for_exit.end(), answ) != var_for_exit.end()) break;
            if(answ == "new"){
            func_for_new(&a, &b, &new_answ);
            }
        }


        while(std::find(variants.begin(), variants.end(), answ) == variants.end() && !exit_time && !new_answ){ //while our answer isn't in array of variants

            std::cout << "\nUps wrong operation\nTry again: \n"; //Simple message
            std::cout << "(Possible var: ";
            for(std::string i: variants) std::cout << "|" << i << "|";
            std::cout << "|new||exit|)";

            std::cin >> answ;//Waiting for new answer
            exit_time = std::find(var_for_exit.begin(), var_for_exit.end(), answ) != var_for_exit.end();

            if(answ == "new"){
                func_for_new(&a, &b, &new_answ);
            }
        }
            if(!exit_time){//if in wrong wariant wasnt exit
                logic(a, b, answ); //making operation

                std::cout << "\nWhat now? :>\n";
                first_exec = true;
                std::cin >> answ;
                exit_time = std::find(var_for_exit.begin(), var_for_exit.end(), answ) != var_for_exit.end();

                if(answ == "new"){
                    func_for_new(&a, &b, &new_answ);
                }
            }
    }
    
    return 0;
}
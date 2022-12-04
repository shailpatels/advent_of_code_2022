#include <iostream>
#include <fstream>


void part1(const std::string& filename){
    int start_a, end_a, start_b, end_b;
    char dump;

    std::ifstream input{filename};

    u_int count = 0;
    while(input >> start_a >> dump >> end_a >> dump >> start_b >> dump >> end_b)
    {

        if(start_a <= start_b && end_a >= end_b)
            count++;
        else if(start_b <= start_a && end_b >= end_a)
            count++;
    }

    std::cout << count << std::endl;
}


void part2(const std::string& filename)
{
    int start_a, end_a, start_b, end_b;
    char dump;

    std::ifstream input{filename};
    auto within = [](int test, int a, int b){
        return test >= a && test <= b;
    };

    u_int count;
    while(input >> start_a >> dump >> end_a >> dump >> start_b >> dump >> end_b)
    {
        if(within(start_a, start_b, end_b) || within(end_a, start_b, end_b))
            count++;

        else if(within(start_b, start_a, end_a) || within(start_b, start_a, end_a))
            count++;
    }

    std::cout << count << std::endl;
}


int main(int argc, char ** argv)
{
    if(2 != argc)
    {
        std::cerr << "usage: ./a.out <input>" << std::endl;
        return EXIT_FAILURE;
    }

    //part1(std::string{argv[1]});
    part2(std::string{argv[1]});
}

#include <iostream>
#include <fstream>
#include <set>



void part1(const std::string& filename){

    std::ifstream input{std::string{ filename }};
    std::string buffer;

    unsigned long largest = 0, sum = 0;
    while(std::getline(input, buffer))
    {
        if(buffer.size() == 0)
        {
            largest = std::max(largest, sum);
            sum = 0;
        }
        else{
            sum += std::stoul(buffer);
        }
        //std::cout << buffer << std::endl;
    }

    largest = std::max(largest, sum);
    std::cout << "largest: " <<largest << std::endl << std::endl;
}


void part2(const std::string& filename)
{
    std::ifstream input{std::string{ filename }};
    std::string buffer;

    std::set<u_int> cals;
    unsigned long sum = 0;

    while(std::getline(input, buffer))
    {
        if(buffer.size() == 0)
        {
            cals.insert(sum); 
            sum = 0;
        }
        else{
            sum += std::stoul(buffer);
        }
    }

    cals.insert(sum);

    unsigned long total = 0;
    auto itr = cals.end();
    itr--;
    for(u_int i = 0; i < 3; i++){
        u_int cal = *itr;
        total += cal;
        std::cout << *itr << std::endl;
        itr--;
    }

    std::cout << "sum: " << total << std::endl;
}


int main(int argc, char ** argv)
{
    if(2 != argc)
    {
        std::cerr << "usage: ./a.out <input>" << std::endl;
        return EXIT_FAILURE;
    }

    part1(std::string{argv[1]});
    part2(std::string{argv[1]});
}

#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#include <assert.h>


inline u_int getPriority(char c)
{
    if(c >= 'a'){
        return (c - 'a') + 1;
    }else{
        return (c - 'A') + 27;
    }
}


void part1(const std::string& filename)
{
    std::ifstream input{filename};

    std::string buffer;
    u_int sum = 0;
    while(input >> buffer)
    {
        u_int pivot = buffer.size() / 2;
        
        std::string a = std::string{ buffer.begin(), buffer.begin() + pivot };
        std::string b = std::string{ buffer.begin() + pivot, buffer.end() };

        for(u_int i = 0; i < pivot; i++){
            for(u_int j = 0; j < pivot; j++){
                if(a[i] == b[j]){
                    sum += getPriority(a[i]);
                    goto skip;
                }
            }
        }

skip:   continue;
    }

    std::cout << sum << std::endl;
}


void part2(const std::string& filename){
    std::string a,b,c;
    std::ifstream input{filename};

    u_int sum = 0;
    while(input >> a >> b >> c)
    {
        std::set<char> intersection;
        std::vector<char> result;

        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        std::sort(c.begin(), c.end());

        std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::inserter(intersection, intersection.begin()));
        std::set_intersection(c.begin(), c.end(), intersection.begin(), intersection.end(), std::back_inserter(result));

        assert(result.size() == 1);

        sum += getPriority(result[0]);
    }

    std::cout << sum << std::endl;
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

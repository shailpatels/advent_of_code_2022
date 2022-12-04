#include <iostream>
#include <fstream>
#include <map>
#include <vector>

/**
 * 0 = rock
 * 1 = paper
 * 2 = sissors
 *
 *   O    P   S
 *   0    0   4 (3+1)
 *   1    0   1 (0+1)
 *   2    0   7 (6+1)
 *
 *   0    1   8 (6+2)
 *   1    1   5 (3+2)
 *   2    1   2 (0+2)
 *
 *   0    2   3 (0+3)
 *   1    2   9 (6+3)
 *   2    2   6 (3+3)
 */



/**
 * 0 = lose
 * 1 = draw
 * 2 = win
 *
 *   O    P   C   S
 *   0    0   2   3
 *   1    0   0   1
 *   2    0   1   2
 *
 *   0    1   0   4 (3+1)
 *   1    1   1   5 (3+2)
 *   2    1   2   6 (3+3)
 *
 *   0    2   1   8 (6+2)
 *   1    2   2   9 (6+3)
 *   2    2   0   7 (6+1)
 */
std::map<int,  std::map<int, int> > scores{
    { 0, {{0, 4}, {1,8}, {2,3}} },
    { 1, {{0, 1}, {1,5}, {2,9}} },
    { 2, {{0, 7}, {1,2}, {2,6}} }
};

std::map<int,  std::map<int, int> > scores2{
    { 0, {{0, 2}, {1,0}, {2,1}} },
    { 1, {{0, 0}, {1,1}, {2,2}} },
    { 2, {{0, 1}, {1,2}, {2,0}} }
};

void part1(const std::string& filename){
    std::ifstream input{filename};

    char opponent, player;
    u_int score = 0;
    while(input >> opponent && input >> player)
    {
        //std::cout << ( opponent  - 'A' ) << " " <<  ( player - 'X' ) << std::endl;
        int o = opponent - 'A';
        int p = player - 'X';
        
        score += scores[o][p];

    }

    std::cout << score << std::endl;
}


void part2(const std::string& filename)
{
    std::ifstream input{filename};

    char opponent, player;
    u_int score = 0;
    while(input >> opponent && input >> player)
    {
        int o = opponent - 'A';
        int choice = player - 'X';

        int p = scores2[o][choice];
        
        score += scores[o][p];
    }

    std::cout << score << std::endl;
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

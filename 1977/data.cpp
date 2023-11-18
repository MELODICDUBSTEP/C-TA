#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
#include <map>

long long MIN = 0;
long long MAX = 9;
int length;
int file;

void Compute(std::string input, std::string output);

int generateRandom(long long MIN, long long MAX);

int main()
{
    for(file = 3; file <= 10; file ++)
    {
         length = generateRandom(0, 1e6);
    std::string input_filename = std::to_string(file) + ".in";
    std::string output_filename = std::to_string(file) + ".out";
    //std::cout << input_filename << " " << output_filename << std::endl;
    std::fstream inf(input_filename.c_str(), std::ios::out);
    // std::fstream ouf(output_filename.c_str(), std::ios::out);
    inf << length << std::endl;
    for(int i = 0; i < length; i++)
    {
        inf << generateRandom(MIN, MAX) << std::endl;
    }
    Compute(input_filename, output_filename);
    }
    return 0;
}

int generateRandom(long long MIN, long long MAX)
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(MIN, MAX);
    return distribution(generator);
}

void Compute(std::string input, std::string output)
{
        std::ifstream inf(input.c_str(), std::ios::in);
        std::ofstream ouf(output.c_str(), std::ios::out);
       bool fivefound = false, zerofound = false;
        int num[1000000];
        int l; 
        inf >> l;
        //std::cout << "L is " << l << std::endl;
        for(int i = 0; i < length; i++)
        {
            inf >> num[i];
        }
        int i;
        for(i = l - 1; i >= 0; i--)
        {
            if(zerofound && num[i] == 0)
            {
                ouf << l - 2 - i;
                //std::cout << "1out and i is" << i << std::endl;
                return;
            }
            if(zerofound && num[i] == 5)
            {
                ouf << l - 2 - i;
                //std::cout << "2out and i is" << i << std::endl;
                return;
            }
            if(fivefound && num[i] == 2)
            {
                ouf << l - 2 - i;
                //std::cout << "3out and i is" << i << std::endl;
                return;
            }
            if(fivefound && num[i] == 7)
            {
                ouf << l - 2 - i;
                //std::cout << "4out and i is" << i << std::endl;
                return;
            }
            if(num[i] == 5)
            {
                fivefound = true;
            }
            if(num[i] == 0)
            {
                zerofound = true;
            }
        }
              if(zerofound)
            {
                ouf << l - 1;
                //std::cout << "5out and i is" << i << std::endl;
                return;
            }
            ouf << l;
            return;
}
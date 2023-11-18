#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
#include <map>
#include <bitset>

long long MIN = 0;
long long MAX = 1;
int n = 50000;
int file;

void Compute(std::string input, std::string output, int k);

long long generateRandom(long long MIN, long long MAX);

int main()
{
    //int k = ;
    for(file = 8; file <= 10; file++)
    {
    int k = generateRandom(0, 100);
    std::string input_filename = std::to_string(file) + ".in";
    std::string output_filename = std::to_string(file) + ".out";
    //std::cout << input_filename << " " << output_filename << std::endl;
    std::fstream inf(input_filename.c_str(), std::ios::out);
    // std::fstream ouf(output_filename.c_str(), std::ios::out);
    inf << n << std::endl;
    long long used_num;
    // = 0b111111110000000;
    for(int i = 0; i < 8; i++)
    {
        used_num += 1LL;
        used_num <<= 1LL;
    }
    used_num <<= 7LL;

    //111111110000000

    for(int i = 0; i < n; i++)
    {
        long long n1 = 0;
        long long n2 = 0;
        for(int i = 0; i < 7; i++)
        {
            n1 <<= 1LL;
            n2 <<= 1LL;
            n1 += generateRandom(0, 1);
            n2 += generateRandom(0, 1);
        }
        n1 = n1 | used_num;
        n2 = n2 | used_num;
        inf << n1 << " " << n2 << std::endl;
    }
    inf << k;
    
    Compute(input_filename, output_filename, k);
    }
    return 0;
}

long long generateRandom(long long MIN, long long MAX)
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<long long> distribution(MIN, MAX);
    return distribution(generator);
}

void Compute(std::string input, std::string output, int k)
{
        std::ifstream inf(input.c_str(), std::ios::in);
        std::ofstream ouf(output.c_str(), std::ios::out);
        int answer = 0;
        std::map<std::pair<long, long>, int> m;
        int l;
        inf >> l;
        std::cout << "L is " << l << std::endl;
        std::vector <std::vector <long long>> coordinates;
        for(int i = 0; i < l; i++)
        {
            long long x1, x2;
            inf >> x1 >> x2;
            coordinates.push_back({x1, x2});
        }
        std::cout << coordinates.size() << std::endl;
        std::cout << coordinates[0].size() << std::endl;
        std::cout << "K is " << k << std::endl;
        for(int i = 0; i < l; i++)
        {
            int x = coordinates[i][0];
            int y = coordinates[i][1];
            for(int j = 0; j <= k; j++)
            {
                int r = x ^ j;
                int s = y ^ (k - j);
                answer += m[std::make_pair(r, s)];
            }
            m[std::make_pair(x, y)]++;
        }
        ouf << answer;
}
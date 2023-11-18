#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
#include <map>

int main()
{
     bool fivefound = false, zerofound = false;
        int num[1000000];
        int l; 
        std::cin >> l;
        //std::cout << "L is " << l << std::endl;
        for(int i = 0; i < l; i++)
        {
            std::cin >> num[i];
        }
        int i;
        for(i = l - 1; i >= 0; i--)
        {
            if(zerofound && num[i] == 0)
            {
                std::cout << l - 2 - i;
                //std::cout << "1out and i is" << i << std::endl;
                return 0;
            }
            if(zerofound && num[i] == 5)
            {
                std::cout << l - 2 - i;
                //std::cout << "2out and i is" << i << std::endl;
                return 0;
            }
            if(fivefound && num[i] == 2)
            {
                std::cout << l - 2 - i;
                //std::cout << "3out and i is" << i << std::endl;
                return 0;
            }
            if(fivefound && num[i] == 7)
            {
                std::cout << l - 2 - i;
                //std::cout << "4out and i is" << i << std::endl;
                return 0;
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
                std::cout << l - 1;
               // std::cout << "5out and i is" << i << std::endl;
                return 0;
            }
            std::cout << l;
            return 0;
}
#ifndef __GENERATOR_HPP__
#define __GENERATOR_HPP__


#include <vector>
#include <time.h>
#include <stdlib.h>

#include <framework/settings/settings.hpp>

namespace framework
{

class generator
{
    public:
        template<typename T = int>
        static std::vector<std::vector<T> > generate_inputs(std::initializer_list<int> sizes)
        {
            srand(time(NULL));
            std::vector<std::vector<T> > content;

            for(auto size : sizes)
            {
                std::vector<T> temp(size * size);

                for(int i = 0; i < temp.capacity(); i++)
                {
                    temp[i] = (T)(((rand() % RAND_MAX) + 1)+(rand() / RAND_MAX));
                }

                content.push_back(temp);
            }

            return content;
            
        }

        static std::vector<settings> generate_settings(std::initializer_list<settings> settings_)
        {
            std::vector<settings> content;

            for(auto setting : settings_)
            {
                content.push_back(setting);
            }

            return content;
        }
};

}

#endif
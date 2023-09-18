#include "exampleZ/example_lib.hpp"
using namespace std;
int run_me()
{
    return 100;
}

int makeXsum(std::initializer_list<int> values)
{
    int total{0};
    for (int val : values)
    {
        total += val;
    }
    return total;
}

/**
 * @brief simple constructor
 *
 */
/**
 * @brief simple desctuctor
 *
 */

void NSX1::Some_Classs1::print_age() const
{
    printf("your age is %d\n", this->age);
}

void NSX1::Some_Classs1::print_freq() const
{
    cout << "freq is" << this->freq << endl;
}
void DumpHex(const void* data, size_t size)
{
    char ascii[17];
    size_t i, j;
    ascii[16] = '\0';
    for (i = 0; i < size; ++i)
    {
        printf("%02X ", (static_cast<const unsigned char*>(data)[i]));
        if ((static_cast<const unsigned char*>(data)[i]) >= ' ' && (static_cast<const unsigned char*>(data)[i]) <= '~')
        {
            ascii[i % 16] = static_cast<const char*>(data)[i];
        }
        else
        {
            ascii[i % 16] = '.';
        }
        if ((i + 1) % 8 == 0 || i + 1 == size)
        {
            printf(" ");
            if ((i + 1) % 16 == 0)
            {
                printf("|  %s \n", ascii);
            }
            else if (i + 1 == size)
            {
                ascii[(i + 1) % 16] = '\0';
                if ((i + 1) % 16 <= 8)
                {
                    printf(" ");
                }
                for (j = (i + 1) % 16; j < 16; ++j)
                {
                    printf("   ");
                }
                printf("|  %s \n", ascii);
            }
        }
    }
}

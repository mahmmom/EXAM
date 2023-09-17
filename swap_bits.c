*#include <stdio.h>
  
unsigned char	swap_bits(unsigned char octet)
{
    return ((octet >> 4) | (octet << 4));
}

int main()
{
    unsigned char octet = 'A';

    printf("%x\n", octet);

    octet = swap_bits(octet);

    printf("%x\n", octet);

}

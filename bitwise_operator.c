#include <stdio.h>

char *int2bin(int n) { 
    // determine the number of bits needed ("sizeof" returns bytes) 
    int nbits = sizeof(n) * 8; 
    char *s = malloc(nbits+1);  // +1 for '\0' terminator 
    s[nbits] = '\0'; 
    
    // forcing evaluation as an unsigned value prevents complications 
    // with negative numbers at the left-most bit 
    unsigned int u = *(unsigned int*)&n; 
    
    int i; 
    unsigned int mask = 1 << (nbits-1); // fill in values right-to-left 
    for (i = 0; i < nbits; i++, mask >>= 1) 
        s[i] = ((u & mask) != 0) + '0'; 
    
    return s; 
} 

int main(int argc, char const *argv[])
{
    int list[] = {1,2,3,4,5,6,7,8,9,10};
    int length = sizeof(list) / sizeof(list[0]);

    for (int i = 0; i < length; i++) {
        if (list[i] & 1) {
            char *s = int2bin(list[i]); 
            printf("%d -> %s\n", list[i], s); 
            free(s); 
        } 
    }
    return 0;
}
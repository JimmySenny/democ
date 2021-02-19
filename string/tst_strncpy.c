#include <stdio.h>
#include <string.h>

int main( int argc, char** argv ){
    char str[10] = "ABC123abc";
    char * p1 = NULL;
    char * p2 = NULL;

    char dst[10];

    memset( dst, 0x00, sizeof( dst ));

    p1 = strstr( str, "BC" );
    p2 = strstr( str, "ab" );

    strncpy( dst, p1+2, p2 - p1 -2 );

    printf( "dst[%s]\n", dst );

    return 0;
}



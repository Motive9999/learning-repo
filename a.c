#include <stdio.h>

#define U64 unsigned long long

void print_bitboard(U64 bitboard)
{
    // loop over board ranks
    for (int rank = 0; rank < 8; rank++)
    {
        // loop over board files
        for (int file = 0; file < 8; file++)
        {
            // convert file & rank into square index
            int square = rank * 8 + file;

            //
            printf(" %d ", square);

        }

        // print new line every rank
        printf("\n");
    }
}

int main()
{
    U64 bitboard = 0ULL;
    print_bitboard(bitboard);

    return 0;
}
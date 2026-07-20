#include <stdio.h>

#define U64 unsigned long long

enum
{
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8
};

enum
{
    WP, WN, WB, WR, WQ, WK,
    BP, BN, BB, BR, BQ, BK
};

void print_bitboard(U64 bitboard)
{
    for (int rank = 7; rank >= 0; rank--)
    {
        for (int file = 0; file < 8; file++)
        {
            int square = rank * 8 + file;

            printf(" %d ", (bitboard & (1ULL << square)) ? 1 : 0);
        }
        printf("\n");
    }
}

void print_raw_bitboard(U64 bitboard)
{
    for (int square = 63; square >= 0; square--)
        printf("%d", (bitboard & (1ULL << square)) ? 1 : 0);

    printf("\n");
}

int main(void)
{
    U64 pieces[12] = {0};

    pieces[WP] =
        (1ULL << A2) |
        (1ULL << B2) |
        (1ULL << C2) |
        (1ULL << D2) |
        (1ULL << E2) |
        (1ULL << F2) |
        (1ULL << G2) |
        (1ULL << H2);

    pieces[BP] =
        (1ULL << A7) |
        (1ULL << B7) |
        (1ULL << C7) |
        (1ULL << D7) |
        (1ULL << E7) |
        (1ULL << F7) |
        (1ULL << G7) |
        (1ULL << H7);

    U64 occupied = pieces[WP] | pieces[BP];

    print_bitboard(occupied);
    print_raw_bitboard(occupied);

    return 0;
}
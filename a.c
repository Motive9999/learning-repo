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

static inline int get_bit(U64 bitboard, int square)
{
    return (bitboard >> square) & 1ULL;
}

static inline void set_bit(U64 *bitboard, int square)
{
    *bitboard |= 1ULL << square;
}

static inline void pop_bit(U64 *bitboard, int square)
{
    *bitboard &= ~(1ULL << square);
}

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

    set_bit(&pieces[WP], A2);
    set_bit(&pieces[WP], B2);
    set_bit(&pieces[WP], C2);
    set_bit(&pieces[WP], D2);
    set_bit(&pieces[WP], E2);
    set_bit(&pieces[WP], F2);
    set_bit(&pieces[WP], G2);
    set_bit(&pieces[WP], H2);

    set_bit(&pieces[BP], A7);
    set_bit(&pieces[BP], B7);
    set_bit(&pieces[BP], C7);
    set_bit(&pieces[BP], D7);
    set_bit(&pieces[BP], E7);
    set_bit(&pieces[BP], F7);
    set_bit(&pieces[BP], G7);
    set_bit(&pieces[BP], H7);

    U64 occupied = pieces[WP] | pieces[BP];

    print_bitboard(occupied);
    print_raw_bitboard(occupied);

    return 0;
}
#include <stdio.h>

// TODO:
// Create a struct that represents a House
// It should store:
//  - The address of the house
//  - The price in EUR
//  - The number of rooms
//  - The area of the house in square meters
typedef struct House {
    int address;
    int price_in_eur;
    int number_of_rooms;
    int house_square_meter;
}a;
// TODO:
// The market price of the houses is 400 EUR / square meters
// Create a function that takes a pointer to a house and decides if it's worth to buy
// (if the price is lower than the calculated price from it's area)
#define MARKET_PRICE 400
int worth_to_buy (struct House* houses)
{
    if (MARKET_PRICE > (houses->price_in_eur/houses->house_square_meter)) {
        return 1;
    } else {
        return 0;
    }
}
// TODO:
// Create a function that takes an array of houses (and it's length), and counts the
// houses that are worth to buy.
int number_worth_to_buy (struct House* houses, int len)
{
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (worth_to_buy(&houses[i])) {
        count++;
        }
    }
    return count;
}

int main()
{
    a house1 = {
    "BP",
    1,
    3,
    150
    };

    a house2 = {
    "TM",
    11115550,
    4,
    200
    };

    a array[2];
    array[0] = house1;
    array[1] = house2;

    printf("worth to buy house1:\t %d\n", worth_to_buy(&house1));
    printf("worth to buy house2:\t %d\n", worth_to_buy(&house2));
    printf("number worth to buy:\t %d\n", number_worth_to_buy(array,2));

    return 0;
}

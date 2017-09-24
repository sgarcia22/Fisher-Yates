#include <iostream>
#include "FisherYates.h"

using namespace std;

int main()
{
    //Declare an array
    int arr [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    //Construct a FisherYates Object
    FisherYates<int> * shuffle = new FisherYates<int>(arr);
    //Get shuffled list
    int * shuffled_arr = shuffle->fisher_algorithm(arr);
    //Print out shuffled list
    shuffle->print(shuffled_arr);
    return 0;
}

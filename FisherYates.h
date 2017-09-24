#ifndef FISHERYATES_H
#define FISHERYATES_H
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdexcept>

template <class element>
class FisherYates
{
    public:
        FisherYates(element * input);
        virtual ~FisherYates();
        element * fisher_algorithm(element * arr);
        int nrand(size_t range);
        void print(element * arr);

    private:
        element * input;
        size_t arr_size;
        int bucket_size;
};

#endif // FISHERYATES_H

template <class element>
//Constructor that takes in array of objects and gets the range of the random number
FisherYates<element>::FisherYates(element * in)
{
    if (!input)
        throw std::runtime_error ("Array is empty.\n ");
    input = in;
    element * curr = in;

    size_t array_size = 0;
    while (curr[array_size]) {
        ++array_size;
    }
    arr_size = array_size;

    //Gets the bucket size to make sure there are no biases in the rand()
    bucket_size = RAND_MAX / arr_size;

}

template <class element>
FisherYates<element>::~FisherYates()
{
    delete [] input;
}

template <class element>
//Output a random number
int FisherYates<element>::nrand(size_t size) {
    if (size < 0 || size > RAND_MAX)
        throw std::domain_error ("nrand(size); size is not a valid value. \n");


    //Returns number of seconds since the epoch and seeds that value into rand()
    srand((unsigned int) time(NULL));
    int bucket_number;
    //Keep calculating the random value while the value not in the non-biased buckets
    do
        bucket_number = rand() / bucket_size;
    while (bucket_number >= size);

    //Return the random number in the range
    return bucket_number;
}

template <class element>
//Implement the Fisher Yates algorithm to shuffle a list
element * FisherYates<element>::fisher_algorithm(element * arr) {
    //Keep track of how many rand() functions are called in order to prevent
    //bias that arises from the fact that the number of possibilities per
    //rand() call are greater than the number of combinations in a deck of cards
    int current_iteration = arr_size;
    //Shuffle the contents of the array without biases
    for (int i = 0; i < arr_size; ++i) {
        //Calculate random number
        int random = nrand(current_iteration);
        //Swap the values
        element temp = arr[i];
        arr[i] = arr[random];
        arr[random] = temp;
        //Decrease the current iteration
        --current_iteration;
    }

    return arr;

}

template <class element>
//Print out the contents of the array
void FisherYates<element>::print(element * arr) {
    for(int i = 0; i < arr_size; ++i)
        std::cout << arr[i] << "   ";
    std::cout << "\n";
}

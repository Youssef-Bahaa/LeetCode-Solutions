class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drink_bottels = numBottles;
        while (numBottles / numExchange) {
            drink_bottels += numBottles / numExchange;
            numBottles =  numBottles / numExchange + numBottles % numExchange;
        }
        return drink_bottels;
    }
};
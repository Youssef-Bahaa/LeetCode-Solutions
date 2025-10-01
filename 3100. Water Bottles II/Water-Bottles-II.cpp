class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int total = 0;
        int full_bottels = numBottles;
        int empty_bottels = 0;

        while (full_bottels > 0 or empty_bottels >= numExchange) {
            total += full_bottels;
            empty_bottels += full_bottels;
            full_bottels = 0;

            if (empty_bottels >= numExchange) {
                empty_bottels -= numExchange;
                full_bottels++;
                numExchange++;
            }
        }
        return total;
    }
};
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int total = numBottles;
        int empty = numBottles;

        while (empty >= numExchange) {
            empty -= numExchange;
            empty++;
            total++;
            numExchange++;
        }

        return total;
    }
};
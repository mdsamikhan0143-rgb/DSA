class FoodRatings {
public:
    unordered_map<string, string> foodCuisine;
    unordered_map<string, int> foodRating;

    unordered_map<string, set<pair<int, string>>> cuisineFoods;

    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {

        for (int i = 0; i < foods.size(); i++) {
            foodCuisine[foods[i]] = cuisines[i];
            foodRating[foods[i]] = ratings[i];

            cuisineFoods[cuisines[i]].insert(
                {ratings[i], foods[i]}
            );
        }
    }

    void changeRating(string food, int newRating) {

        string cuisine = foodCuisine[food];
        int oldRating = foodRating[food];

        cuisineFoods[cuisine].erase({oldRating, food});

        foodRating[food] = newRating;

        cuisineFoods[cuisine].insert({newRating, food});
    }

    string highestRated(string cuisine) {

        auto it = cuisineFoods[cuisine].end();
        --it;

        int maxRating = it->first;

        // Find lexicographically smallest food with max rating
        auto start = cuisineFoods[cuisine].lower_bound(
            {maxRating, ""}
        );

        return start->second;
    }
};
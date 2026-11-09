class MovieRentingSystem {
public:
    // movie -> {price, shop, movie}
    unordered_map<int, set<tuple<int, int, int>>> available;

    // Stores all rented movies: {price, shop, movie}
    set<tuple<int, int, int>> rented;

    // Stores price of each movie at each shop
    map<pair<int, int>, int> priceMap;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {

        for (auto &e : entries) {
            int shop = e[0];
            int movie = e[1];
            int price = e[2];

            available[movie].insert({price, shop, movie});

            priceMap[{shop, movie}] = price;
        }
    }

    vector<int> search(int movie) {

        vector<int> ans;

        auto &s = available[movie];

        int count = 0;

        for (auto it = s.begin(); it != s.end() && count < 5; it++) {

            auto [price, shop, movieId] = *it;

            ans.push_back(shop);
            count++;
        }

        return ans;
    }

    void rent(int shop, int movie) {

        int price = priceMap[{shop, movie}];

        // Remove from available movies
        available[movie].erase({price, shop, movie});

        // Add to rented movies
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {

        int price = priceMap[{shop, movie}];

        // Remove from rented movies
        rented.erase({price, shop, movie});

        // Add back to available movies
        available[movie].insert({price, shop, movie});
    }

    vector<vector<int>> report() {

        vector<vector<int>> ans;

        int count = 0;

        for (auto it = rented.begin();
             it != rented.end() && count < 5;
             it++) {

            auto [price, shop, movie] = *it;

            ans.push_back({shop, movie});

            count++;
        }

        return ans;
    }
};
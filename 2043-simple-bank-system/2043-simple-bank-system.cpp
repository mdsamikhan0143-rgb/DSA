class Bank {
public:
    vector<long long> balance;

    Bank(vector<long long>& balance) {
        this->balance = balance;
    }

    bool transfer(int account1, int account2, long long money) {
        if (account1 < 1 || account1 > balance.size() ||
            account2 < 1 || account2 > balance.size()) {
            return false;
        }

        if (balance[account1 - 1] < money) {
            return false;
        }

        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;

        return true;
    }

    bool deposit(int account, long long money) {
        if (account < 1 || account > balance.size()) {
            return false;
        }

        balance[account - 1] += money;

        return true;
    }

    bool withdraw(int account, long long money) {
        if (account < 1 || account > balance.size()) {
            return false;
        }

        if (balance[account - 1] < money) {
            return false;
        }

        balance[account - 1] -= money;

        return true;
    }
};
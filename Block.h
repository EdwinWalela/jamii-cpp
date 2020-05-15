#include "Transaction.h"
#include <vector>
#include <time.h>

class Block{
    public:
        long int timestamp;
        std::string prev_hash;
        std::string hash;
        std::vector<Transaction> transactions;

        Block();
};

Block::Block(){
    timestamp = time(NULL);
    hash = "00xhfff8";
}
        
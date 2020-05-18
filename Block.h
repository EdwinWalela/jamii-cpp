#include "Transaction.h"
#include <vector>
#include <string>
#include <time.h>

class Block{
    public:
        long int timestamp;
        int nonce;
        std::string prev_hash;
        std::string hash;

        std::vector<Transaction> tx;
        Block();
        void hashBlock();
};

Block::Block(){
    timestamp = time(NULL);
}

void Block::hashBlock(){
    std::string txs_hash;
    for (int i = 0; i < tx.size(); i++)
    {
        txs_hash += tx.at(i).hash;
    }
    
    hash = Crypto::SHA256Hash(txs_hash+std::to_string(nonce)+prev_hash);
    
}

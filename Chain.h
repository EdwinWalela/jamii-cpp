#include "Block.h"
#include <vector>

class Chain{
    private:
        Block create_genesis();
    public:
        std::vector<Block> chain;
        std::vector<Transaction> pending_tx;
        Chain();
        Block latestBlock();
        void add_block(Block);
        void add_pending_tx(Transaction);
};

Chain::Chain(){
    // Initalizae chain with genesis block
    chain.push_back(create_genesis());
}

Block Chain::create_genesis(){
    return Block();
}

Block Chain::latestBlock(){
    return chain.at(chain.size()-1);
}

void Chain::mine_block(){
    while(pending_tx.size()>1){
        for (int i = 0; i < pending_tx.size(); i++)
        {
            // this->pending_tx.
        }
        
    }
}

void Chain::add_pending_tx(Transaction tx){
    pending_tx.push_back(tx);
}

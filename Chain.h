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
        void add_tx(Transaction);
        int mine_block();
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

void Chain::add_tx(Transaction tx){
    pending_tx.push_back(tx);
}

int Chain::mine_block(){
    Block blk;
    if(chain.size()==0){
        blk.prev_hash = "00000000";
    }
    if(pending_tx.size()>1){
        blk.tx = pending_tx;
        pending_tx.empty();
    }

    while(blk.hash.substr(0,5) != "00000"){
        blk.hashBlock();
    }
    chain.push_back(blk);
    return blk.nonce;
}

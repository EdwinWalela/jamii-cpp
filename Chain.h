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
    Block genesis = Block();
    // std::cout<<"1"<<std::endl;
    genesis.tx.push_back(Transaction("0","miner",50.000));
    // std::cout<<"2"<<std::endl;
    genesis.prev_hash = Crypto::SHA256Hash("Jamii Chain");
    // std::cout<<"3"<<std::endl;
    genesis.hash_block();
    // std::cout<<"4"<<std::endl;
    return genesis;
}

Block Chain::latestBlock(){
    return chain.at(chain.size()-1);
}

void Chain::add_tx(Transaction tx){
    pending_tx.push_back(tx);
}

int Chain::mine_block(){
    Block blk;
    if(pending_tx.size()>0){
        blk.tx = pending_tx;
        pending_tx.empty();
    }

    blk.hash_block();
    chain.push_back(blk);
    return blk.nonce;
}

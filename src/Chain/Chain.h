#include "../Block/Block.h"
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
    genesis.tx.push_back(Transaction("0","miner",50.000));
    genesis.prev_hash = Crypto::SHA256Hash("Jamii Chain");
    genesis.hash_block();
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
        Transaction coinBase = Transaction("","miner",REWARD);
        blk.tx.push_back(coinBase);
        // Concat pending txs with coinbase
        blk.tx.insert(blk.tx.end(),pending_tx.begin(),pending_tx.end());
        // Empty pending txs
        pending_tx.empty();
    }
    // Calculate block's hash
    blk.hash_block();
    // Add block to chain
    blk.prev_hash = latestBlock().hash;
    chain.push_back(blk);
    return blk.nonce;
}

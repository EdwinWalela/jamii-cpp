#include "Block.h"
#include <vector>

class Chain{
    private:
        Block create_genesis();
    public:
        std::vector<Block> chain;
        Chain();
        

};

Chain::Chain(){
    // Initalizae chain with genesis block
    chain.push_back(create_genesis());
}

Block Chain::create_genesis(){
    return Block();
}
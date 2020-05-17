#include <iostream>
#include "Chain.h"

int main(){
    Chain jamii = Chain();
    Block genesis_block = jamii.chain.at(0);
    std::string genessis_trans_hash = genesis_block.hash;

    std::cout<<"jamii genesis transaction hash:"<<genessis_trans_hash;
}

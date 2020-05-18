#include <iostream>
#include "Chain.h"

int main(){
    Chain jamii = Chain();
    Transaction new_tx = Transaction("from","to",50.000);
    jamii.add_tx(new_tx);
    std::cout<<"Mining block (Dificulty = 5)"<<std::endl;
    int nonce = jamii.mine_block();
    std::cout<<"Block mined"<<std::endl;
    std::cout<<"Nonce:"<<nonce<<std::endl;
    std::cout<<"Hash:"<<jamii.latestBlock().hash<<std::endl;
}

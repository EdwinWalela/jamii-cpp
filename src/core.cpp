#define DIFF 4
#define REWARD 50.00
#include <iostream>
#include "./Chain/Chain.h"

int main(){
    Chain jamii = Chain();
    Transaction new_tx = Transaction("jamii","jamii",50.000);
    jamii.add_tx(new_tx);
    std::cout<<"Mining block (Dificulty = "<<DIFF<<")"<<std::endl;
    int nonce = jamii.mine_block();
    std::cout<<"Block mined"<<std::endl;
    std::cout<<"Nonce:"<<nonce<<std::endl;
    std::cout<<"Hash:"<<jamii.latestBlock().hash<<std::endl;
    std::cout<<"Block's Transaction Volume: "<<jamii.latestBlock().tx_volume<<std::endl;
    std::cout<<"Block Verifiyer: "<<jamii.latestBlock().tx.at(0).to<<std::endl;

}

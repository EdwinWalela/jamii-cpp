#include <iostream>
#include "Chain.h"

int main(){
    Chain jamii = Chain();

    Transaction tx_1 = Transaction("me","you",2.5);
    Transaction tx_2 = Transaction("me","you",13.89);
    Transaction tx_3 = Transaction("you","me",5.3);

    Block block_1 = Block();
    block_1.transactions.push_back(tx_1);
    block_1.transactions.push_back(tx_2);
    block_1.transactions.push_back(tx_3);

    jamii.chain.push_back(block_1);
    std::cout<<jamii.chain.at(1).transactions.at(1).hash;
}

#include "../Transaction/Transaction.h"
#include <vector>
#include <string>
#include <time.h>

class Block{
    public:
        long int timestamp;
        long int nonce = 0;
        std::string prev_hash;
        std::string hash;

        std::vector<Transaction> tx;
        Block();
        void hash_block();
        bool isHashValid();
};

Block::Block(){
    timestamp = time(NULL);
}

bool Block::isHashValid() {
	for (int i = 0; i < DIFF;i++) {
		if (hash.at(i) == '0') {
			continue;
		}else {
			return false;
		}
	}
	return true;
}

void Block::hash_block(){
    std::string txs_hash;
    for (int i = 0; i < tx.size(); i++)
    {
        txs_hash += tx.at(i).hash;
    }
    hash = Crypto::SHA256Hash(txs_hash+std::to_string(nonce)+prev_hash);
    while(!isHashValid()){
        hash = Crypto::SHA256Hash(txs_hash+std::to_string(nonce)+prev_hash);
        nonce++;
    }
}
#include "../Transaction/Transaction.h"
#include <vector>
#include <string>
#include <time.h>

class Block{
    public:
        long int timestamp;
        long int nonce = 0;
        float tx_volume;
        int height;
        std::string prev_hash;
        std::string hash;
        std::string merkle_root; // TODO

        std::vector<Transaction> tx;
        Block();
        void hash_block();
        bool isHashValid();
        float sum_volume();
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

float Block::sum_volume(){
    float vol;
    for (int i = 0; i < tx.size(); i++)
    {
        vol += tx.at(i).value;
    }
    return vol;
}

void Block::hash_block(){
    tx_volume = sum_volume();
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
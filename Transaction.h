#include <string>
#include <vector> 
#include "crypto.h"

class Transaction{
    private:
        void hash_tx();
    public:
        std::string from;
        std::string to;
        float value;
        std::string hash;

        Transaction(std::string _from,std::string _to, float _value);
};

Transaction::Transaction(std::string _from,std::string _to, float _value){
    from = _from;
    to = _to;
    value = _value;
    hash_tx();
}

void Transaction::hash_tx(){
    hash = Crypto::SHA256Hash(from+to+std::to_string(value));
}


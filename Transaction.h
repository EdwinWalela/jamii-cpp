#include <string.h>
// Override std::string highlighting in vscode 
#include <vector> 

class Transaction{
    public:
        std::string from;
        std::string to;
        float value;

        Transaction(std::string _from,std::string _to, float _value);
};

Transaction::Transaction(std::string _from,std::string _to, float _value){
    from = _from;
    to = _to;
    value = _value;
}
#include <string>
#include "../../include/picosha2.h"

class Crypto{
    public:
        static std::string SHA256Hash(std::string);
};

std::string Crypto::SHA256Hash(std::string src){
    std::string digest;
	picosha2::hash256_hex_string(src, digest);
	return digest;
}

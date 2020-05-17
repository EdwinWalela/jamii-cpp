#include <string>
#include "picosha2.h"

class CryptoHash{
    public:
        static std::string SHA256Hash(std::string _str);
};
std::string CryptoHash::SHA256Hash(std::string src){
    std::vector<unsigned char> hash(picosha2::k_digest_size);
    picosha2::hash256(src.begin(), src.end(), hash.begin(), hash.end());

    std::string hex_str = picosha2::bytes_to_hex_string(hash.begin(), hash.end());
    return hex_str;
}
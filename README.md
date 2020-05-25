# Jamii Chain

## Inspiration
[Bitcoin's Implementation](https://bitcoin.org/bitcoin.pdf) of a trust-based peer-to-peer network  
## Goal
To implement an peer-to-peer transparent blockchain network. 

## Compiler
```GCC version 7.4.0```

## Installation
1. Clone into ```jamii```
2. Compile ```g++ ./src/core.cpp -o jamii.exe```
3. Run ```jamii``` 


## Documentation 

### Definition of Terms
```reward``` - Number of coins to reward miner for verifying a block

```tx``` - Transaction

```Genesis block``` first block in the blockchain

```Coinbase``` - Transaction containing miner's reward

```Nonce``` - Number of tries a miner attempts to calculate the target hash

```Digest``` - Output of hash function (the hash)

## Verification Algorithim
```Proof of Work```

Target hash - Output hash has to start with 4 zeros

## Project Structure

### ```/src``` 
Source code for the blockchain

```./Tranasction``` - Transaction definition

```./Block``` - Block definition

```./Chain``` - Chain definition

```./crypto``` - Hash Functions definition (SHA256) using Picosha2 Library

```./core.cpp``` - Client definition

Client Functions:
 - Mine blocks
 - Create Transactions

### ```/include```

Third party libraries

```./picosha2.h``` - SHA256 Hash Function definition

## TODO
- [ ] Blockchain validity verification
- [ ] Signing transactions (Elliptic Curve)
- [ ] Merkle Trees 
- [ ] Unit Tests

## Contribution
Open to anyone. Create a pull request

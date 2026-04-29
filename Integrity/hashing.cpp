#include <iostream>
#include <string>
#include <functional>
using namespace std;

// HASHING FUNCTION


string createHash(string timeStamp, string previousHash, int grant, string name) {
    string data = "";

    // SKIPS IF PREVIOUS HASH IS EMPTY
    if (!previousHash.empty()) {
        data += previousHash;
    }

    data += timeStamp;
    data += to_string(grant);
    data += name;

    // TURNS COMBINED STRINGS INTO HASH
    size_t hashed = hash<string>{}(data);

    return to_string(hashed);
}


// VALIDATE HASH
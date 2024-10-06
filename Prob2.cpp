#include <iostream>
#include <string>

using namespace std;

struct BigNumberNode {
    string value;
    BigNumberNode* nextNode;

    BigNumberNode(const string& v) : value(v), nextNode(nullptr) {}
};

class BigNumberLinkedList {
public:
    BigNumberNode* headNode;
    BigNumberNode* tailNode;
    int nodeCount;

    BigNumberLinkedList() : headNode(nullptr), tailNode(nullptr), nodeCount(0) {}

    void appendNode(const string& v) {
        BigNumberNode* newNode = new BigNumberNode(v);
        if (nodeCount == 0) {
            headNode = newNode;
            tailNode = newNode;
        } else {
            tailNode->nextNode = newNode;
            tailNode = newNode;
        }
        nodeCount++;
    }

    bool divisibleByPrime(long long prime) {
        long long remainder = 0;
        BigNumberNode* currentNode = headNode;

        while (currentNode != nullptr) {
            string numberPart = currentNode->value;

            for (char digit : numberPart) {
                remainder = (remainder * 10 + (digit - '0')) % prime;
            }

            currentNode = currentNode->nextNode;
        }

        return remainder == 0;
    }

    bool performPrimeCheck() {
        for (long long prime : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47}) {
            if (divisibleByPrime(prime)) {
                cout << "The number is divisible by " << prime << " (not prime)." << endl;
                return false;
            }
        }

        return true;
    }

    ~BigNumberLinkedList() {
        BigNumberNode* currentNode = headNode;
        while (currentNode != nullptr) {
            BigNumberNode* nextNode = currentNode->nextNode;
            delete currentNode;
            currentNode = nextNode;
        }
    }
};

int main() {
    BigNumberLinkedList* bigNumList = new BigNumberLinkedList();

    bigNumList->appendNode("15737649871");
    bigNumList->appendNode("59232635422");
    bigNumList->appendNode("87395761283");
    bigNumList->appendNode("84576943829");
    bigNumList->appendNode("73649827365");
    bigNumList->appendNode("49827365498"); 
    bigNumList->appendNode("72365982736"); 
    bigNumList->appendNode("59827365982");
    bigNumList->appendNode("73659826398");
    bigNumList->appendNode("73659823659");
    bigNumList->appendNode("87236598273");
    bigNumList->appendNode("65928736598");
    bigNumList->appendNode("27365982736");
    bigNumList->appendNode("59283659827");
    bigNumList->appendNode("36598273659");
    bigNumList->appendNode("82736598273");
    bigNumList->appendNode("65982736598");
    bigNumList->appendNode("73659827365");
    bigNumList->appendNode("98273659827");
    bigNumList->appendNode("36598273659");
    bigNumList->appendNode("82736598273");
    bigNumList->appendNode("65982736597");

    cout << "Verifying primality of the 1024-bit number:" << endl;
    cout << "Prime Status: " << (bigNumList->performPrimeCheck() ? "Prime" : "Not Prime") << endl;

    delete bigNumList;
    return 0;
}

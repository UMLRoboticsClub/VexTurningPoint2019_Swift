#define DEBUG

#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include <cstdio>
#include <cstring>
#include <climits>

#include "pros/apix.h"

#include "crc.h"
#include "serial.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

const char *header = "zz ";

void (*doThing)(vector<Point>&);

void parseInput(const char *buf, vector<Point> &targets){
    int len = strlen(buf);
#ifdef DEBUG
    cout << "input: [" << buf << "]" << endl;
    cout << "size : " << len << endl;
#endif
    int pktIndex = 0;

    //check header
    const char *header = "zz ";
    const int headerSize = strlen(header);

    if(len < headerSize + 8){
#ifdef DEBUG
        cout << "packet messed up: too small" << endl;
#endif
        return;
    }

    while(isspace(buf[pktIndex + 1])) ++pktIndex; //skip spaces

    for(; pktIndex < headerSize; ++pktIndex){
        if(header[pktIndex] != buf[pktIndex]){
#ifdef DEBUG
            cout << "packet messed up: bad header" << endl;
#endif
            return;
        }
    }




//TODO:sometimes crc fails for no reason wtf

    


#ifdef DEBUG
    cout << "packet header ok" << endl;
#endif

    while(isspace(buf[pktIndex + 1])) ++pktIndex; //skip spaces

    char *end;
    const char *afterHeader = buf + pktIndex - 1;
    //get size
    const int size = strtol(afterHeader, &end, 10);
    //digits of 'size'
    const int sizeSize = end - afterHeader;
    for(int i = 0; i < size; ++i){
        //get the rest of the numbers
        //int num = strtol(end, &end, 10);
        //targets.emplace_back((int)strtol(end, &end, 10), num);
        targets.emplace_back((int)strtol(end, &end, 10), (int)strtol(end, &end, 10));

#ifdef DEBUG
        cout << "point:" << '[' << targets.back().second << "," << targets.back().first << ']' << endl;
#endif

    }

    //cout << "size size: " << sizeSize << endl;

    char *dataStart = (char*)buf + pktIndex + sizeSize;
    const int dataLen = end - buf - (dataStart - buf);

#ifdef DEBUG
    for(int i = 0; i < dataLen; ++i){
        cout << *(dataStart + i);
    }
    cout << endl;
#endif

    uint32_t repcrc = strtol(end, &end, 10);
    uint32_t gencrc = crc32buf(dataStart, dataLen);

#ifdef DEBUG
    cout << "reported crc: " << repcrc << endl;
    cout << "generated crc: " << gencrc << endl;
#endif

    if(repcrc != gencrc) {

#ifdef DEBUG
        cout << "Bad CRC!" << endl;
        cout << endl;
        fflush(stdout);
#endif

        targets.clear();
        return;
    }

#ifdef DEBUG
    cout << "CRCs match!" << endl;
    cout << endl;
    fflush(stdout);
#endif

}

void setVisionCallback(void (*callback)(vector<Point>&)){
    doThing = callback;
}

void readAndParseVisionData(void*){
    int headerLen = strlen(header);
    vector<Point> targets;
    char buf[128];

    size_t size = 128;

    while(true){
        cin.getline(buf, 128);

        //skip if header doesn't exist
        if(strncmp(buf, header, headerLen) != 0){
#ifdef DEBUG
            cout << "header doesn't exist:[" << buf << "]" << endl;
#endif
            continue;
        }
#ifdef DEBUG
        cout << "header exists" << endl;
#endif

        targets.clear();
        parseInput(buf, targets);
        doThing(targets);
    }
}

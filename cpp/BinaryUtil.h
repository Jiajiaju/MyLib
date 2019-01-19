//
//  BinaryUtil.h
//  MyLibCPP
//
//  Created by welove-jiajiaju on 2019/1/19.
//  Copyright © 2019 welove-jiajiaju. All rights reserved.
//

#ifndef BinaryUtil_h
#define BinaryUtil_h

#include <string>

extern const unsigned int ShortSize = 2;
extern const unsigned int UnsignedShortSize = 2;
extern const unsigned int IntSize = 4;
extern const unsigned int UnsignedIntSize = 4;
extern const unsigned int FloatSize = 4;

extern inline std::string getString(unsigned char* byte, int whence, int length){
    unsigned char* data = new unsigned char[length + 1];
    for (int i = 0; i < length; ++i){
        data[i] = byte[i + whence];
    }
    data[length] = '\0';
    std::string str(reinterpret_cast<char*>(data));
    delete[] data;
    return str;
}


extern inline unsigned short getUnsignedShort(unsigned char* byte, int whence){
    unsigned short number = 0;
    for (int i = 0; i < UnsignedShortSize; ++i){
        number = (number << 8) | byte[i + whence];
    }
    return number;
}

extern inline short getShort(unsigned char* byte, int whence){
    short number = 0;
    for (int i = 0; i < ShortSize; ++i){
        number = (number << 8) | byte[i + whence];
    }
    return number;
}


extern inline unsigned int getUnsignedInt(unsigned char* byte, int whence){
    unsigned int number = 0;
    for (int i = 0; i < UnsignedIntSize; ++i){
        number = (number << 8) | byte[i + whence];
    }
    return number;
}

extern inline int getInt(unsigned char* byte, int whence){
    int number = 0;
    for (int i = 0; i < IntSize; ++i){
        number = (number << 8) | byte[i + whence];
    }
    return number;
}


extern inline float getFloat(unsigned char* byte, int whence){
    unsigned char* data = new unsigned char[FloatSize + 1];
    for (int i = 0; i < FloatSize; ++i){
        data[i] = byte[i + whence];
    }
    data[FloatSize] = '\0';
    float number = *(reinterpret_cast<float*>(data));
    delete[] data;
    return number;
}

#endif /* BinaryUtil_h */

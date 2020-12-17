//
// Created by brian on 14/12/2020.
//

#include "ManipString.h"

std::vector<std::string> ManipString::DecoupeString(std::string s, std::vector<std::string> *res, char x){
    if(!s.empty()){
        int index_first = 0;
        int index_last =1;
        while(s.at(index_last) != x){
            if((index_last+1)==s.size()){
                res->push_back(s.substr(index_first,index_last+1));
                return *res;
            }
            index_last++;
        }
        res->push_back(s.substr(index_first,index_last));
        s=s.substr(index_last+1);
        return DecoupeString(s,res,'<');
    }
}

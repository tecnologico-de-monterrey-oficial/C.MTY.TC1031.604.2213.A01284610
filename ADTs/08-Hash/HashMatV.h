#ifndef HashMatV_h
#define HashMatV_h

#include<vector>

class HashMatV {
private:
    vector<string> hashTable[99];
    bool status[99];
public:
    HashMatV();
    int hashFunction(string matricula);
    bool findMatricula(string matricula);
    void addMatricula(string matricula);
    void deleteMatricula(string matricula);
    void print();
};

HashMatV::HashMatV() {

}

int HashMatV::hashFunction(string matricula) {
    try {
        int numMatricula = stoi((matricula.substr(1,8)));
        return numMatricula % 99;
    } catch (invalid_argument &e) {
        return -1;
    }   
}

bool HashMatV::findMatricula(string matricula) {
    // Obtenmos la dirección base con la función hash
    int index = hashFunction(matricula);
    if(index>=0){
        vector<string>:: iterator it;
        it = find(hashTable[index].begin(), hashTable[index].end(), matricula);
        if (it!= hashTable[index].end())
        {
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

void HashMatV::addMatricula(string matricula) {
    // Obtenmos la dirección base con la función hash
    int index = hashFunction(matricula);
    if (index >= 0) {
        vector<string>:: iterator it;
        it = find(hashTable[index].begin(), hashTable[index].end(), matricula);
        if (it!= hashTable[index].end()){
            return;
        }
        hashTable[index].push_back(matricula);
        return;
    } else {
        throw invalid_argument("La matrícula no es una matrícula");
    }
}

void HashMatV::deleteMatricula(string matricula) {
    // Obtenmos la dirección base con la función hash
    int index = hashFunction(matricula);
    if (index >= 0) {
        vector<string>:: iterator it;
        if(it != hashTable[index].end()){
            hashTable[index].erase(it);
            return;
        }
        return;
        throw invalid_argument("La matrícula no se encuentra");
    } else {
        throw invalid_argument("La matrícula no es una matrícula");
    }
}

void HashMatV::print() {
    for (int i=0; i<99; i++) {
        cout << i << " ";
        for (auto mat : hashTable[i]){
        cout << mat << " ";
        }
        cout << endl;
    }
}


#endif
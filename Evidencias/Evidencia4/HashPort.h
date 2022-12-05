#ifndef HashPort_h
#define HashPort_h

using namespace std;

class HashPort {
private:
    string hashTable[37];
    bool status[37];
public:
    HashPort();
    int hashFunction(string Port);
    bool findPort(string Port);
    string& operator[](int index);
    void addPort(string Port);
    void deletePort(string Port);
    void print();
};

HashPort::HashPort() {

}

string &HashPort::operator[](int index){
    return hashTable[index];
}

int HashPort::hashFunction(string Port) {
    try {

        uint32_t hash = 0x811c9dc5;
        uint32_t prime = 0x1000193;

        for(int i = 0; i < Port.size(); ++i) {
            uint8_t value = Port[i];
            hash = hash ^ value;
            hash *= prime;
        }
        return hash % 37;

    } catch (invalid_argument &e) {
        return -1;
    }   
}

bool HashPort::findPort(string Port) {
    // Obtenmos la dirección base con la función hash
    int index = hashFunction(Port);
    int baseIndex = index;
    if (index >= 0) {
        while (hashTable[index] != "" || status[index]) {
            // Validar si el elemento se encuentra en el índice base
            if (hashTable[index] == Port) {
                // ya lo encontré
                return true;
            } else {
                index = (index + 1) % 37;
                // Validamos si ya le dimos la vuelta
                if (index == baseIndex) {
                    return false;
                }
            }
        }
        // no lo encontramos
        return false;
    } else {
        return false;
    }
}

void HashPort::addPort(string Port) {
    // Obtenmos la dirección base con la función hash
    int index = hashFunction(Port);
    int baseIndex = index;
    if (index >= 0) {
        while (hashTable[index] != "") {
            index = (index + 1) % 37;
            // Validamos si ya le dimos la vuelta
            if (index == baseIndex) {
                throw invalid_argument("La tabla esta llena");
                return;
            }
        }
        // Insertamos el dato
        hashTable[index] = Port;
        // Actualizamos el status
        status[index] = false;
    } else {
        throw invalid_argument("La matrícula no es una matrícula");
    }
}

void HashPort::deletePort(string Port) {
    // Obtenmos la dirección base con la función hash
    int index = hashFunction(Port);
    int baseIndex = index;
    if (index >= 0) {
        while (hashTable[index] != "" || status[index]) {
            // Validar si el elemento se encuentra en el índice base
            if (hashTable[index] == Port) {
                // ya lo encontré
                // lo borro (inicializo con "")
                hashTable[index] = "";
                // Cambiar el status
                status[index] = true;
                // nos salimos
                return;
            } else {
                // La prueba lineal
                index = (index + 1) % 37;
                // Validamos si ya le dimos la vuelta
                if (index == baseIndex) {
                    throw invalid_argument("La matrícula no se encuentra");
                    return; 
                }
            }
        }
        throw invalid_argument("La matrícula no se encuentra");
    } else {
        throw invalid_argument("La matrícula no es una matrícula");
    }
}

void HashPort::print() {
    for (int i=0; i<37; i++) {
        cout << i << " " << hashTable[i] << endl;
    }
}


#endif
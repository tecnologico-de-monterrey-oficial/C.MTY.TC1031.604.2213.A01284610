#pragma once

struct Log {
    string date;
    string newdate;
    int month;
    int year;
    string time;
    string entry;
    string ubi;
    string key;

    Log();
    Log(string date, string time, string entry, string ubi);
    bool operator<(Log log);
    bool operator>(Log log);
    bool operator<(string value);
    bool operator>(string value);
    bool operator==(string value);



};

Log::Log(){
    // this->date = nullptr;
    // this->time = nullptr;
    // this->entry = nullptr;
    // this->ubi = nullptr;
    // this->key = nullptr;
}

Log::Log(string date, string time, string entry, string ubi){
    this->date = date;
    this->time = time;
    this->entry = entry;
    this->ubi = ubi;

    this->month = stoi(date.substr(3,2));
    this->year = stoi(date.substr(6,4));

    this-> newdate = date.substr(6,4) + date.substr(3,2) + date.substr(0,2);
    this->key = ubi.substr(0,3) + "-" + newdate + "-" + time;
    //cambiar año mes dia
}

bool Log::operator<(Log log){
    return this->key < log.key;
}

bool Log::operator>(Log log){
    return this->key < log.key;
}

bool Log::operator<(string value){
    return strcmp(this->ubi.substr(0,3).c_str(), value.c_str())<0;
}

bool Log::operator>(string value){
    return strcmp(this->ubi.substr(0,3).c_str(), value.c_str())>0;
}

bool Log::operator==(string value){
    return strcmp(this->ubi.substr(0,3).c_str(), value.c_str())==0;
}

#pragma once

struct Log {
    string date;
    string time;
    string entry;
    string ubi;
    string key;

    Log(string date, string time, string entry, string ubi);
    bool operator<(Log log);
};

Log::Log(string date, string time, string entry, string ubi){
    this->date = date;
    this->time = time;
    this->entry = entry;
    this->ubi = ubi;

    string newdate = date.substr(6,4) + date.substr(3,2) + date.substr(0,2);
    this->key = ubi + "-" + newdate + "-" + time;
    //cambiar año mes dia
}

bool Log::operator<(Log log){
    return this->key < log.key;
}
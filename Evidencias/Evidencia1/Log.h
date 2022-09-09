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
    this->key = ubi + "-" + date + "-" + time;
    //cambiar año mes dia
}

bool Log::operator<(Log log){
    return this->key < log.key;
}
//
// Created by Simon on 2020/1/8.
//

#ifndef MAIN_RESTCLIENT_H
#define MAIN_RESTCLIENT_H

#include <map>
#include <string>
#include <cstdio>
#include <future>
#include "http/connection.h"
#include "thread_pool/threadpool.h"

namespace restclient {

    typedef struct {
        void *memory;
        size_t size;
    } MemoryStruct;

    std::string paramToString(const http::Param &p);

    static inline std::string &ltrim(std::string &);

    static inline std::string &rtrim(std::string &);

    static inline std::string &trim(std::string &);


    class RestClient {
    private:
        std::shared_ptr<http::Connection> conn;
        std::string baseUrl;
        std::shared_ptr<http::ThreadPool> worker;
    public:

        explicit RestClient(std::string &baseUrl) {
            this->conn = std::make_shared<http::Connection>(baseUrl);
            this->worker = std::make_shared<http::ThreadPool>(std::thread::hardware_concurrency());
        }

        void addRequest(const http::Request &req);

    };


}

#endif //MAIN_RESTCLIENT_H

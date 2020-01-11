//
// Created by Simon on 2020/1/8.
//

#ifndef MAIN_CONNECTION_H
#define MAIN_CONNECTION_H

#include <curl/curl.h>
#include <string>
#include "RestClient.h"
#include <iostream>

namespace Http{

    typedef struct {
        double totalTime;
        double nameLookupTime;
        double connectTime;
        double appConnectTime;
        double preTransferTime;
        double startTransferTime;
        double redirectTime;
        int redirectCount;
    } Request;

    typedef struct {
        std::string baseUrl;
        restclient::Header headers;
        int timeout;
        bool followRedirects;
        int maxRedirects;
        bool noSignal;
        struct {
            std::string username;
            std::string password;
        } basicAuth;

        std::string certPath;
        std::string certType;
        std::string keyPath;
        std::string keyPassword;
        std::string customUserAgent;
        std::string uriProxy;
        std::string unixSocketPath;
        Request lastRequest;
    } Config;

    class Connection{
    private:

        CURL* curl;
        std::string baseUrl;
        restclient::Header headerFields;
        int timeout;
        bool followRedirects;
        int maxRedirects;
        bool noSignal;
    public:
        Request request;

        explicit Connection(const std::string& baseUrl);
        ~Connection();

        restclient::MemoryStruct performCurlRequest(const std::string& uri, size_t callBack(char *, size_t , size_t, void *));


    };
}

#endif //MAIN_CONNECTION_H
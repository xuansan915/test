#ifndef CURL_CLIENT_H
#define CURL_CLIENT_H
#include <iostream>
#include <curl/curl.h>
//#include "zlib.h"
#include <vector>
#include <string>
#include <unistd.h>
#include <memory.h>
#include <json/json.h>
#include <sstream>
class curl_client
{
    public:
        curl_client();
        virtual ~curl_client();

     public:
        static std::size_t receive_data(void *contents, std::size_t size, std::size_t nmemb, void *stream);
        // HTTP 下载文件的回掉函数
        static std::size_t writedata2file(void *ptr, std::size_t size, std::size_t nmemb, FILE *stream);
        // 文件下载接口
        static int download_file(std::string & url, std::string &outfilename);
        // http get 请求
        static CURLcode HttpGet(const std::string & strUrl, std::string & strResponse,int nTimeout);
        // htpp post 请求
        static CURLcode HttpPost(const std::string & strUrl, std::string szJson,std::string & strResponse,int nTimeout);

};

#endif // CURL_CLIENT_H

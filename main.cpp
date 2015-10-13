#include <iostream>
#include "HdlEngine/HdlEngine.h"
#include <sys/time.h>
#include <glog/logging.h>

using namespace std;

int main(int argc, char** argv)
{
        struct timeval start, end;
        gettimeofday(&start, NULL);
////    for(int i = 0; i < 101; ++i){
////       victl:: hdlEngine.processNextFrame();
////    }
    int count = 0;
#ifdef OFFLINE
    if (argc < 3)
    {
        cout << "Error: too few arguments'" << endl
             << "./Usage: HdlEngine 'hdl_file' 'output_dir'" << endl;
        return -1;
    }
    victl::HdlEngine hdlEngine(argv[1]);
    while(hdlEngine.processNextFrame()){++count;}
    hdlEngine.write3bPng("map_tmp/final-3b.png");
    hdlEngine.visualLocalMap("map_tmp/visualized-final.png");
    for(uint i = 0; i < hdlEngine.counter.size(); ++i)
    {
        DLOG(INFO) << "height:" << i*200/double(1000) << '\t' << "num:" << hdlEngine.counter[i];
    }
#else
    victl::HdlEngine hdlEngine;
    while(hdlEngine.processNextFrame()){++count;}
    hdlEngine.write3bPng("map_tmp/final-3b.png");
    hdlEngine.visualLocalMap("map_tmp/visualized-final.png");
#endif
        gettimeofday(&end, NULL);
        long useconds = end.tv_usec - start.tv_usec;
        long seconds  = end.tv_sec  - start.tv_sec;
        DLOG(INFO) << "Finish time: " << seconds <<"seconds  "<<useconds<<"microseconds";
    return 0;
}


// Copyright 2018 Aglikov Ilya

#ifndef MODULES_QUEUE_INCLUDE_QUEUE_APP_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_APP_H_

#include <string>

class QueueApp {
 public:
    QueueApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int clocks;
        int capacity;
        double jobIntens;
        double procRate;
    } Arguments;
};

#endif  // MODULES_QUEUE_INCLUDE_QUEUE_APP_H_

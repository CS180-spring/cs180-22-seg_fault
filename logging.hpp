#ifndef _LOGGING_HPP_
#define _LOGGING_HPP_

#include <string>

class logging {
    public:
        logging(std::string file_name);
        void newLog(std::string logText);
    private:
        std::string logFile;
};

#endif //_LOGGING_HPP_
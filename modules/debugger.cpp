#include "debugger.h"
std::string Debugger::selectLoggerLevel(DebugLevel logType){
    switch (logType) {
    case DEBUG:
        return "[DEBUG] ";
    case WARN:
        return "[WARN] ";
    default:
        return "[INFO] ";
    }
}
/*
Debugger::~Debugger(){
//    if (m_out){
//        delete m_out;
//        m_out = nullptr;
//    }
}*/

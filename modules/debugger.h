#include <iostream>
#include <string>
#include "static_values.h"

using std::string;

static DebugLevel LogLevel = DEBUG;

class Debugger{
    std::ostream *m_outFile = nullptr;
    std::ostream *m_out = nullptr; // Para el output por consola
    std::string selectLoggerLevel(DebugLevel logType);
    
public:
Debugger(){
     
        std::string LogLevelStr = selectLoggerLevel(LogLevel);
        #ifdef INTERNAL_DEBUGGER
    if (!m_out)
        m_out = &std::cout;

    
#endif
(*m_out) << '\n' << LogLevelStr;
    }
    template<typename T>
    Debugger& operator << (const T& object);
 //   ~Debugger();
};


template<typename T>
Debugger& Debugger::operator<<(const T& object)
{
    (*m_out)  << object ;
    return *this;
}

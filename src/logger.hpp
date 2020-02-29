#ifndef LOGGER_HPP_INCLUDED
#define LOGGER_HPP_INCLUDED

#include <array>
#include <fstream>
#include <iostream>
#include <mutex>
#include <string>
#include <memory>
#include <functional>

namespace vkBasalt
{

    enum class LogLevel : uint32_t
    {
        Trace = 0,
        Debug = 1,
        Info  = 2,
        Warn  = 3,
        Error = 4,
        None  = 5,
    };

    class Logger
    {

    public:
        Logger();
        ~Logger();

        static void trace(const std::string& message);
        static void debug(const std::string& message);
        static void info(const std::string& message);
        static void warn(const std::string& message);
        static void err(const std::string& message);
        static void log(LogLevel level, const std::string& message);

        static LogLevel logLevel()
        {
            return s_instance.m_minLevel;
        }

    private:
        static Logger s_instance;

        const LogLevel m_minLevel;

        std::mutex m_mutex;

        std::unique_ptr<std::ostream, std::function<void(std::ostream*)>> m_outStream;

        void emitMsg(LogLevel level, const std::string& message);

        static LogLevel getMinLogLevel();

        static std::string getFileName();
    };

} // namespace vkBasalt

#endif // LOGGER_HPP_INCLUDED

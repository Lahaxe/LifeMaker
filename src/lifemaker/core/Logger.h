/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#ifndef _30a37e0c_2ffb_4007_924d_2c32915654cd
#define _30a37e0c_2ffb_4007_924d_2c32915654cd

#ifdef USE_LOG4CPP
#include <map>
#include <string>

#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#else
#include <QDebug>
#endif

#ifdef USE_LOG4CPP
namespace lifemaker
{

    static std::map<std::string, log4cpp::Priority::PriorityLevel> level_dictionary =
    {
        { "", log4cpp::Priority::DEBUG },       // Default
        { "ERROR", log4cpp::Priority::ERROR },
        { "WARNING", log4cpp::Priority::WARN },
        { "INFO", log4cpp::Priority::INFO },
        { "DEBUG", log4cpp::Priority::DEBUG }
    };

    void initialize_logger(std::string const & priority);

    log4cpp::CategoryStream getLogger(log4cpp::Priority::PriorityLevel const & level);

    log4cpp::CategoryStream getLogger(std::string const & priority);

    log4cpp::CategoryStream loggerDebug();

    log4cpp::CategoryStream loggerError();

    log4cpp::CategoryStream loggerInfo();

    log4cpp::CategoryStream loggerWarning();

} // namespace lifemaker

    #define LOGGER_DEBUG lifemaker::loggerDebug()
    #define LOGGER_ERROR lifemaker::loggerError()
    #define LOGGER_WARNING lifemaker::loggerWarning()
    #define LOGGER_INFO lifemaker::loggerInfo()

#else

    #define LOGGER_DEBUG (qDebug() << "DEBUG: ")
    #define LOGGER_ERROR (qCritical() << "ERROR: ")
    #define LOGGER_WARNING (qWarning() << "WARNING: ")
    #define LOGGER_INFO (qDebug() << "INFO: ")

#endif

#endif // _30a37e0c_2ffb_4007_924d_2c32915654cd

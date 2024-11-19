#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Logger {
public:
    virtual void log(const std::string& message) = 0;
};

class FileLogger : public Logger {
public:
    void log(const std::string& message) override {
        std::ofstream logFile("log.txt", std::ios::app);

        if (logFile.is_open()) {
            logFile << message << std::endl;

            logFile.close();
        } else {
            std::cerr << "Не удалось открыть файл log.txt для записи." << std::endl;
        }
    }
};

class ConsoleLogger : public Logger {
public:
    void log(const std::string& message) override {
        std::cout << message << "\n";
    }
};

class LoggerFactory {
public:
    virtual Logger* createLogger() = 0;
};

class FileLoggerFactory : public LoggerFactory {
public:
    Logger* createLogger() override {
        return new FileLogger();
    }
};

class ConsoleLoggerFactory : public LoggerFactory {
public:
    Logger* createLogger() override {
        return new ConsoleLogger();
    }
};

LoggerFactory* factory1 = new FileLoggerFactory();
Logger* logger = factory1->createLogger();

ConsoleLoggerFactory* factory2 = new ConsoleLoggerFactory();
Logger* loggerC = factory2->createLogger();


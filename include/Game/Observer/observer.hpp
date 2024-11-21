#include <iostream>
#include <vector>
#include <memory>
#include <fstream>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const std::string& event) = 0;
};

class FileLogger : public Observer {
public:
    FileLogger(const std::string& filename);

    void update(const std::string& event) override;

private:
    std::string filename;
};

class ScreenLogger : public Observer {
public:
    void update(const std::string& event);
};
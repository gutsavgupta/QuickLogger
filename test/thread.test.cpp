#include <Clogger.h>

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

using Severity = typename clogger::Clogger::SeverityT;
std::string line;

void LogThread()
{
    uint64_t avgTime = 0;
    uint64_t count   = 0;
    auto&    logger  = clogger::Clogger::GetInstance().GetLogger();
    while (std::getline(std::cin, line))
    {
        auto time1 = std::chrono::high_resolution_clock::now();
        LOG(logger, Severity::DEBUG, "input[" << line << "]");
        // CLOG(Severity::DEBUG, "input[" << line << "]");

        auto time2 = std::chrono::high_resolution_clock::now();
        auto time3 = std::chrono::high_resolution_clock::now();

        auto timeDiff =
          std::chrono::duration_cast<std::chrono::nanoseconds>(time2 - time1);
        auto clockDiff =
          std::chrono::duration_cast<std::chrono::nanoseconds>(time3 - time2);

        avgTime += timeDiff.count();
        ++count;

        std::cout << "time for logging a message of len:" << line.length()
                  << " is ns:" << timeDiff.count()
                  << " and time for clock::now() ns:" << clockDiff.count()
                  << " avgTime:" << (1.0 * avgTime) / count << std::endl;
    }
    return;
}

void DumpThread()
{
    // clogger::Clogger::GetInstance().Run();
    return;
}

int main()
{
    std::thread logThread(LogThread);
    std::thread dumpThread(DumpThread);

    logThread.join();
    dumpThread.join();
    return 0;
}

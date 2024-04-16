#include "LogObserver.hpp"

using namespace observers;

LogObserver::LogObserver() :
    _os(std::ofstream("./lab6/logs/battle_logs.log"))
{
}

void LogObserver::report_killed(const NPC& attacker, const NPC& defender) {
    _os << defender << " | killed by | " << attacker << std::endl;
}
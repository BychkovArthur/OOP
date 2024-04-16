#pragma once

#include <fstream>
#include <memory>

#include "NPC.hpp"
#include "Elf.hpp"
#include "Outlaw.hpp"
#include "Squirrel.hpp"

extern std::mutex print_mutex, file_mutex;

namespace observers {

class LogObserver : public IObserver {
  private:
    std::ofstream _os;

  public:
    LogObserver();

    void report_killed(const std::shared_ptr<NPC>, const std::shared_ptr<NPC>) override;
};

}; // namespace observers
#pragma once

#include <fstream>

#include "NPC.hpp"
#include "Elf.hpp"
#include "Outlaw.hpp"
#include "Squirrel.hpp"
#include "ConsoleObserver.hpp"
#include "LogObserver.hpp"

class NPCFactory final {
  public:
    NPCFactory() = default;
    virtual ~NPCFactory() = default;

    std::shared_ptr<NPC> create_NPC(NPCType, const int64_t, const int64_t);

    void save(const set_t&, const std::string&);
    set_t load(const std::string&);
};
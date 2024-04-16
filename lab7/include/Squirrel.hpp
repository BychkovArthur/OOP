#pragma once

#include "NPC.hpp"
#include "Outlaw.hpp"
#include "Elf.hpp"

class Squirrel : public NPC {
  public:
    Squirrel(const int64_t, const int64_t);

    std::string get_type() override;
    int64_t get_damage_range() const override;

    void battle_cry() const override;

    bool accept(std::shared_ptr<NPC>) override;
    bool fight(std::shared_ptr<Outlaw>) override;
    bool fight(std::shared_ptr<Elf>) override;
    bool fight(std::shared_ptr<Squirrel>) override;

    void move(const int64_t, const int64_t) override;
};

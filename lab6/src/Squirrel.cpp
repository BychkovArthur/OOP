#include "Squirrel.hpp"

Squirrel::Squirrel(const int64_t __x, const int64_t __y) : 
    NPC(NPCType::Squirrel, "Squirrel_" + std::to_string(id++), __x, __y) 
{
}

std::string Squirrel::get_type() 
{
    return "Squirrel";
}

void Squirrel::battle_cry() const
{
    std::cout << "Barks!!!" << std::endl;
}

bool Squirrel::accept(std::shared_ptr<NPC> visitor) 
{
    if (visitor->fight(*this)) {
        this->_alive = false;
        return true;
    }

    return false;
}

bool Squirrel::fight(Outlaw& accepter) 
{
    return false;
}

bool Squirrel::fight(Elf& accepter) 
{
    notify_killed(accepter);
    return true;
}

bool Squirrel::fight(Squirrel& accepter) 
{
    return false;
}
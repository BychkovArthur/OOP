#include "Squirrel.hpp"

Squirrel::Squirrel(const int64_t __x, const int64_t __y) : 
    NPC(NPCType::Squirrel, "Squirrel_" + std::to_string(id++), __x, __y) 
{
}

std::string Squirrel::get_type() 
{
    return "Squirrel";
}

int64_t Squirrel::get_damage_range() const
{
    return 5;
}

void Squirrel::battle_cry() const
{
    std::cout << "Barks!!!" << std::endl;
}

bool Squirrel::accept(std::shared_ptr<NPC> visitor) 
{
    return visitor->fight(std::shared_ptr<Squirrel>(this, [](Squirrel*) {}));
}

bool Squirrel::fight(std::shared_ptr<Outlaw> accepter) 
{
    return false;
}

bool Squirrel::fight(std::shared_ptr<Elf> accepter) 
{
    if (this->get_energy() > accepter->get_energy()) {
        notify_killed(accepter);
        accepter->must_die();
    }
    return true;
}

bool Squirrel::fight(std::shared_ptr<Squirrel> accepter) 
{
    return false;
}

void Squirrel::move(const int64_t max_x, const int64_t max_y)
{
    std::lock_guard<std::shared_mutex> lck(_mutex);
    double angle = static_cast<double>(std::rand() % 100) / 100.0 * 2 * M_PI,
           dist = static_cast<double>(std::rand() % 100) / 100.0 * 5;

    int shift_x = static_cast<int>(dist * std::cos(angle)),
        shift_y = static_cast<int>(dist * std::sin(angle));

    if ((_x + shift_x >= 0) && (_x + shift_x <= max_x))
        _x += shift_x;
    if ((_y + shift_y >= 0) && (_y + shift_y <= max_y))
        _y += shift_y;
}
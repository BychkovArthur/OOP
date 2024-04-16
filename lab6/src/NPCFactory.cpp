#include "NPCFactory.hpp"

std::shared_ptr<NPC> NPCFactory::create_NPC(NPCType type, const int64_t x, const int64_t y) 
{
    std::shared_ptr<NPC> result;
    switch (type) {
    case NPCType::Elf :
        result = std::make_shared<Elf>(x, y);
        break;
    case NPCType::Outlaw :
        result = std::make_shared<Outlaw>(x, y);
        break;
    case NPCType::Squirrel :
        result = std::make_shared<Squirrel>(x, y);
        break;

    default:
        break;
    }

    return result;
}

void NPCFactory::save(const set_t& s, const std::string& file_name) {
    std::ofstream out(file_name);

    if (!out.is_open()) {
        throw std::invalid_argument("Не удалось открыть файл для записи");
    }

    out << s.size() << std::endl;
    for (auto& npc : s) {

        out << npc->get_type() << std::endl
            << npc->get_x() << std::endl
            << npc->get_y() << std::endl;
    }

    out.flush();
    out.close();
}

set_t NPCFactory::load(const std::string& file_name) {
    set_t result;
    std::ifstream in(file_name);
    std::shared_ptr<observers::IObserver> console_observer, file_observer;
    console_observer = std::make_shared<observers::ConsoleObserver>();
    file_observer = std::make_shared<observers::LogObserver>();

    if (in.good() && in.is_open()) {
        int count;
        in >> count;
        
        while (count--) {
            std::shared_ptr<NPC> npc;
            int64_t x, y;
            std::string type;

            in >> type;
            in >> x >> y;

            if (type == "Elf") {
                npc = std::make_shared<Elf>(x, y);
            } else if (type == "Outlaw") {
                npc = std::make_shared<Outlaw>(x, y);
            } else if (type == "Squirrel") {
                npc = std::make_shared<Squirrel>(x, y);
            }
            
            result.insert(npc);
            npc->attach(console_observer);
            npc->attach(file_observer);
        }
    }

    return result;
}
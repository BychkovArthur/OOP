#include <gtest/gtest.h>

#include "NPCFactory.hpp"
#include "Elf.hpp"
#include "Outlaw.hpp"
#include "Squirrel.hpp"
#include "ConsoleObserver.hpp"
#include "LogObserver.hpp"

TEST(NPCFactoryTest, Create_NPC) {
    NPCFactory factory;
    bool test = true;
    try {
        std::shared_ptr<NPC> Elf = factory.create_NPC(NPCType::Elf, 1, 2);
        std::shared_ptr<NPC> Outlaw = factory.create_NPC(NPCType::Outlaw, 3, 4);
        std::shared_ptr<NPC> Squirrel = factory.create_NPC(NPCType::Squirrel, 5, 6);
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

TEST(NPCFactoryTest, Save) {
    NPCFactory factory;
    set_t s;
    bool test = true;
    try {
        s.insert(factory.create_NPC(NPCType::Elf, 1, 2));
        s.insert(factory.create_NPC(NPCType::Outlaw, 3, 4));
        s.insert(factory.create_NPC(NPCType::Squirrel, 5, 6));
        factory.save(s, "./lab6/game_data/test.txt");
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

TEST(NPCFactoryTest, Load) {
    NPCFactory factory;
    set_t s;
    bool test = true;
    try {
        s = factory.load("./lab6/game_data/test.txt");
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

TEST(NPCTest, OutputOperator) {
    std::shared_ptr<NPC> npc = std::make_shared<Elf>(1, 2);
    std::stringstream expected_output;
    expected_output << "Elf_9 {x : 1, y : 2}";

    std::stringstream actual_output;
    actual_output << *npc.get();

    EXPECT_EQ(expected_output.str(), actual_output.str());
}

TEST(NPCTest, Getters) {
    NPCFactory factory;
    std::shared_ptr<NPC> Elf = factory.create_NPC(NPCType::Elf, 1, 2);
    std::shared_ptr<NPC> Outlaw = factory.create_NPC(NPCType::Outlaw, 3, 4);
    std::shared_ptr<NPC> Squirrel = factory.create_NPC(NPCType::Squirrel, 5, 6);

    EXPECT_EQ(Elf->get_type(), "Elf");
    EXPECT_EQ(Outlaw->get_type(), "Outlaw");
    EXPECT_EQ(Squirrel->get_type(), "Squirrel");

    EXPECT_TRUE(Elf->is_alive());
    EXPECT_TRUE(Outlaw->is_alive());
    EXPECT_TRUE(Squirrel->is_alive());

    EXPECT_EQ(Elf->get_x(), 1);
    EXPECT_EQ(Outlaw->get_x(), 3);
    EXPECT_EQ(Squirrel->get_x(), 5);
    EXPECT_EQ(Elf->get_y(), 2);
    EXPECT_EQ(Outlaw->get_y(), 4);
    EXPECT_EQ(Squirrel->get_y(), 6);
}

TEST(NPCTest, Near) {
    NPCFactory factory;
    std::shared_ptr<NPC> Elf = factory.create_NPC(NPCType::Elf, 1, 1);
    std::shared_ptr<NPC> Outlaw = factory.create_NPC(NPCType::Outlaw, 50, 1);
    std::shared_ptr<NPC> Squirrel = factory.create_NPC(NPCType::Squirrel, 100, 1);

    EXPECT_FALSE(Elf->near(Outlaw, 10));
    EXPECT_TRUE(Elf->near(Outlaw, 60));
    EXPECT_FALSE(Elf->near(Squirrel, 90));
    EXPECT_TRUE(Elf->near(Squirrel, 110));
}

TEST(NPCTest, Attach) {
    NPCFactory factory;
    std::shared_ptr<NPC> Elf = factory.create_NPC(NPCType::Elf, 1, 1);
    std::shared_ptr<observers::IObserver> console_observer, file_observer;
    console_observer = std::make_shared<observers::ConsoleObserver>();
    file_observer = std::make_shared<observers::LogObserver>();
    bool test = true;
    try {
        Elf->attach(console_observer);
        Elf->attach(file_observer);
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

TEST(ElfTest, ConstructorAndGetters) {
    Elf Elf(1, 2);
    EXPECT_EQ(Elf.get_x(), 1);
    EXPECT_EQ(Elf.get_y(), 2);
    EXPECT_TRUE(Elf.is_alive());
    EXPECT_EQ(Elf.get_type(), "Elf");
}

TEST(ElfTest, Visitors) {
    NPCFactory factory;
    std::shared_ptr<NPC> Elf = factory.create_NPC(NPCType::Elf, 1, 2);
    std::shared_ptr<NPC> Outlaw = factory.create_NPC(NPCType::Outlaw, 3, 4);
    std::shared_ptr<NPC> Squirrel = factory.create_NPC(NPCType::Squirrel, 5, 6);

    EXPECT_FALSE(Elf->accept(Elf));
    EXPECT_FALSE(Elf->accept(Outlaw));
    EXPECT_TRUE(Elf->accept(Squirrel));
    EXPECT_FALSE(Elf->is_alive());
}

TEST(OutlawTest, ConstructorAndGetters) {
    Outlaw Outlaw(1, 2);
    EXPECT_EQ(Outlaw.get_x(), 1);
    EXPECT_EQ(Outlaw.get_y(), 2);
    EXPECT_TRUE(Outlaw.is_alive());
    EXPECT_EQ(Outlaw.get_type(), "Outlaw");
}

TEST(OutlawTest, Visitors) {
    NPCFactory factory;
    std::shared_ptr<NPC> Elf = factory.create_NPC(NPCType::Elf, 1, 2);
    std::shared_ptr<NPC> Outlaw = factory.create_NPC(NPCType::Outlaw, 3, 4);
    std::shared_ptr<NPC> Squirrel = factory.create_NPC(NPCType::Squirrel, 5, 6);

    EXPECT_FALSE(Outlaw->accept(Outlaw));
    EXPECT_FALSE(Outlaw->accept(Squirrel));
    EXPECT_TRUE(Outlaw->is_alive());
    EXPECT_TRUE(Outlaw->accept(Elf));
    EXPECT_FALSE(Outlaw->is_alive());
}

TEST(SquirrelTest, ConstructorAndGetters) {
    Squirrel Squirrel(1, 2);
    EXPECT_EQ(Squirrel.get_x(), 1);
    EXPECT_EQ(Squirrel.get_y(), 2);
    EXPECT_TRUE(Squirrel.is_alive());
    EXPECT_EQ(Squirrel.get_type(), "Squirrel");
}

TEST(SquirrelTest, Visitors) {
    NPCFactory factory;
    std::shared_ptr<NPC> Elf = factory.create_NPC(NPCType::Elf, 1, 2);
    std::shared_ptr<NPC> Outlaw = factory.create_NPC(NPCType::Outlaw, 3, 4);
    std::shared_ptr<NPC> Squirrel = factory.create_NPC(NPCType::Squirrel, 5, 6);
    std::shared_ptr<NPC> Squirrel_ = factory.create_NPC(NPCType::Squirrel, 5, 6);

    EXPECT_FALSE(Squirrel->accept(Elf));
    EXPECT_TRUE(Squirrel->is_alive());
    EXPECT_TRUE(Squirrel->accept(Outlaw));
    EXPECT_FALSE(Squirrel->is_alive());
    EXPECT_FALSE(Squirrel_->accept(Squirrel));
    EXPECT_TRUE(Squirrel_->is_alive());
    remove("./lab6/game_data/battle_logs.txt");
    remove("./lab6/game_data/test.txt");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
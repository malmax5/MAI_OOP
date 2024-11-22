#include <gtest/gtest.h>
#include "../include/NPC/Enums/type_id_enum.hpp"
#include "../include/NPC/Factory/knight_factory.hpp"

TEST(KnightFactoryTest, CreateKnight) {
    KnightFactory factory;
    std::shared_ptr<NPC> knight = factory.CreateNPC(0, 0);

    ASSERT_NE(knight, nullptr);
    ASSERT_EQ(knight->GetTypeId(), KnightId);
}
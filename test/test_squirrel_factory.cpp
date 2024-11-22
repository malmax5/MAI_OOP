#include <gtest/gtest.h>
#include "../include/NPC/Enums/type_id_enum.hpp"
#include "../include/NPC/Factory/squirrel_factory.hpp"

TEST(SquirrelFactoryTest, CreateSquirrel) {
    SquirrelFactory factory;
    std::shared_ptr<NPC> squirrel = factory.CreateNPC(0, 0);

    ASSERT_NE(squirrel, nullptr);
    ASSERT_EQ(squirrel->GetTypeId(), SquirrelId);
}

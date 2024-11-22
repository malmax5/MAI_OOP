#include <gtest/gtest.h>
#include "../include/NPC/Enums/type_id_enum.hpp"
#include "../include/NPC/Factory/pegasus_factory.hpp"

TEST(PegasusFactoryTest, CreatePegasus) {
    PegasusFactory factory;
    std::shared_ptr<NPC> pegasus = factory.CreateNPC(0, 0);

    ASSERT_NE(pegasus, nullptr);
    ASSERT_EQ(pegasus->GetTypeId(), PegasusId);
}

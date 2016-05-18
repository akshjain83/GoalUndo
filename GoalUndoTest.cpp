/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"

using namespace std;
 
class GoalUndoTest : public ::testing::Test
{
	protected:
		GoalUndoTest(){}
		virtual ~GoalUndoTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(GoalUndoTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(GoalUndoTest, UndoEmptyGoal)
{
  GoalUndo setter;
  string emptY = "";
  setter.undoGoal();
  ASSERT_EQ(emptY, setter.getGoal());
}

TEST(GoalUndoTest, UndoEmptyOperation)
{
  GoalUndo setter;
  string emptY = "";
  setter.undoOperation();
  ASSERT_EQ(emptY, setter.getGoal());
}


TEST(GoalUndoTest, UndoEmptyOperationOverloaded)
{
  GoalUndo setter;
  string emptY = "";
  setter.undoOperation(emptY);
  ASSERT_EQ(emptY, setter.getGoal());
}

TEST(GoalUndoTest, GetEmptyGoal)
{
  GoalUndo setter;
  string emptY = "";
  ASSERT_EQ(emptY, setter.getGoal());
}


TEST(GoalUndoTest, GetEmptyOperatios)
{
  GoalUndo setter;
  string emptY = "";
  ASSERT_EQ(emptY, setter.getOperations());
}

TEST(GoalUndoTest, addEmptyOperation)
{
  GoalUndo setter;
  string emptY = "";
  setter.addOperation(emptY);
  ASSERT_EQ(emptY, setter.getGoal());
}

TEST(GoalUndoTest, addEmptyGoalEmptyOperation)
{
  GoalUndo setter;
  string emptY = "";
  setter.addOperation(emptY, emptY);
  ASSERT_EQ(emptY, setter.getGoal());

}


TEST(GoalUndoTest, addEmptyGoalNonEmptyOperation)
{
  GoalUndo setter;
  string emptY = "";
  string nonEmpty = "Will Not get added";
  setter.addOperation(emptY,nonEmpty);
  ASSERT_EQ(emptY, setter.getGoal());
}


TEST(GoalUndoTest, addNonEmptyGoalEmptyOperation)
{
  GoalUndo setter;
  string emptY = "";
  string nonEmpty = "Will Not get Added";
  setter.addOperation(nonEmpty, emptY);
  ASSERT_EQ(emptY, setter.getGoal());
}

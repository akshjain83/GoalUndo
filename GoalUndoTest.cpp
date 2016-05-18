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

TEST(GoalUndoTest, loopThroughGetVectors)
{
 GoalUndo setter;
 string goal = "This is first Goal";
 string oper = "This is first Operation";
 string oper2 = "This is second Operation";
 string oper3 = "This is third Operation";
 string result = oper + " " + oper2 + " " + oper3;
 setter.addOperation(goal, oper);
 setter.addOperation(oper2);
 setter.addOperation(oper3);
 ASSERT_EQ(result, setter.getOperations());
}


TEST(GoalUndoTest, loopThroughUndoVectors)
{
 GoalUndo setter;
 string goal = "This is first Goal";
 string oper = "This is first Operation";
 string oper2 = "This is second Operation";
 string oper3 = "This is third Operation";
 string result = oper + " " + oper2 + " " + oper3;
 setter.addOperation(goal, oper);
 setter.addOperation(oper2);
 setter.addOperation(oper3);
 setter.undoOperation(oper);
 setter.undoOperation(oper3);
 ASSERT_EQ(oper2, setter.getOperations());
}

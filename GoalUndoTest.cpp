/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"
 
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

TEST(GoalUndoTest, getEmptyGoal)
{
	GoalUndo gtest;
	ASSERT_EQ("", gtest.getGoal());
}

TEST(GoalUndoTest, undoEmptyGetOps)
{
	GoalUndo gtest;
   gtest.undoGoal();
   ASSERT_EQ("",gtest.getOperations());
}

TEST(GoalUndoTest, singleGoalOps)
{
	GoalUndo gtest;
   gtest.addOperation("This is Goal along Operation");
   ASSERT_EQ("This is Goal along Operation",gtest.getOperations());
   ASSERT_EQ("This is Goal along Operation",gtest.getGoal());
}

TEST(GoalUndoTest, singleGoalMultiOps)
{
	GoalUndo gtest;
   gtest.addOperation("Check Two Operations", "Operation 1");
   gtest.addOperation("Operation 2");
   ASSERT_EQ("Operation 1 Operation 2",gtest.getOperations());
   ASSERT_EQ("Check Two Operations",gtest.getGoal());
}


TEST(GoalUndoTest, getOpsAfterUndo)
{
	GoalUndo gtest;
   gtest.addOperation("Get Operation After Undo", "No Goal");
   gtest.undoGoal();
   ASSERT_EQ("",gtest.getOperations());
}



TEST(GoalUndoTest, multiGoalOps)
{
	GoalUndo gtest;
   gtest.addOperation("Goal 1", "G1 Task 1");
   gtest.addOperation("G1 Task 2");
   gtest.addOperation("Goal 2", "G2 Task 1");
   ASSERT_EQ("G2 Task 1",gtest.getOperations());
   gtest.undoGoal();
   ASSERT_EQ("Goal 1",gtest.getGoal());
}

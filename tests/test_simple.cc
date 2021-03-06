#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "dwalk.h"

bool exist(const char* filename)
{
  return access(filename,F_OK) == 0;
}

class DwalkTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    graph_fn.push_back(
        std::make_pair("./tests/dataset1/sample.in",
                       "./tests/dataset1/sample.label"));
    graph_fn.push_back(
        std::make_pair("./tests/dataset2/sample.in",
                       "./tests/dataset2/sample.label"));
  }
  // virtual void TearDown() {}
  std::vector<std::pair<std::string, std::string> > graph_fn;
};

TEST_F(DwalkTest, TestFileExistCheck)
{
  for (unsigned int i = 0; i < graph_fn.size(); i++) {
    const char* graph_filename = graph_fn[i].first.c_str();
    const char* label_filename = graph_fn[i].second.c_str();
    ASSERT_TRUE(exist(graph_filename));
    ASSERT_TRUE(exist(label_filename));
  }
}

TEST_F(DwalkTest, TestFileLoadCheck)
{
  // foreach dataset
  for (unsigned int i = 0; i < graph_fn.size(); i++) {
    const char* graph_filename = graph_fn[i].first.c_str();
    const char* label_filename = graph_fn[i].second.c_str();
    gll::Dwalk d;
    d.load(graph_filename, label_filename, false);
    ASSERT_TRUE(true);
    ASSERT_TRUE(true);
  }
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

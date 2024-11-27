#include <string>
#include "gtest/gtest.h"
#include "class.h"

using namespace std;

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


TEST(TestConstr, TestEmConst) {
	FlatMap value;
	EXPECT_EQ(value.sizez, 0);
	EXPECT_EQ(value.contains(""), 0);
	EXPECT_EQ(value.contains(" "), 0);
	EXPECT_EQ(value.contains("something"), 0);
}

TEST(TestConstr, TestEqConst) {
	FlatMap value1;
	value1["key"] = "value";
	FlatMap value2(value1);
	FlatMap value3(value1);
	int paramether = 0;
	if ((value1.sizez != value2.sizez) || (value2.sizez != value3.sizez))
		paramether = 1;
	else {
		size_t amount = value1.sizez;
		for (int i = 0; i < amount; i++) {
			if (((value1.map[i][0] == value2.map[i][0]) && (value1.map[i][1] == value2.map[i][1])) || ((value2.map[i][0] == value3.map[i][0]) && (value2.map[i][1] == value3.map[i][1])))
				paramether += 0;
			else
				paramether = 1;
		}
	}
	EXPECT_EQ(paramether, 0);
}

TEST(TestSize, TestSize) {
	FlatMap value;
	EXPECT_EQ(value.size(), 0);
	value["NSU"] = "NET";
	EXPECT_EQ(value.size(), 1);
	value["GROUP"] = "23207";
	value["OBSHAGA"] = "7";
	EXPECT_EQ(value.size(), 3);
	value.erase("GROUP");
	EXPECT_EQ(value.size(), 2);
	value.erase("");
	EXPECT_EQ(value.size(), 2);
	value.erase("OBSHAGA");
	value.erase("NSU");
	EXPECT_EQ(value.size(), 0);
}

TEST(TestOpEQ, TestOpEq) {
	FlatMap value1;
	FlatMap value2;
	FlatMap value3;
	value2["SEMESTR"] = "3";
	value2["COURSE"] = "2";
	value1 = value2;
	value3 = value1;
	EXPECT_EQ(value2.size(), value1.size());
	EXPECT_EQ(value3.size(), value2.size());
	size_t paramether = 0;
	if ((value1.size() != value2.size()) || (value2.size() != value3.size()))
		paramether = 1;
	else {	
		int amount = (int) value2.size();
		for (int i = 0; i < amount; i++) {
			if (((value1.map[i][0] == value2.map[i][0]) && (value1.map[i][1] == value2.map[i][1])) || ((value2.map[i][0] == value3.map[i][0]) && (value2.map[i][1] == value3.map[i][1])))
				paramether += 0;
			else
				paramether = 1;
		}
	}
	EXPECT_EQ(paramether, 0);
}

TEST(TestGetInsert, TestGetInsert) {
	FlatMap value;
	EXPECT_EQ(value.size(), 0);
	value["RYAN"] = "GOSLING";
	value["TYLER"] = "DURDEN";
	value["JOHN"] = "CENA";
	value["JASON"] = "STATTHEM";
	EXPECT_EQ(value.size(), 4);
	EXPECT_EQ((value["RYAN"] == "GOSLING"), 1);
	EXPECT_EQ((value["TYLER"] == "GOBLIN"), 0);
	EXPECT_EQ((value["JOHN"] == "CENA"), 1);
	EXPECT_EQ((value["JASON"] == "STATTHEM"), 1);
	value.erase("JASON");
	EXPECT_EQ((value["JASON"] == "STATTHEM"), 0);
}

TEST(TestContains, TestContains) {
	FlatMap value;
	EXPECT_EQ(value.contains(""), 0);
	EXPECT_EQ(value.contains(" "), 0);
	EXPECT_EQ(value.contains("SOMETHING"), 0);
	value["CITY"] = "NSK";
	value["RAYON"] = "AKADEM";
	value["UNIVERSITY"] = "NSU";
	EXPECT_EQ(value.contains("CITY"), 1);
	EXPECT_EQ(value.contains("UNIVERSITY"), 1);
	EXPECT_EQ(value.contains("RAYON"), 1);
	EXPECT_EQ(value.contains(""), 0);
	EXPECT_EQ(value.contains(" "), 0);
	EXPECT_EQ(value.contains("SOMETHING"), 0);
}

TEST(TestErase, TestErase) {
	FlatMap value;
	value["ich"] = "ni";
	value["san"] = "chi";
	value["go"] = "rock";
	value["sich"] = "hach";
	EXPECT_EQ(value.size(), 4);
	EXPECT_EQ(value.erase("ich"), 1);
	EXPECT_EQ(value.size(), 3);
	EXPECT_EQ(value.erase("nothing"), 0);
	EXPECT_EQ(value.erase("go"), 1);
	EXPECT_EQ(value.size(), 2);
	EXPECT_EQ(value.erase("sich"), 1);
	EXPECT_EQ(value.erase("san"), 1);
	EXPECT_EQ(value.size(), 0);
	EXPECT_EQ(value.erase("torrin"), 0);
}



TEST(TestClear, TestClearing) {
	FlatMap value1;
	FlatMap value2;
	value2["STREET"] = "PIROGOVA";
	value2["UNIVERSITY"] = "NSU";
	FlatMap value3 = value2;
	value1.clear();
	value2.clear();
	value3.clear();
	EXPECT_EQ(value1.sizez, 0);
	EXPECT_EQ(value2.sizez, 0);
	EXPECT_EQ(value3.sizez, 0);

	EXPECT_EQ(value1.contains(""), 0);
	EXPECT_EQ(value1.contains(" "), 0);
	EXPECT_EQ(value2.contains("STREET"), 0);
	EXPECT_EQ(value2.contains("UNIVERSITY"), 0);
	EXPECT_EQ(value2.contains("SOMETHING"), 0);
	EXPECT_EQ(value3.contains(""), 0);
	EXPECT_EQ(value3.contains("STREET"), 0);
	EXPECT_EQ(value3.contains("UNIVERSITY"), 0);
	EXPECT_EQ(value3.contains("SOMETHING"), 0);

}

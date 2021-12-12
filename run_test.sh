#!/bin/bash

V1_DIR='v1'
V2_DIR='v2'

V1_LOGFILE='v1.log'
V2_LOGFILE='v2.log'

BINARY='hotrace'

TEST_DIR='resources'

TEST_FILE1=$TEST_DIR/test01.htr
TEST_FILE2=$TEST_DIR/test02.htr
TEST_FILE3=$TEST_DIR/test03.htr
TEST_FILE4=$TEST_DIR/test04.htr
TEST_FILE5=$TEST_DIR/test05.htr
TEST_FILE6=$TEST_DIR/test06.htr
TEST_FILE7=$TEST_DIR/test07.htr
TEST_FILE8=$TEST_DIR/test08.htr

test_v1() {
	make $BINARY -C $V1_DIR

	time $V1_DIR/$BINARY < $TEST_FILE1 > /dev/null
	time $V1_DIR/$BINARY < $TEST_FILE2 > /dev/null
	time $V1_DIR/$BINARY < $TEST_FILE3 > /dev/null
	time $V1_DIR/$BINARY < $TEST_FILE4 > /dev/null
	time $V1_DIR/$BINARY < $TEST_FILE5 > /dev/null
	time $V1_DIR/$BINARY < $TEST_FILE6 > /dev/null
	time $V1_DIR/$BINARY < $TEST_FILE7 > /dev/null
	time $V1_DIR/$BINARY < $TEST_FILE8 > /dev/null
}

test_v2() {
	make $BINARY -C $V2_DIR

	time $V2_DIR/$BINARY < $TEST_FILE1 > /dev/null
	time $V2_DIR/$BINARY < $TEST_FILE2 > /dev/null
	time $V2_DIR/$BINARY < $TEST_FILE3 > /dev/null
	time $V2_DIR/$BINARY < $TEST_FILE4 > /dev/null
	time $V2_DIR/$BINARY < $TEST_FILE5 > /dev/null
	time $V2_DIR/$BINARY < $TEST_FILE6 > /dev/null
	time $V2_DIR/$BINARY < $TEST_FILE7 > /dev/null
	time $V2_DIR/$BINARY < $TEST_FILE8 > /dev/null
}

test_v1
test_v2

exit 0

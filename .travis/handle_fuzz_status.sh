NO_CRASHES=$(find test/make_build_debug/fuzz/${TEST_LIB}/ -iname "id*" | grep ".*/crashes/*" | wc -l)
exit $NO_CRASHES
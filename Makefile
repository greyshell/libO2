TEST_LIB=dumb_example
FUZZ_TIME=45s

PATHU = lib/Unity/src/
PATHS = src/
PATHT = test/

PATH_DEBUG = test/make_build_debug
PATH_FUZZ = test/make_build_debug/fuzz/$(TEST_LIB)

PATHB = test/make_build_debug/unittest_build/
PATHD = test/make_build_debug/unittest_build/depends/
PATHO = test/make_build_debug/unittest_build/objs/
PATHR = test/make_build_debug/unittest_build/results/


BUILD_PATHS = $(PATH_DEBUG) $(PATHB) $(PATHD) $(PATHO) $(PATHR) $(PATH_FUZZ)

SRCT = $(wildcard $(PATHT)*.c)

CLEANUP=rm -f
CLEANUP_DIR=rm -rf
MKDIR=mkdir -p
TARGET_EXTENSION=out

COMPILE=gcc -c
LINK=gcc
DEPEND=gcc -MM -MG -MF
CFLAGS=-I. -I$(PATHU) -I$(PATHS) -Dtest
COMPILE_AFL=AFL_USE_ASAN=1 afl-gcc

RESULTS = $(patsubst $(PATHT)test_%.c,$(PATHR)test_%.txt,$(SRCT) )

PASSED = `grep -s PASS $(PATHR)*.txt`
FAIL = `grep -s FAIL $(PATHR)*.txt`
IGNORE = `grep -s IGNORE $(PATHR)*.txt`


.PHONY: clean
.PHONY: test

test: $(BUILD_PATHS) $(RESULTS)
	@echo "-----------------------\nIGNORES:\n-----------------------"
	@echo "$(IGNORE)"
	@echo "-----------------------\nFAILURES:\n-----------------------"
	@echo "$(FAIL)"
	@echo "-----------------------\nPASSED:\n-----------------------"
	@echo "$(PASSED)"
	@echo "\nDONE"

fuzz-build: $(BUILD_PATHS)
	$(COMPILE_AFL) $(CFLAGS) $(PATHT)/fuzz_$(TEST_LIB).c $(PATHS)/*.c \
        -o $(PATH_FUZZ)/fuzz_$(TEST_LIB)

fuzz: fuzz-build
	timeout $(FUZZ_TIME) afl-fuzz -i $(PATH_FUZZ)/in -o $(PATH_FUZZ)/out \
		-m none $(PATH_FUZZ)/fuzz_dumb_example

cppcheck: $(BUILD_PATHS)
	cppcheck $(PATHS)*.c > $(PATH_DEBUG)/cppcheck_report.txt

cppcheck-report: cppcheck
	@echo "-----------------------\nCPPCHECK REPORT:\n-----------------------"
	@cat $(PATH_DEBUG)/cppcheck_report.txt

$(PATHR)%.txt: $(PATHB)%.$(TARGET_EXTENSION)
	-./$< > $@ 2>&1

$(PATHB)test_%.$(TARGET_EXTENSION): $(PATHO)test_%.o $(PATHO)%.o $(PATHU)unity.o
	$(LINK) -o $@ $^

$(PATHO)%.o:: $(PATHT)%.c
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATHO)%.o:: $(PATHS)%.c
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATHO)%.o:: $(PATHU)%.c $(PATHU)%.h
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATHD)%.d:: $(PATHT)%.c
	$(DEPEND) $@ $<

$(PATH_DEBUG):
	$(MKDIR) $(PATH_DEBUG)

$(PATHB):
	$(MKDIR) $(PATHB)

$(PATHD):
	$(MKDIR) $(PATHD)

$(PATHO):
	$(MKDIR) $(PATHO)

$(PATHR):
	$(MKDIR) $(PATHR)

$(PATH_FUZZ):
	@$(MKDIR) $(PATH_FUZZ)
	@$(MKDIR) $(PATH_FUZZ)/in/
	@echo abc > $(PATH_FUZZ)/in/t1

clean:
	$(CLEANUP) $(PATHO)*.o
	$(CLEANUP) $(PATHB)*.$(TARGET_EXTENSION)
	$(CLEANUP) $(PATHR)*.txt
	$(CLEANUP_DIR) $(PATH_FUZZ)
	$(CLEANUP) $(PATH_DEBUG)/cppcheck_report.txt

.PRECIOUS: $(PATHB)test_%.$(TARGET_EXTENSION)
.PRECIOUS: $(PATHD)%.d
.PRECIOUS: $(PATHO)%.o
.PRECIOUS: $(PATHR)%.txt

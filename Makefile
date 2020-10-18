TEST_LIB=dumb_example
FUZZ_TIME=10s

PATHU = lib/Unity/src/
PATHS = src/
PATHT = test/
DEBUG_ROOT = $(PATHT)/debug/

PATH_DEBUG = $(DEBUG_ROOT)$(TEST_LIB)/
PATH_FUZZ = $(PATH_DEBUG)/fuzz_build/
PATHB = $(PATH_DEBUG)/unittest_build/
PATHD = $(PATHB)/depends/
PATHO = $(PATHB)/objs/
PATHR = $(PATHB)/results/


BUILD_PATHS = $(DEBUG_ROOT) $(PATH_DEBUG) $(PATHB) $(PATHD) $(PATHO) $(PATHR) $(PATH_FUZZ)

SRCT = $(wildcard $(PATHT)/$(TEST_LIB).c)

CLEANUP=rm -f
CLEANUP_DIR=rm -rf
MKDIR=mkdir -p
TARGET_EXTENSION=out

COMPILE=gcc -c
LINK=gcc
DEPEND=gcc -MM -MG -MF
CFLAGS=-I. -I$(PATHU) -I$(PATHS) -Dtest
COMPILE_AFL=AFL_USE_ASAN=1 afl-gcc

RESULTS = $(PATHR)test_$(TEST_LIB).txt

PASSED = `grep -s PASS $(PATHR)*.txt`
FAIL = `grep -s FAIL $(PATHR)*.txt`
IGNORE = `grep -s IGNORE $(PATHR)*.txt`


.PHONY: clean
.PHONY: test

test-all: cppcheck test fuzz

test: $(BUILD_PATHS) $(RESULTS)
	@echo "-----------------------\nIGNORES:\n-----------------------"
	@echo "$(IGNORE)"
	@echo "-----------------------\nFAILURES:\n-----------------------"
	@echo "$(FAIL)"
	@echo "-----------------------\nPASSED:\n-----------------------"
	@echo "$(PASSED)"
	@echo "\nDONE"

fuzz-build: $(BUILD_PATHS)
	$(COMPILE_AFL) $(CFLAGS) $(PATHT)/fuzz_$(TEST_LIB).c $(PATHS)/$(TEST_LIB).c \
        -o $(PATH_FUZZ)/fuzz_$(TEST_LIB)

fuzz: fuzz-build
	timeout $(FUZZ_TIME) afl-fuzz -i $(PATH_FUZZ)/in -o $(PATH_FUZZ)/out \
		-m none $(PATH_FUZZ)/fuzz_$(TEST_LIB)

cppcheck: $(BUILD_PATHS)
	cppcheck $(PATHS)/$(TEST_LIB).c > $(PATH_DEBUG)/cppcheck_report_$(TEST_LIB).txt

cppcheck-report: cppcheck
	@echo "-----------------------\nCPPCHECK REPORT:\n-----------------------"
	@cat $(PATH_DEBUG)/cppcheck_report_$(TEST_LIB).txt

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

$(DEBUG_ROOT):
	$(MKDIR) $(DEBUG_ROOT)

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
	$(CLEANUP_DIR) $(PATH_DEBUG)

clean-all:
	$(CLEANUP_DIR) $(DEBUG_ROOT)

.PRECIOUS: $(PATHB)test_%.$(TARGET_EXTENSION)
.PRECIOUS: $(PATHD)%.d
.PRECIOUS: $(PATHO)%.o
.PRECIOUS: $(PATHR)%.txt
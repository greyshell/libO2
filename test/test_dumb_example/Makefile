CLEANUP = rm -f
CLEANUPDIR = rm -rf
MKDIR = mkdir -p
TARGET_EXTENSION=out

.PHONY: clean
.PHONY: test

PATHU = ../../lib/Unity/src/
PATHS = ../../src/
PATHT = test/
PATHF = fuzz/
PATHB = build/
PATHD = build/depends/
PATHO = build/objs/
PATHR = build/results/
PATHFUZZ = build/fuzz/

BUILD_PATHS = $(PATHB) $(PATHD) $(PATHO) $(PATHR)

SRCT = $(wildcard $(PATHT)*.c)

COMPILE=gcc -c
LINK=gcc
DEPEND=gcc -MM -MG -MF
CFLAGS=-I. -I$(PATHU) -I$(PATHS) -Dtest
COMPILE_AFL=AFL_USE_ASAN=1 afl-gcc

RESULTS = $(patsubst $(PATHT)test_%.c,$(PATHR)test_%.txt,$(SRCT) )

PASSED = `grep -s PASS $(PATHR)*.txt`
FAIL = `grep -s FAIL $(PATHR)*.txt`
IGNORE = `grep -s IGNORE $(PATHR)*.txt`

test: $(BUILD_PATHS) $(RESULTS)
	@echo "-----------------------\nIGNORES:\n-----------------------"
	@echo "$(IGNORE)"
	@echo "-----------------------\nFAILURES:\n-----------------------"
	@echo "$(FAIL)"
	@echo "-----------------------\nPASSED:\n-----------------------"
	@echo "$(PASSED)"
	@echo "\nDONE"

fuzz-build:
	$(COMPILE_AFL) $(CFLAGS) fuzz/fuzz_dumb_example.c $(PATHS)/dumb_example.c \
		-o $(PATHFUZZ)/fuzz_dumb_example

fuzz: $(PATHFUZZ) fuzz-build
	afl-fuzz -i $(PATHFUZZ)/in -o $(PATHFUZZ)/out -m none $(PATHFUZZ)/fuzz_dumb_example

cppcheck: $(BUILD_PATHS)
	cppcheck $(PATHS)/dumb_example.c > $(PATHR)/cppcheck_results.txt

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

$(PATHB):
	$(MKDIR) $(PATHB)

$(PATHD):
	$(MKDIR) $(PATHD)

$(PATHO):
	$(MKDIR) $(PATHO)

$(PATHR):
	$(MKDIR) $(PATHR)

$(PATHFUZZ):
	$(MKDIR) $(PATHFUZZ)
	$(MKDIR) $(PATHFUZZ)/in/
	echo abc > $(PATHFUZZ)/in/t1

clean:
	$(COMPILE) $(PATHO)*.o
	$(CLEANUP) $(PATHB)*.$(TARGET_EXTENSION)
	$(CLEANUP) $(PATHR)*.txt

.PRECIOUS: $(PATHB)test_%.$(TARGET_EXTENSION)
.PRECIOUS: $(PATHD)%.d
.PRECIOUS: $(PATHO)%.o
.PRECIOUS: $(PATHR)%.txt

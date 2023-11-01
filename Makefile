CC = gcc
CFLAGS = -Wall -Werror -std=c17

# MAIN FILE
MAIN_SRC = src/main.c
MAIN_OBJ = $(MAIN_SRC:.c=.o)
MAIN_OUT = bin/main

# ALL FILE
ALL_SRC = $(wildcard lib/*/*.c) $(wildcard src/app/*/*.c) src/db.c
ALL_OBJ = $(ALL_SRC:.c=.o)

.PHONY: all clean run build compile test recompile %.test %.ADTrun %.run test %.ADTtest %.test %.result %/driver

all: build run

run: 
	$(MAIN_OUT)

build: $(MAIN_OUT)

clean: 
	rm -f $(MAIN_OBJ) $(ALL_OBJ)

recompile: clean all

lib/%/test/driver: $(ALL_OBJ) lib/%/test/driver.o 
	$(CC) $(CFLAGS) -o $@ $^

src/app/%/test/driver: $(ALL_OBJ) src/app/%/test/driver.o
	$(CC) $(CFLAGS) -o $@ $^

%.ADTrun: lib/%/test/driver
	lib/$*/test/driver
	
%.run: src/app/%/test/driver
	src/app/$*/test/driver

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(MAIN_OUT): $(ALL_OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# UNIT TEST FOR MAIN
TEST_DIR = test
TEST_CASES = $(wildcard $(TEST_DIR)/*.in)
TEST_OUTPUTS = $(TEST_CASES:.in=.out)
TEST_RESULTS = $(TEST_CASES:.in=.result)

$(TEST_RESULTS): $(TEST_DIR)/%.result: $(TEST_DIR)/%.in $(TEST_DIR)/%.out $(MAIN_OUT) build
	@if ./bin/main < $< | diff -Z -B - $(word 2, $^) > /dev/null; then \
		echo "$< $(word 2, $^): TRUE"; \
	else \
		echo "$< $(word 2, $^): WRONG";\
	fi > $@

test: build $(TEST_RESULTS)
	@cat $(TEST_RESULTS)

.SECONDEXPANSION:

# RULE FOR RESULT
HOHO = $(shell echo $1| tr ' ' '/')
HIHI = $(call HOHO, $(wordlist 1,$(shell expr $(words $1) - 1),$1))
HEHE = $(call HIHI, $(subst /, ,$1))

# UNIT TEST FOR ADT
TEST_ADT_DIR = lib/$1/test
TEST_ADT_CASES = $(wildcard $(call TEST_ADT_DIR,$1)/*.in)
TEST_ADT_RESULTS = $(patsubst %.in,%.result, $(call TEST_ADT_CASES,$1))

%.ADTtest: $$(call TEST_ADT_RESULTS,$$*) lib/%/test/driver 
	@cat $(call TEST_ADT_RESULTS,$*)

# UNIT TEST FOR APP
TEST_APP_DIR = src/app/$1/test
TEST_APP_CASES = $(wildcard $(call TEST_APP_DIR,$1)/*.in)
TEST_APP_RESULTS = $(patsubst %.in,%.result, $(call TEST_APP_CASES,$1))

%.test: src/app/%/test/driver $$(call TEST_APP_RESULTS,$$*) 
	@cat $(call TEST_APP_RESULTS,$*)

# HANDLE RESULT	
%.result: %.in %.out $$(call HEHE,$$*)/driver
	@if ./$(call HEHE,$*)/driver < $< | diff -Z -B - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@
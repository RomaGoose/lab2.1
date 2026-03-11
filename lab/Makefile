.PHONY: debug release run-debug run-release clean-debug clean-release debug-check

MAKEFLAGS += --no-print-directory

DBG_DIR = build_debug
RLS_DIR = build_release

PROJECT_NAME = lab

ifeq ($(OS),Windows_NT)
EXE_PATH = \$(PROJECT_NAME).exe
GEN = MinGW Makefiles
DBG_CHECK = if not exist $(DBG_DIR) cmake -G "$(GEN)" -DCMAKE_BUILD_TYPE=Debug -S . -B $(DBG_DIR)
RLS_CHECK = if not exist $(RLS_DIR) cmake -G "$(GEN)" -DCMAKE_BUILD_TYPE=Release -S . -B $(RLS_DIR)
else
EXE_PATH = /$(PROJECT_NAME)
GEN = Unix Makefiles
DBG_CHECK = if [ ! -d $(DBG_DIR) ]; then cmake -G "$(GEN)" -DCMAKE_BUILD_TYPE=Debug -S . -B $(DBG_DIR); fi
RLS_CHECK = if [ ! -d $(RLS_DIR) ]; then cmake -G "$(GEN)" -DCMAKE_BUILD_TYPE=Release -S . -B $(RLS_DIR); fi
endif

debug-check:
	@$(DBG_CHECK)

debug:
	@$(DBG_CHECK)
	cmake --build $(DBG_DIR)

release:
	@$(RLS_CHECK)
	cmake --build $(RLS_DIR)

run-debug: debug
	$(DBG_DIR)$(EXE_PATH)

run-release: release
	$(RLS_DIR)$(EXE_PATH)

clean-debug: 
	cmake --build $(DBG_DIR) --target clean

clean-release: 
	cmake --build $(RLS_DIR) --target clean
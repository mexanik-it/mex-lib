SRCDIR  := source
INCDIR  := include
LIBDIR  := lib
BINDIR  := bin

LIB_NAME := mex-lib

CXX     := g++
CXXFLAGS:= -Wall -Wextra -std=c++17 -I$(INCDIR) -MMD -MP

SRCS    := $(wildcard $(SRCDIR)/*.cpp)
OBJS    := $(SRCS:$(SRCDIR)/%.cpp=$(BINDIR)/%.o)
DEPS    := $(OBJS:.o=.d)

LIBDIR_WIN  := $(subst /,\,$(LIBDIR))
BINDIR_WIN  := $(subst /,\,$(BINDIR))

LIB_FILE_A_UNIX := $(LIBDIR)/lib$(LIB_NAME).a
LIB_FILE_WIN   := $(LIBDIR_WIN)\$(LIB_NAME).lib

.PHONY: all clean rebuild

all:
	@cls
	@echo [[94mBUILD STARTED[0m]
	@$(MAKE) $(LIB_FILE_WIN)
	@echo.
	@echo [[92mSUCCESS[0m] Library created: $(LIB_FILE_WIN) ($(words $(SRCS)) files compiled)
	@echo.
	@pause

$(LIB_FILE_WIN): $(OBJS) | $(LIBDIR)
	@if not exist "$(LIBDIR_WIN)" mkdir "$(LIBDIR_WIN)"
	@ar rcs "$(LIB_FILE_A_UNIX)" $(OBJS)
	@move /Y "$(LIBDIR_WIN)\lib$(LIB_NAME).a" "$(LIB_FILE_WIN)" >nul

# ГЛАВНОЕ ИЗМЕНЕНИЕ ЗДЕСЬ:
# @echo показывает имя файла (человек видит)
# @$(CXX) ... компилирует, но сама команда g++ НЕ показывается в консоли
$(BINDIR)/%.o: $(SRCDIR)/%.cpp | $(BINDIR)
	@if not exist "$(BINDIR_WIN)" mkdir "$(BINDIR_WIN)"
	@echo Compiling: $<
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(BINDIR):
	mkdir $(BINDIR)

$(LIBDIR):
	mkdir $(LIBDIR)

clean:
	del /Q $(BINDIR_WIN)\*.o 2>nul
	del /Q $(BINDIR_WIN)\*.d 2>nul
	del /Q $(LIBDIR_WIN)\*.a 2>nul
	del /Q $(LIBDIR_WIN)\*.lib 2>nul
	@echo [[93m:: Clean done.[0m]

rebuild: clean
	@cls
	@echo [[94mBUILD STARTED (REBUILD)[0m]
	@$(MAKE) all

-include $(DEPS)
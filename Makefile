CXX = g++
FLAGS = -Wall -Wextra -Wshadow -Wrestrict

EXEC = mwparse

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
DEPENDS = $(OBJECTS:.o=.d)

OBJDEST = obj
DEPDEST = dep

.PHONY: release debug

release: FLAGS += -DNDEBUG -O2
release: $(EXEC)

debug: FLAGS += -g
debug: $(EXEC)

$(EXEC): $(OBJDEST) $(DEPDEST)
$(EXEC): $(OBJDEST)/$(OBJECTS)
	$(CXX) $(FLAGS) $(filter %.o,$^) -o $@

$(OBJDEST):
	mkdir -p $@

$(DEPDEST):
	mkdir -p $@

-include $(DEPDEST)/$(DEPENDS)

$(OBJDEST)/%.o: %.cpp
	$(CXX) $(FLAGS) -MMD -MF $(patsubst $(OBJDEST)/%.o,$(DEPDEST)/%.d,$@) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(EXEC) $(OBJDEST)/$(OBJECTS) $(DEPDEST)/$(DEPENDS)


CXX = g++
FLAGS = -Wall -Wextra -Wshadow -Wrestrict # CHANGE (if needed)

EXEC = a.out # CHANGE

################################################################

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
DEPENDS = $(OBJECTS:.o=.d)

OBJDEST = obj
DEPDEST = dep

################################################################

.PHONY: release debug

release: FLAGS += -DNDEBUG -O2 # CHANGE (if needed)
release: $(EXEC)

debug: FLAGS += -g # CHANGE (if needed)
debug: $(EXEC)

################################################################

# Include the obj and dep directories as dependencies so they're
# built first time around
$(EXEC): $(OBJDEST) $(DEPDEST)

# Filter is needed to removed the directories from the list
# of files to be built
$(EXEC): $(OBJDEST)/$(OBJECTS)
	$(CXX) $(FLAGS) $(filter %.o,$^) -o $@

################################################################

$(OBJDEST):
	mkdir -p $@

$(DEPDEST):
	mkdir -p $@

################################################################

# This automatically includes the generated dependency file for
# each source file
-include $(DEPDEST)/$(DEPENDS)

################################################################

# The -MF option specifies the name of each dependency file
# that gcc automatically creates for each object file
$(OBJDEST)/%.o: %.cpp
	$(CXX) $(FLAGS) -MMD -MF \
	$(patsubst $(OBJDEST)/%.o,$(DEPDEST)/%.d,$@) -c $< -o $@

################################################################

.PHONY: clean

clean:
	rm -f $(EXEC) $(OBJDEST)/$(OBJECTS) $(DEPDEST)/$(DEPENDS)

obj_files = \
    GenericDataStructure.o \
    $(NULL)

.PHONY: all
all: $(obj_files)

%.o: %.cpp %.h
	$(COMPILE.cpp) -o $@ $<

%.o: %.cpp
	$(COMPILE.cpp) -o $@ $<

hello: hello.o $(obj_files)
	$(CXX) -o $@ $^ $(LIBS)


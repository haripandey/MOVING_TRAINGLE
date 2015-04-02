  # the compiler: gcc for C program, define as g++ for C++
  CC = g++

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -lGL, -lGLU and -lglut are flags for Opengl library
  CFLAGS  = -g -lGL -lGLU -lglut
  # the build target executable:
  TARGET = triangle

  all: $(TARGET)

  $(TARGET): $(TARGET).cpp;$(CC) $(TARGET).cpp $(CFLAGS) -o $(TARGET) ;

  clean:;$(RM) $(TARGET)

# Makefile in src/ directory

# Java compiler and runner
JAVAC = javac
JAVA = java

# Main class name
MAIN = SpellChecker

# Java source files in current (src/) directory
SOURCES = *.java

# Default target: build and run
all: build run

# Compile Java source files
build:
	$(JAVAC) $(SOURCES)

# Run the main class
run:
	$(JAVA) $(MAIN)

# Clean up compiled class files
clean:
	rm -f *.class
